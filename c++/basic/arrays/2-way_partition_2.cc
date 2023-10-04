// Divide a given array into two parts using a given pivot.
// * The elements of the first part are smaller than the pivot.
// * The elements of the second part are larger than or equal to the pivot.
// * The pivot should be located in right place which is the location of the
//   pivot when the array is sorted.
// * Return the index of the pivot.

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
// Define two types of cursors.
// * 'lo' points the next element of the elements that is less than or equal to
//   the pivot.
//   lo goes from the first element to the last element.
// * 'hi' points the previous element of the elements that is larger than or
//   equal to the pivot.
//   hi goes from the last element to the first element.
//
// Swap(elems[0], elems[pivot_idx])
// lo = 1, hi = elems.size() - 1
// While lo is less than hi:
//   move lo to the next element that is larger than or equal to the pivot.
//   move hi to the next element that is less than or equal to the pivot.
//   swap(elems[lo++], elems[hi--])
// Swap(elems[0], elems[hi])
// Return hi.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

int TwoWayPartition(vector<int>* elems_ptr, int pivot_idx) {
  vector<int>& elems = *elems_ptr;
  if (elems.empty()) {
    return -1;
  }

  swap(elems[0], elems[pivot_idx]);
  int lo = 1, hi = elems.size() - 1;
  while (true) {
    while (lo < elems.size() && elems[lo] < elems[0]) {
      ++lo;
    }
    while (hi >= 1 & elems[hi] > elems[0]) {
      --hi;
    }
    if (lo >= hi) {
      break;
    }
    swap(elems[lo++], elems[hi--]);
  }
  swap(elems[0], elems[hi]);
  return hi;
}

//{{{
int main() {
{
  // Test #1
  // elems[] = {10, 9, 8, 7, 6, 5, 5, 5, 4, 3, 2, 1}, pivot_idx = 5
  // return elems[] = {1, 2, 3, 4, 6, 5, 5, 5, 7, 8, 9, 10}, pivot_idx = 4
  vector<int> elems = {10, 9, 8, 7, 6, 5, 5, 5, 4, 3, 2, 1};
  int split_idx = TwoWayPartition(&elems, 5);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;
  cout << "pivot_idx: " << split_idx << '\n' << endl;
}
{
  // Test #2
  // elems[] = {}
  // return elems[] = {}, pivot_idx = -1;
  vector<int> elems = {};
  int split_idx = TwoWayPartition(&elems, 0);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;
  cout << "pivot_idx: " << split_idx << '\n' << endl;
}
{
  // Test #3
  // elems[] = {1, 1, 1, 1, 1, 1}, pivot_idx = 0
  // return elems[] = {1, 1, 1, 1, 1, 1}, pivot_idx = 0
  vector<int> elems = {1, 1, 1, 1, 1, 1};
  int split_idx = TwoWayPartition(&elems, 0);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;
  cout << "pivot_idx: " << split_idx << '\n' << endl;
}
{
  // Test #4
  // elems[] = {1, 1, 1, 1, 1, 2}, pivot_idx = 5
  // return elems[] = {1, 1, 1, 1, 1, 2}, pivot_idx = 5
  vector<int> elems = {1, 1, 1, 1, 1, 2};
  int split_idx = TwoWayPartition(&elems, 5);
  for (int i: elems) {
    cout << i << ' ';
  }
  cout << endl;
  cout << "pivot_idx: " << split_idx << '\n' << endl;
}
  return 0;
}
//}}}
