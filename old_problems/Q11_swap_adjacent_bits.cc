// Implement code that swaps the two adjacent bits at indices i and i + 1.
// Assume that LSB is the 0-th bit.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

long SwapAdjacentBits(long num, int i) {
  long bits = (num >> i) & 3;
  if (bits == 1 || bits == 2) {
    num ^= (3UL << i);
  }
  return num;
}

int main() {
  // Test #1
  // num = 00...01, i = 0
  // return value = 00...10
  long result = SwapAdjacentBits(1, 0);
  if (result != 2) {
    cerr << "Test #1: Wrong answer." << endl;
  }

  // Test #2
  // num = 00..100, i = 1
  // return value = 00..010
  result = SwapAdjacentBits(4, 1);
  if (result != 2) {
    cerr << "Test #2: Wrong answer." << endl;
  }

  // Test #3
  // num = 10...00, i = 62
  // return value = 01...00
  result = SwapAdjacentBits(1UL << 63, 62);
  if (result != (1UL << 62)) {
    cerr << "Test #3: Wrong answer." << endl;
  }

  // Test #4
  // num = 00...00, i = 10
  // return value = 00...00
  result = SwapAdjacentBits(0, 10);
  if (result != 0) {
    cerr << "Test #4: Wrong answer." << endl;
  }

  // Test #5
  // num = 11...11, i = 10
  // return value = 11...11
  result = SwapAdjacentBits(-1UL, 10);
  if (result != -1UL) {
    cerr << "Test #4: Wrong answer." << endl;
  }
  return 0;
}
