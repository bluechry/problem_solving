// Given an array, rotate the array to the right by k steps, where k is
// non-negative.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline int64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution #1
// * Main Idea
//.  j = 0;
//   do {
//     j = (j + gap) % elems.size();
//     swap(elems[0], elems[j]);
//   } while (j != 0)
//
// * Details
//   elems.size()와 gap과의 관계에 따라서 위의 1, 2번 과정을 여러 번
//   반복해야한다.
//   * elems.size() = 9, elems.size() = 2이면,
//     temp = elems[0]일 때만 2번 과정을 수행하여 모든 원소들을 shift할 수 있다.
//   * elems.size() = 9, elems.size() = 3이면,
//     temp = elems[0]일 때와 temp = elems[1]일 때에 대하여 2번 과정을 수행해야
//     모든 원소들을 shift할 수 있다.
//   * elems.size() = 9, elems.size() = 6이면,
//     temp = elems[0], elems[1], elems[2], 총 세가지 경우에 대하여 2번 과정을
//     수행해야한다.
//
//   위 과정을 일반화하면,
//   elems.size()와 gap의 최대공약수를 k라고 하면,
//   elems[0] ~ elems[k - 1]에 대하여 2번 과정을 수행해야한다.
//
//   elems.size()와 gap의 최대공약수는, elems[]를 하나의 circular list로
//   보았을 때 gap이 k인 circular sublist의 개수를 의미한다.
//
//   let N = elems.size()
//
//   # of circular sublists = N / length of a sublist
//
//   length of a sublist = LCM(N, gap) / gap
//                       = (N * gap / gcd(N, gap)) / gap
//                       = N / gcd(N, gap)
//
//   # of circular sublists = N / (N / gcd(N, gap)))
//                          = gcd(N, gap)
//
//   최대공약수를 구하기 싫으면, 원소가 swap된 횟수를 count하여
//   이 횟수가 원소의 개수와 동일해지면 종료하는 방법이 있다.
//
// Time Complexity: O(N), N is the number of elements in elems[].
//   모든 원소들을 한번 씩 옮기므로 O(N)이다.
//
// Space Complexity: O(1)

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  return b ? gcd(b, a % b) : a;
}

void RotateArray(vector<int>* elems_ptr, int gap) {
  vector<int>& elems = *elems_ptr;
  int num_loops = gcd(elems.size(), gap);
  for (int i = 0; i < num_loops; ++i) {
    int j = i;
    do {
      j = (j + gap) % elems.size();
      swap(elems[i], elems[j]);
    } while (j != i);
  }
}

void RotateArray2(vector<int>* elem_ptr, int gap) {
  vector<int>& elem = *elem_ptr;
  reverse(elem.begin(), elem.end());
  reverse(elem.begin(), elem.begin() + gap);
  reverse(elem.begin() + gap, elem.end());
}

int main() {
{
  // Test #1
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 1
  // return value: {9, 1, 2, 3, 4, 5, 6, 7, 8}
  vector<int> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems, 1);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray2(&elems2, 1);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #2
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 2
  // return value: {8, 9, 1, 2, 3, 4, 5, 6, 7}
  vector<int> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems, 2);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems2, 2);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #3
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 3
  // return value: {7, 8, 9, 1, 2, 3, 4, 5, 6}
  vector<int> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems, 3);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems2, 3);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #6
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 6
  // return value: {4, 5, 6, 7, 8, 9, 1, 2, 3}
  vector<int> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems, 6);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems2, 6);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #7
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 9
  // return value: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  vector<int> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems, 9);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems2, 9);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl << endl;
}
{
  // Test #8
  // elems: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  // num_shift: 0
  // return value: {1, 2, 3, 4, 5, 6, 7, 8, 9}
  vector<int> elems = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems, 0);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> elems2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  RotateArray(&elems2, 0);
  for (int i: elems2) {
    cout << i << ' ';
  }
  cout << endl;
}
  return 0;
}
