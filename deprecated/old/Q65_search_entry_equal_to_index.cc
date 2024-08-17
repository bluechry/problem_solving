// Design an efficient algorithm that takes a sorted array of distinct integers,
// and returns an index i such that the element at index i equals i.
// For example, when the input is <-2, 0, 2, 3, 6, 7, 9> your algorithm should
// return 2 or 3.

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

// Solution #1
//   다음 성질을 이용하여 binary search를 적용해보자.
//   * i 위치의 값이 i 보다 작으면, [0, i - 1]의 값들은 모두 index 보다 작다.
//   * i 위치의 값이 i 보다 크면, [i + 1, n - 1]의 값들은 모두 index 보다 크다.
//
//   mid = lo + (hi - lo) / 2
//   if (mid > elems[mid])  // 첫번째 경우, mid의 오른쪽을 검색한다.
//     lo = mid + 1
//   else if (mid < elems[mid]):  // 두번째 경우, mid의 왼쪽을 검색한다.
//     hi = mid - 1
//   else:
//     return mid
//
// Time Complexity: O(logN), N is # of elements.
//
// Space Complexity: O(1)

int SearchEntryEqualToIndex(vector<int> elems) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (mid > elems[mid]) {
      lo = mid + 1;
    } else if (mid < elems[mid]) {
      hi = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

// Solution #2
//   Solution #1과 동일한 방법이지만 문제를 바라보는 관점이 다르다.
//   주어진 문제를,
//   'elems[]의 각 원소에서 index 값을 뺀 배열에서 0을 찾는 문제'로
//   볼 수 있다.
//
//   elems_2[] = elems[i] - i for i = [0, n-1]
//
//   elems_2[]의 특징은 다음과 같다.
//   * 값이 0인 원소의 왼쪽의 원소들은 모두 음수이다.
//   * 0인 원소의 오른쪽의 원소들은 모두 양수이다.
//
//   elems_2[]를 직접 구할 필요는 없고, 알고리즘을 다음과 같이 쓰면 된다.
//
//   mid = lo + (hi - lo) / 2
//   diff = elems[mid] - mid
//   if (diff < 0):
//     lo = mid + 1
//   else if (diff > 0):
//     hi = mid - 1
//   else
//     return mid
//
// Time Complexity: O(logN), N is # of elements.
//
// Space Complexity: O(1)
int SearchEntryEqualToIndex2(vector<int> elems) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int diff = elems[mid] - mid;
    if (diff < 0) {
      lo = mid + 1;
    } else if (diff > 0) {
      hi = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
{
  // Test #1
  // elems[] = {-2, 0, 2, 3, 6, 7, 9}
  // return value = 2 or 3
  vector<int> elems = {-2, 0, 2, 3, 6, 7, 9};
  cout << SearchEntryEqualToIndex(elems) << endl;
  cout << SearchEntryEqualToIndex2(elems) << endl;
}
{
  // Test #2
  // elems[] = {0, 2, 4, 8, 9, 10};
  // return value = 0
  vector<int> elems = {0, 2, 4, 6, 8, 9, 10};
  cout << SearchEntryEqualToIndex(elems) << endl;
  cout << SearchEntryEqualToIndex2(elems) << endl;
}
{
  // Test #3
  // elems[] = {-1, -2, -3, -4, -5, 5}
  // return value = 5
  vector<int> elems = {-1, -2, -3, -4, -5, 5};
  cout << SearchEntryEqualToIndex(elems) << endl;
  cout << SearchEntryEqualToIndex2(elems) << endl;
}
{
  // Test #4
  // elems[] = {-1, -2, -3, -4, -5, -6}
  // return value = -1
  vector<int> elems = {-1, -2, -3, -4, -5, -6};
  cout << SearchEntryEqualToIndex(elems) << endl;
  cout << SearchEntryEqualToIndex2(elems) << endl;
}
  return 0;
}
