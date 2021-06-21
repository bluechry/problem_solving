// Given a sorted array and an element, return the number of elements less than
// the element. Assume that the array has no duplicate element.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   Binary search algorithm을 그대로 수행하되, elem을 못 찾으면 '-1'이 아닌
//   lo를 반환한다.
//
//   elem을 못 찾는 경우, binary search가 종료되는 시점에 lo는 elem보다
//   큰 값들 중에 가장 작은 값을 가리키게 되며, lo 값은 elems[0, lo - 1]의
//   원소 개수와 같다.
//
// Time Complexity: O(logN), N is the number of elements in the array.
//
// Space Complexity: O(1), no extra space.

int GetRank(const vector<int>& elems, int elem) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (elems[mid] < elem) {
      lo = mid + 1;
    } else if (elems[mid] > elem) {
      hi = mid - 1;
    } else {
     return mid;
    }
  }
  return lo;
}

int main() {
{
  // Test #1
  // elems[] = {0, 1, 2, 3, ..., 9};
  // rank of elems[i] = i
  vector<int> elems = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (int i: elems) {
    cout << GetRank(elems, i) << ' ';
  }
  cout << endl;
}
{
  // Test #2
  // elems[] = {1, 3, 5, 7, 9, 11};
  // ranks of {2, 4, 6, 8, 10, 12} = {1, 2, 3, 4, 5, 6}
  vector<int> elems = {1, 3, 5, 7, 9, 11};
  for (int i: elems) {
    cout << GetRank(elems, i + 1) << ' ';
  }
  cout << endl;
}
  return 0;
}
