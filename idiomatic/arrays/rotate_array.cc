// Given an array of integers, rotate the elements to the left or to the right
// by k positions.

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
// Let N = the number of elements in the array
//     k = rotate unit
//
// For i in [0, GCD(N, k) - 1], shift elements by moving the i-th element to the
// (i+k)-th (or i-k)-th position cyclically.
//
// Note: why we obtain the GCD(N, k)?
// * We have to find the # of loops of the cyclic shift procedure.
// * num_loops = N / len_of_cycle - (1)
// * len_of_cycle = LCM(N, k) / k - (2)
//
// We solve the equations (1) and (2),
// * len_of_cycle = (N * k) / GCD(N, k) / k = N / GCD(N, k)
// * num_loops = N / (N / GCD(N, k) = GCD(N, k)
//
// Time Complexity: O(N), N is the number of elements in the array.
//
// Space Complexity: O(1)

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  return b ? gcd(b, a % b) : a;
}

void RotateToLeft(int* elems, size_t len, size_t k) {
  int num_loops = gcd(len, k);
  for (int i = 0; i < num_loops; ++i) {
    int j = i;
    while (true) {
      int next = (j + k) % len;
      if (next == i) {
        break;
      }
      swap(elems[j], elems[next]);
      j = next;
    }
  }
}

void RotateToRight(int* elems, size_t len, size_t k) {
  int num_loops = gcd(len, k);
  for (int i = 0; i < num_loops; ++i) {
    int j = (i + k) % len;
    while (j != i) {
      swap(elems[i], elems[j]);
      j = (j + k) % len;
    }
  }
}

// Solution #2
// Shift the array by reversing the whole array and its subarrays.
//
// Time Complexity: O(N), N is the number of elements in the array.
//
// Space Complexity: O(1)

void RotateToLeft2(int* elems, size_t len, size_t k) {
  reverse(&elems[0], &elems[len]);
  reverse(&elems[0], &elems[len - k]);
  reverse(&elems[len - k], &elems[len]);
}

void RotateToRight2(int* elems, size_t len, size_t k) {
  reverse(&elems[0], &elems[len]);
  reverse(&elems[0], &elems[k]);
  reverse(&elems[k], &elems[len]);
}

//{{{
void TestRotateToLeft() {
  cout << "Testing RotateToLeft()\n" << endl;
{
  // Test #1
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 6
  // result[] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5}
  int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(elems, 10, 6);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #2
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 3
  // result[] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2}
  int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(elems, 10, 3);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #3
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 10
  // result[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
  int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft(elems, 10, 10);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
}

void TestRotateToLeft2() {
  cout << "Testing RotateToLeft2()\n" << endl;
{
  // Test #1
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 6
  // result[] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5}
  int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft2(elems, 10, 6);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #2
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 3
  // result[] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2}
  int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft2(elems, 10, 3);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #3
  // elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, gap = 10
  // result[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
  int elems[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToLeft2(elems, 10, 10);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
}

void TestRotateToRight() {
  cout << "Testing RotateToRight()\n" << endl;
{
  // Test #1
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 1
  // return value: {9, 1, 2, 3, 4, 5, 6, 7, 8}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight(elems, 9, 1);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #2
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 2
  // return value: {8, 9, 1, 2, 3, 4, 5, 6, 7}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight(elems, 9, 2);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #3
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 3
  // return value: {7, 8, 9, 1, 2, 3, 4, 5, 6}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight(elems, 9, 3);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #6
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 6
  // return value: {4, 5, 6, 7, 8, 9, 1, 2, 3}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight(elems, 9, 6);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #7
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 9
  // return value: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight(elems, 9, 9);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #8
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 0
  // return value: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight(elems, 9, 0);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
}

void TestRotateToRight2() {
  cout << "Testing RotateToRight2()\n" << endl;
{
  // Test #1
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 1
  // return value: {9, 1, 2, 3, 4, 5, 6, 7, 8}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight2(elems, 9, 1);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #2
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 2
  // return value: {8, 9, 1, 2, 3, 4, 5, 6, 7}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight2(elems, 9, 2);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #3
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 3
  // return value: {7, 8, 9, 1, 2, 3, 4, 5, 6}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight2(elems, 9, 3);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #6
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 6
  // return value: {4, 5, 6, 7, 8, 9, 1, 2, 3}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight2(elems, 9, 6);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #7
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 9
  // return value: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight2(elems, 9, 9);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #8
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 0
  // return value: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateToRight2(elems, 9, 0);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
}

int main() {
  TestRotateToLeft();
  TestRotateToLeft2();
  TestRotateToRight();
  TestRotateToRight2();
  return 0;
}
//}}}
