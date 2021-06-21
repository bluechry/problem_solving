// Write a program which takes as input two sorted arrays of integers, and
// updates the first to the combined entries of the two arrays in sorted order.
// Assume that
// * the two arrays are not empty.
// * the first array has enough empty entries at its end to hold the result.

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

// Solution
//   두 배열을 각각 A, B라고 하고 각 배열의 크기를 각각 n, m이라고 하자.
//   A[n - 1]에서 A[0]까지 B[m - 1]에서 B[0]까지 역순으로 원소 크기의
//   내림차순으로 merge하면서 A[n + m - 1]부터 A[0]까지 기록한다.
//
// Time Complexity: O(n + m)
//
// Space Complexity: O(1)

void MergeInPlace(int A[], int n, int B[], int m) {
  if (n == 0 || m == 0) {
  }

  int a = n - 1, b = m - 1, write_idx = n + m - 1;
  while (a >= 0 && b >= 0) {
    A[write_idx--] = (A[a] > B[b]) ?  A[a--] : B[b--];
  }
  while (b >= 0) {
    A[write_idx--] = B[b--];
  }
}

int main() {
{
  // Test #1
  // A[] = {1, 2, 3, 4, 5, _, _, ..., _}
  // B[] = {6, 7, 8, 9, 10}
  int A[1024] = {1, 2, 3, 4, 5, };
  int B[5] = {6, 7, 8, 9, 10};
  MergeInPlace(A, 5, B, 5);
  for (int i = 0; i < 10; ++i) {
    cout << A[i] << ' ';
  }
  cout << endl;
}
{
  // Test #2
  // A[] = {6, 7, 8, 9, 10, _, _, ..., _}}
  // B[] = {1, 2, 3, 4, 5};
  int A[1024] = {6, 7, 8, 9, 10, };
  int B[5] = {1, 2, 3, 4, 5};
  MergeInPlace(A, 5, B, 5);
  for (int i = 0; i < 10; ++i) {
    cout << A[i] << ' ';
  }
  cout << endl;
}
  return 0;
}
