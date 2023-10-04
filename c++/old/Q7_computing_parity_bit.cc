// The parity of a binary word is 1 if the number of 1s in the word is odd;
// otherwise, it is 0. For example, the parity of 1011 is 1, and the parity of
// 10001000 is 0. Parity checks are used to detect single bit errors in data
// storage and communication. It is fairly straightforward to write code that
// computes the parity of a single 64-bit word.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(auto start, auto end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int kWordSize = 16;

class ParityChecker {
 public:
  ParityChecker():
      subword_len_(kWordSize),
      parity_table_(1 << kWordSize) {
    MakeParityTable();
  }

  // Solution #1: Brute-force method
  int GetParityBit1(long num) {
#if 0
    int result = 0;
    while (num) {
      result += (num & 0x1);
      num >>= 1;
    }
    return result & 0x1;
#else
    // This code is more faster than the previous code.
    int result = 0;
    while (num) {
      result ^= 1;
      num &= (num - 1);
    }
    return result;
#endif
  }

  // Solution #2: Pre-calculation of parity bits
  int GetParityBit2(long num) {
    int bit_mask = 0xffff;
    int result = parity_table_[num >> (kWordSize * 3)] ^
                 parity_table_[(num >> (kWordSize * 2)) & bit_mask] ^
                 parity_table_[(num >> (kWordSize)) & bit_mask] ^
                 parity_table_[(num & bit_mask)];
    return result;
  }

  // Solution #3: Log-time parity bit calculation
  int GetParityBit3(long num) {
    num ^= (num >> 32);
    num ^= (num >> 16);
    num ^= (num >> 8);
    num ^= (num >> 4);
    num ^= (num >> 2);
    num ^= (num >> 1);
    return (num & 0x1);
  }

 private:
  void MakeParityTable() {
    for (int i = 0; i < parity_table_.size(); ++i) {
      parity_table_[i] = GetParityBit3(i);
    }
  }

  vector<int> parity_table_;
  int subword_len_;
};

int main() {
{
  // Test #1. Compare results of all solutions.
  ParityChecker pc;
  for (int i = 0; i < (1 << kWordSize); ++i) {
    int result_1 = pc.GetParityBit1(i);
    int result_2 = pc.GetParityBit2(i);
    int result_3 = pc.GetParityBit3(i);

    if (result_1 != result_2 || result_1 != result_3) {
      cerr << "wrong answer." << endl;
      printf("result_1: %d's parity is %d\n", i, result_1);
      printf("result_2: %d's parity is %d\n", i, result_2);
      printf("result_3: %d's parity is %d\n", i, result_3);
      exit(1);
    }
  }
}
{
  // Test #2. Get elapsed time of each solution.
  ParityChecker pc;
  auto start = GetTime();
  for (int i = 0; i < (1L << 20); ++i) {
    long num = rand() % numeric_limits<long>::max();
    int result_1 = pc.GetParityBit1(num);
  }
  auto end = GetTime();
  auto duration = GetElapsedTime(start, end);
  cout << "Elapsed time of solution #1: " << duration << endl;

  start = GetTime();
  for (int i = 0; i < (1L << 20); ++i) {
    long num = rand() % numeric_limits<long>::max();
    int result_2 = pc.GetParityBit2(num);
  }
  end = GetTime();
  duration = GetElapsedTime(start, end);
  cout << "Elapsed time of solution #2: " << duration << endl;

  start = GetTime();
  for (int i = 0; i < (1L << 20); ++i) {
    long num = rand() % numeric_limits<long>::max();
    int result_3 = pc.GetParityBit3(num);
  }
  end = GetTime();
  duration = GetElapsedTime(start, end);
  cout << "Elapsed time of solution #3: " << duration << endl;
}
  return 0;
}
