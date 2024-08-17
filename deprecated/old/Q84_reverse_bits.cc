// Write a program that takes a 64-bit word and returns the 64-bit word
// consisting of the bits of the input word in reverse order. For example,
// if the input is alternating 1s and 0s, i.e., (1010...10), the output should
// be alternating 0s and 1s, i.e., (0101...01).

#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution #1
//   [0~31]-th bit들을 [63~32]-th bit들과 swap한다.
//
// Time Complexity: O(N), N is # of bits.
//
// Space Complexity: O(1)

inline long SwapBits(long num, int i, int j) {
  if (((num >> i) & 1) != ((num >> j) & 1)) {
    num ^= (1UL << i) | (1UL << j);
  }
  return num;
}

long ReverseBits(long num) {
  for (int i = 0; i <= 31; ++i) {
    num = SwapBits(num, i, 63 - i);
  }
  return num;
}

// Solution #2
//   * 16-bit integer들에 대한 reverse를 미리 구해둔 후 table에 저장해둔다.
//     16-bit integer들이 search key가 된다.
//   * 64-bit integer를 4개의 16-bit 구간, [x3, x2, x1, x0]로 쪼갠다.
//   * [rev(x0), rev(x1), rev(x2), rev(x3)]를 반환한다.
//
// Time Complexity: O(N/L), N is # of bits, L is # of bits in a key.
//
// Space Complexity: 2B * 2^16 = 2^7KB = 128KB 의 추가 공간이 발생한다.

// Note
// 16-bit integer를 reverse한 결과를 long으로 저장한다.
// ReverseBits2()에서 shift 연산을 수행하기 위해서다.
long precomputed_reverse[1 << 16];

uint16_t ReverseUint16(uint16_t num) {
  for (int i = 0; i <= 7; ++i) {
    num = SwapBits(num, i, 15 - i);
  }
  return num;
}

void PrecomputeReverse() {
  // Note
  // 변수 i와 상수 kNumReverse의 타입이 integer임에 유의한다.
  // 만약 uint16_t 타입이면 정상적으로 동작하지 않을 수 있다.
  // 예를 들면 infinite loop가 발생한다.
  for (int i = 0; i < (1 << 16); ++i) {
    precomputed_reverse[i] = ReverseUint16(i);
  }
}

long ReverseBits2(long num) {
  return precomputed_reverse[num & 0xffff] << 48 |
         precomputed_reverse[(num >> 16) & 0xffff] << 32 |
         precomputed_reverse[(num >> 32) & 0xffff] << 16 |
         precomputed_reverse[(num >> 48) & 0xffff];
}

int main() {
  PrecomputeReverse();
{
  // Test #1.
  // num = 1, return value = numeric_limits<long>::min()
  cout << ReverseBits(1) << " " << ReverseBits2(1) << endl;
}
{
  // Test #2.
  // num = numeric_limits<long>::min(), return value = 1
  long num = numeric_limits<long>::min();
  cout << ReverseBits(num) << " " << ReverseBits2(num) << endl;
}
{
  // Test #3.
  for (int i = 0; i < 1024; ++i) {
    if (ReverseBits(i) != ReverseBits2(i)) {
      cout << "Wrong answer: reverse of " << i << endl;
    }
  }
}
  return 0;
}
