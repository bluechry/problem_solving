// The Hamming distance between two integers is the number of positions at which
// the corresponding bits are different.
// Given two integers x and y, calculate the Hamming distance.
// Assume that 0 <= x, y < 2^31
//

//{{{
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
//}}}

// Solution
// Count the number of set bits in x^y.
//
// Time Complexity: O(s), s is the number of positions at which the
// corresponding bits are different.
//
// Space Complexity: O(1)

int FindHammingDistance(int x, int y) {
  int diff = x ^ y;
  int dist = 0;
  while (diff) {
    ++dist;
    diff = diff & (diff - 1);
  }
  return dist;
}

//{{{
int main() {
  // Test #1
  // input: x = 1, y = 0
  // return: 1
  cout << "Hamming distance of (1, 0): " << FindHammingDistance(1, 0) << endl;

  // Test #2
  // input: x = 1, y = 1
  // return: 0
  cout << "Hamming distance of (1, 1): " << FindHammingDistance(1, 1) << endl;

  // Test #3
  // input: x = 45, y = 23
  // return: 4
  cout << "Hamming distance of (45, 23): " << FindHammingDistance(45, 23)
       << endl; 
  return 0;
}
//}}}
