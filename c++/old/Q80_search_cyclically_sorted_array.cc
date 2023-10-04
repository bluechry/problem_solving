// An array is said to be cyclically sorted if it is possible to cyclically
// shift its entries so that it becomes sorted.
// For example, {378, 478, 550, 631, 103, 203, 220, 234, 279, 368}.
// Design an O(logN) algorithm for finding the position of the smallest element
// in a cyclically sorted array.
// Assume all elements are distinct.

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
//   * lo = 0, hi = elems.size() - 1
//   * mid = lo + (hi - lo) / 2
//
//   1. elems[mid] > elems[hi] 이면 lo = mid + 1
//   2. elems[mid] < elems[hi] 이면 hi = mid
//   3. lo < hi 를 만족하는 동안 1~2 과정을 반복
//
//   Note
//   * elems[mid] = elems[hi]인 경우는 존재하지 않는다.
//
// Time Complexity: O(logN), N is # of elements.
//
// Space Complexity: O(1)

int SearchCyclicallySortedArray(const vector<int>& elems) {
  int lo = 0, hi = elems.size() - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (elems[mid] > elems[hi]) {
      lo = mid + 1;
    } else {  // elems[mid] < elems[hi]
      hi = mid;
    }
  }
  return lo;
}

// Another implementation which is comparing mid with lo.
// The previous version is simpler and easier to read.
int SearchCyclicallySortedArray2(const vector<int>& elems) {
  int lo = 0, hi = elems.size() - 1;
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (elems[mid] >= elems[lo]) {
      lo = mid + 1;
    } else {  // elems[mid] < elems[lo]
      hi = mid;
    }
  }
  // Non-cyclically sorted array가 주어지면, lo가 0을 가리키지 않고
  // elems.size() - 1를 가리키게 된다. 이러한 경우에는 0을 반환하자.
  if (lo == elems.size() - 1) {
    return 0;
  } else {
    return lo;
  }
}

int main() {
{
  // Test #1.
  // elems[] = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368}
  // return value = 4
  vector<int> elems = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
  cout << SearchCyclicallySortedArray(elems) << endl;
  cout << SearchCyclicallySortedArray2(elems) << endl;
}
{
  // Test #2.
  // elems[] = {1, 2, 3, 4, 5, 6}
  // return value = 0
  vector<int> elems = {1, 2, 3, 4, 5, 6};
  cout << SearchCyclicallySortedArray(elems) << endl;
  cout << SearchCyclicallySortedArray2(elems) << endl;
}
  return 0;
}
