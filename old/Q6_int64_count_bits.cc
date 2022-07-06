// Problem Statement
//  Given a 64bit signed integer number, count the # of set bits
//  in the time complexity of O(1).

#include <iostream>
#include <limits>

using namespace std;

// Clue
//  O(1)의 time complexity에 문제를 푸는 방법에는 hashing이 있다.
//  64bit 정수들의 set bit을 미리 세어두면 어떨까?
//
// Solution
//  64bit 정수들 각각에 대하여 미리 set bit의 개수를 세어서,
//  정수의 값에 해당하는 array location에 set bit의 개수를 저장한다.
//  그리고 정수가 주어지면 해당 array location에서 set bit의 개수를 읽는다.
//  음수가 주어져도 양수로 간주하여 set bit을 세어도 무방하다.
//  sign bit도 하나의 set bit이기 때문이다.
//
//  문제는 64bit 정수들의 개수는 총 '2^64-1'개나 되기때문에
//  set bit의 개수를 미리 세는데 매우 오랜 시간이 걸리고,
//  array의 크기도 너무 커져서 main memory를 매우 많이 소비하게 된다.
//
//  그렇다면 미리 구해두는 정수들의 개수를 줄여야 한다.
//  64bit 정수들 대신 16bit 정수들에 대해서 set bit을 미리 계산해두고,
//  64bit 정수가 주어지면 16bit씩 쪼개어서 총 네 번 hashing한다.
//  네 번 hashing한 결과를 더하면 주어진 64bit 정수에 대한 set bit의 개수를
//  얻을 수 있다.
//
//  16bit 정수들의 개수는 총 '2^16-1'개로 약64000개다. 이 정도의 개수면
//  충분히 빠르게 set bit을 계산할 수 있고, array의 크기도 1M 미만이 되어
//  main memory를 적게 사용한다.

class BitCounter {
 public:
  BitCounter() {
    MakeBitCntTable();
  }

  ~BitCounter() = default;

  // Time complexity O(1)에 set bit의 개수를 구한다.
  int GetNumBits(int64_t num);

  // Time complexity O(s) (s = # of set bits)에 set bit의 개수를 구한다.
  int CountSetBits(int64_t num);

 private:
  // 16bit 정수에 대한 set bit의 개수를 구하여 저장해둔다.
  void MakeBitCntTable();

  // Set bit의 개수를 저장한 array.
  int bitCntTable[1 << 16];
};

void BitCounter::MakeBitCntTable() {
  // 0x0000 ~ 0xffff까지의 set bit의 개수를 구해서 저장한다.
  int table_size = 1 << 16;
  for (int i = 0; i < table_size; ++i) {
    bitCntTable[i] = CountSetBits(i);
  }
}

int BitCounter::CountSetBits(int64_t num) {
  int count = 0;
  while (num) {
    ++count;
    num &= (num - 1);
  }
  return count;
}

int BitCounter::GetNumBits(int64_t num) {
  int count = 0;
  // 반드시 num을 uint64_t 타입으로 casting한다.
  // 그렇지 않으면 num이 음수일 때 while loop이 영원히 끝나지 않는다.
  // '>>' 연산(arithmetic right shift)이 문제인데,
  // 음수에 arithmetic right shift를 하면 MSB가 항상 set bit이므로
  // num은 영원히 0이 되지 않고 while loop은 끝나지 않는다.
  uint64_t x = static_cast<uint64_t>(num);
  uint64_t mask = (1UL << 16) - 1;
  while (x) {
    count += bitCntTable[x & mask];
    x >>= 16;
  }
  return count;
}

int main() {
  BitCounter bc;
  for (int64_t i = -10000; i <= 10000; ++i) {
    int my_ans = bc.GetNumBits(i);
    int ans = bc.CountSetBits(i);
    printf("# of bits in %ld: %d(%d)\n", i, my_ans, ans);
  }
  return 0;
}
