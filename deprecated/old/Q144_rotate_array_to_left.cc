// Given an array of integers, rotate the elements to the left by k positions.
// Assume that k is not larger than the array size.

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

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  return b ? gcd(b, a % b) : a;
}

// Solution
// For i in [0, GCD(N, k) - 1], swap the i-th element and the (i + k)-th element
// cyclically until the (i + k)-th element is not the first one.
//
// Note: why we obtain the GCD(N, k)?
// * We have to find the # of loops of the cyclic swap procedure.
// * num_loops = N / len_of_cycle - (1)
// * len_of_cycle = LCM(N, k) / k - (2)
//
// We solve the equations (1) and (2),
// * len_of_cycle = (N * k) / GCD(N, k) / k = N / GCD(N, k)
// * num_loops = N / (N / GCD(N, k) = GCD(N, k)
//
// Therefore, # of loops = GCD(N, k).
//
// Time Complexity: O(N), N is the number of elements.
//
// Space Complexity: O(1)

void RotateToLeft(vector<int>* elems_ptr, int gap) {
  vector<int>& elems = *elems_ptr;
  int num_loops = gcd(elems.size(), gap);
  for (int i = 0; i < num_loops; ++i) {
    int j = i;
    while (true) {
      int next = (j + gap) % elems.size();
      if (next == i) {
        break;
      }
      swap(elems[j], elems[next]);
      j = next;
    }
  }
}

// Solution
// * Reverse the whole array.
// * Reverse first N - k elements.
// * Reverse last k elements.
//
// Time Complexity: O(N), N is the number of elements.
//
// Space Complexity: O(1)

void RotateToLeft2(vector<int>* elems_ptr, int gap) {
  vector<int>& elems = *elems_ptr;
  reverse(elems.begin(), elems.end());
  reverse(elems.begin(), elems.end() - gap);
  reverse(elems.end() - gap, elems.end());
}

//{{{
int main() {
{
  // Test #1
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 6
  // result[] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5}
  vector<int> elems = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(&elems, 6);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(&elems2, 6);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #2
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 3
  // result[] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2}
  vector<int> elems = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(&elems, 3);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(&elems2, 3);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #3
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 10
  // result[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
  vector<int> elems = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(&elems, 10);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(&elems2, 10);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
  return 0;
}
//}}}
