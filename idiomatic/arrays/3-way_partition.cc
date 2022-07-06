// Divide a given array into three parts using a given pivot.
// * The elements of the first part are smaller than the pivot,
// * The elements of the second part are same as the pivot, and
// * The elements of the third part are larger than the pivot.
// * The pivot should be located in right position which is the location of the
//   pivot when the array is sorted.
// * Return the range of the second part which contains the pivot.

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
// Define three types of cursors.
// * 'lt' points the next element of the elements that is less than the pivot.
//   lt goes from the first element to the last element.
// * 'gt' points the previous element of the elements that is larger than the'
//   pivot. 'gt' goes from the last element to the first element.
// * 'i' points the current element that is not compared with the pivot.
//
// While i is not larger than the gt:
//   if elems[i] < pivot
//     swap(elems[i++], elems[lt++])
//   else if elems[i] > pivot:
//     swap(elems[i], elems[gt--])
//   else
//     ++i
// Return (lt, gt)
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

pair<int, int> ThreeWayPartition(vector<int>* elems_ptr, int pivot_idx) {
  vector<int>& elems = *elems_ptr;
  if (elems.empty()) {
    return pair<int, int>(-1, -1);
  }

  int pivot = elems[pivot_idx];
  int lt = 0, gt = elems.size() - 1, i = 0;
  while (i <= gt) {
    if (elems[i] < pivot) {
      swap(elems[i++], elems[lt++]);
    } else if (elems[i] > pivot) {
      swap(elems[i], elems[gt--]);
    } else {
      ++i;
    }
  }
  return pair<int, int>(lt, gt);
}

//{{{
int main() {
{
  // Test #1.
  // A[] = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2}
  // return value = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2}
  vector<int> A = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2};
  pair<int, int> pivots = ThreeWayPartition(&A, 0);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
  printf("range of the 2nd part: (%d, %d)\n\n", pivots.first, pivots.second);
}
{
  // Test #2.
  // A[] = {1, 1, 1, 1, 0, 0, 0, 0}
  // return value = {0, 0, 0, 0, 1, 1, 1, 1}
  vector<int> A = {1, 1, 1, 1, 0, 0, 0, 0};
  pair<int, int> pivots = ThreeWayPartition(&A, 0);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
  printf("range of the 2nd part: (%d, %d)\n\n", pivots.first, pivots.second);
}
{
  // Test #3.
  // A[] = {1, 1, 1, 1}
  // return value = {1, 1, 1, 1}
  vector<int> A = {1, 1, 1, 1};
  pair<int, int> pivots = ThreeWayPartition(&A, 0);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
  printf("range of the 2nd part: (%d, %d)\n\n", pivots.first, pivots.second);
}
{
  // Test #4.
  // A[] = {}
  // return value = {}
  vector<int> A;
  pair<int, int> pivots = ThreeWayPartition(&A, 0);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
  printf("range of the 2nd part: (%d, %d)\n\n", pivots.first, pivots.second);
}
{
  // Test #5.
  // A[] = {5, 1, 1, 1, 2 ,2, 2, 6, 6, 6, 7, 7 ,7};
  // return value = {1}
  vector<int> A = {5, 1, 1, 1, 2, 2, 2, 6, 6, 6, 7, 7, 7};
  pair<int, int> pivots = ThreeWayPartition(&A, 0);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
  printf("range of the 2nd part: (%d, %d)\n\n", pivots.first, pivots.second);
}
  return 0;
}
//}}}
