// Solve Q80 again when the given sorted array has duplicates.

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
//  Q80번의 solution을 살짝 수정해보자.
//  elems[mid]와 elems[hi]를 비교하여 left 또는 right subarray에서 가장 작은
//  원소(이하 pivot)를 찾는데, elems[mid] == elems[hi]인 경우에는 어느 쪽
//  array에 pivot이 있을지 특정할 수가 없다.
//
//  이 때에는 양쪽 subarray 모두를 검색해보아야하는데, 양쪽에서 찾은 pivot의
//  index들 중에서 pivot의 값이 작은 쪽의 index를 반환한다.
//  만약 양쪽의 pivot 값이 같다면 left subarray에서 찾은 pivot의 index를
//  반환한다.
//
// Time Complexity
//  * 최악의 경우, 즉, 모든 원소들이 동일한 경우: O(N)
//  * 대부분의 원소들이 동일한 경우: ~ O(N)
//  * 모든 원소들이 distinct한 경우: O(logN)
//  * 대부분의 원소들이 distinct한 경우: ~ O(logN)
//
// Space Complexity: O(1)

int SearchCyclicallySortedArray(vector<int>& elems, int lo, int hi) {
  if (lo == hi) {
    return lo;
  }

  int mid = lo + (hi - lo) / 2;
  if (elems[mid] > elems[hi]) {
    return SearchCyclicallySortedArray(elems, mid + 1, hi);
  } else if (elems[mid] < elems[hi]) {
    return SearchCyclicallySortedArray(elems, lo, mid);
  } else {
    int left_result = SearchCyclicallySortedArray(elems, lo, mid);
    int right_result = SearchCyclicallySortedArray(elems, mid + 1, hi);
    return (elems[left_result] <= elems[right_result])
           ? left_result : right_result;
  }
}

int main() {
{
  // Test #1.
  // elems[] = {368, 368, 550, 550, 103, 103, 220, 220, 368, 368}
  // return value = 4
  vector<int> elems = {368, 368, 550, 550, 103, 103, 220, 220, 368, 368};
  cout << SearchCyclicallySortedArray(elems, 0, elems.size() - 1) << endl;
}
{
  // Test #2.
  // elems[] = {1, 1, 1, 1, 1, 1}
  // return value = 0
  vector<int> elems = {1, 1, 1, 1, 1, 1};
  cout << SearchCyclicallySortedArray(elems, 0, elems.size() - 1) << endl;
}
  return 0;
}
