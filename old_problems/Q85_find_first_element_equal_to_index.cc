// Design an efficient algorithm that takes a sorted array of integers, and
// returns an index i such that the element at index i equals i. The array may
// contains duplicate elements.
// For example, when the input is <0, 0, 0, 1, 2, 5, 7> your algorithm should
// return 0 or 5.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   원소가 중복될 수도 있다는 조건은 binary search로의 reduction이 불가능하게
//   만든다. 예를들어, <0, 0, 0, 1, 2, 5, 7>이 주어지고, mid가 3(elems[3] = 1)
//   이라고 하자. 원소가 중복되지 않았으면 mid의 왼쪽에 있는 원소들은 검색할
//   필요가 없다. 하지만 원소가 중복된 경우는 elems[0] = 0과 같은 경우가
//   존재할 수 있으므로 왼쪽 원소들도 다 검색해야한다.
//
//   그래도 search space를 pruning할 수 있는 방법이 있다.
//   왼쪽 subarray의 영역을 '[lo, min(mid - 1, elems[mid])]'로 하고
//   오른쪽 subarray의 영역을 '[max(mid + 1, elems[mid]), hi]'로 하면 된다.
//
// Time Complexity: O(N), N is the length of elems.
//   Worst case는 index와 동일한 entry가 없는 경우이다.
//   T(N) = 2 * T(N / 2) = N
//
// Space Complexity: O(1), no additional space.

int FindEntryEqualToIndex(vector<int> elems, int lo, int hi) {
  if (lo > hi) {
    return -1;
  }
  int mid = lo + (hi - lo) / 2;
  if (elems[mid] == mid) {
    return mid;
  }
  int result = FindEntryEqualToIndex(elems, lo, min(mid - 1, elems[mid]));
  if (result != -1) {
    return result;
  }
  return FindEntryEqualToIndex(elems, max(mid + 1, elems[mid]), hi);
}

int FindEntryEqualToIndex(vector<int> elems) {
  return FindEntryEqualToIndex(elems, 0, elems.size() - 1);
}

int main() {
{
  // Test #1
  // elems[] = {-2, 0, 2, 3, 6, 7, 9}
  // return value = 2 or 3
  vector<int> elems = {-2, 0, 2, 3, 6, 7, 9};
  cout << FindEntryEqualToIndex(elems) << endl;
}
{
  // Test #2
  // elems[] = {0, 2, 4, 8, 9, 10};
  // return value = 0
  vector<int> elems = {0, 2, 4, 6, 8, 9, 10};
  cout << FindEntryEqualToIndex(elems) << endl;
}
{
  // Test #3
  // elems[] = {-1, -2, -3, -4, -5, 5}
  // return value = 5
  vector<int> elems = {-1, -2, -3, -4, -5, 5};
  cout << FindEntryEqualToIndex(elems) << endl;
}
{
  // Test #4
  // elems[] = {-1, -2, -3, -4, -5, -6}
  // return value = -1
  vector<int> elems = {-1, -2, -3, -4, -5, -6};
  cout << FindEntryEqualToIndex(elems) << endl;
}
{
  // Test #5
  // elems[] = {0, 0, 0, 1, 2, 5, 7}
  // return value = 0 or 5
  vector<int> elems = {0, 0, 0, 1, 2, 5, 7};
  cout << FindEntryEqualToIndex(elems) << endl;
}
{
  // Test #6
  // elems[] = {-1, 0, 0, 1, 2, 6, 6}
  // return value = 6
  vector<int> elems = {-1, 0, 0, 1, 2, 6, 6};
  cout << FindEntryEqualToIndex(elems) << endl;
}
  return 0;
}
