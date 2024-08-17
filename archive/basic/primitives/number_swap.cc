// Swap two numbers without a temporary variable.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//}}}

// Solution #1
//  lhs = lhs - rhs  // find difference of the two numbers.
//  rhs = rhs + lhs  // update rhs by adding lhs to rhs.
//  lhs = rhs - lhs  // update lhs by subtracting lhs from rhs.
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

void SwapUsingDiff(int* lhs, int* rhs) {
  *lhs = *lhs - *rhs;
  *rhs = *rhs + *lhs;
  *lhs = *rhs - *lhs;
}

// Solution #2
//  lhs = lhs xor rhs  // find different bits of the two numbers.
//  rhs = rhs xor lhs  // toggle rhs bits which corresponds to lhs bits.
//  lhs = rhs xor lhs  // toggle rhs bits which corresponds to lhs bits.
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

void SwapUsingXor(int* lhs, int* rhs) {
  *lhs = *lhs ^ *rhs;
  *rhs = *rhs ^ *lhs;
  *lhs = *rhs ^ *lhs;
}

//{{{
int main() {
  int lhs = 100, rhs = 50;
  cout << lhs << " " << rhs << endl;

  SwapUsingDiff(&lhs, &rhs);
  cout << lhs << " " << rhs << endl;

  SwapUsingXor(&lhs, &rhs);
  cout << lhs << " " << rhs << endl;
  return 0;
}
//}}}
