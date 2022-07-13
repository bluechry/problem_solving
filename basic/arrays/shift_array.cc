// Given an array of integers, write the codes for shifting the array by k
// positions left or right.

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

// Solution
// * Left shift
//   for (i = 0; i < N - k; ++i)
//     array[i] = array[i + k]
//   empty array[N - k, N - 1]
//
// * Right shift
//   for (i = N - 1; i <= k; --i)
//     array[i] = array[i - k];
//   empty array[0, k - 1]
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

void ShiftArrayLeft(int elems[], size_t len, size_t k) {
  for (int i = 0; i < len - k; ++i) {
    elems[i] = elems[i + k];
  }
  for (int i = len - k; i < len; ++i) {
    elems[i] = 0;
  }
}

void ShiftArrayRight(int elems[], size_t len, size_t k) {
  for (int i = len - 1; i >= k; --i) {
    elems[i] = elems[i - k];
  }
  for (int i = k - 1; i >= 0; --i) {
    elems[i] = 0;
  }
}

//{{{
int main() {
{
  // Test #1 - Shift Left
  int elems[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  ShiftArrayLeft(elems, 10, 3);
  for (auto i: elems) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #2 - Shift Right
  int elems[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  ShiftArrayRight(elems, 10, 3);
  for (auto i: elems) {
    cout << i << " ";
  }
  cout << endl;
}
  return 0;
}
//}}}
