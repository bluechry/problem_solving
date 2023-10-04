// Design an efficient algorithm that takes a sorted array and a key, and finds
// the index of the first occurrence of an element greater than that key.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution #1
//   Binary search를 살짝 변형한다. Key 값보다 작거나 같은 원소를 만나면
//   계속해서 그 원소의 오른쪽 원소들을 검색한다.
//
//   lo와 hi 커서는 'key 값보다 큰 첫번째 원소'에서 만나고,
//   hi가 그 원소보다 왼쪽으로 옮겨가면서 종료하게 된다.
//   (또는, lo와 hi 커서가 'key 값보다 큰 첫번째 원소'의 바로 앞에서 만나고,
//    lo가 'key 값보다 큰 첫번째 원소'로 옮겨오면서 종료하게 된다.)
//   그러면 lo 위치를 반환하면 된다.
//
//   만약, key 값보다 큰 원소가 없다면 lo와 hi는 마지막 원소에서 만나고,
//   lo가 마지막 원소를 지나면서 종료하게 된다.
//   이 경우에는 -1을 반환한다.
//
// Time Complexity: O(logN)
//
// Space Complexity: O(1)
//
// Note
//   * Key 값과 동일한 원소들 중 마지막 원소를 찾는 것과 유사하다.
//   * 검색 진행 상황을 다음과 같이 나누어보면 종료 조건을 정의하기 쉬워진다.
//     * mid가 key 값과 동일한 원소들의 중간 원소를 가리킬 때
//     * mid가 key 값과 동일한 원소들의 첫 원소를 가리킬 때
//     * mid가 key 값과 동일한 원소들의 마지막 원소를 가리킬 때

template<typename T>
int BinarySearchUpperBound(const vector<T>& elems, T key) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (key >= elems[mid]) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  if (lo < elems.size()) {
    return lo;
  } else {
    return -1;
  }
}

// Solution #2
//   Solution #1에서 lo 커서의 위치를 반환하는 대신 key 값보다 큰 원소를
//   만날 때마다 위치를 기록해 두었다가 반환한다.
//
// Time Complexity: O(logN)
//
// Space Complexity: O(1)

template<typename T>
int BinarySearchUpperBound2(const vector<T>& elems, T key) {
  int lo = 0, hi = elems.size() - 1, result = -1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (key >= elems[mid]) {
      lo = mid + 1;
    } else {
      result = mid;
      hi = mid - 1;
    }
  }
  return result;
}

int main() {
{
  // Test #1
  // elems[] = {1, 1, 1, 1, 1}, key = 1
  // return value = -1
  vector<int> elems = {1, 1, 1, 1, 1};
  cout << BinarySearchUpperBound(elems, 1) << endl;
  cout << BinarySearchUpperBound2(elems, 1) << endl;
}
{
  // Test #2
  // elems[] = {1, 1, 2, 2, 2}, key = 1
  // return value = 2
  vector<int> elems = {1, 1, 2, 2, 2};
  cout << BinarySearchUpperBound(elems, 1) << endl;
  cout << BinarySearchUpperBound2(elems, 1) << endl;
}
{
  // Test #3
  // elems[] = {1, 1, 2, 2, 2}, key = 0
  // return value = 0
  vector<int> elems = {1, 1, 2, 2, 2};
  cout << BinarySearchUpperBound(elems, 0) << endl;
  cout << BinarySearchUpperBound2(elems, 0) << endl;
}
{
  // Test #4
  // elems[] = {1, 1, 2, 2, 2}, key = 3
  // return value = -1
  vector<int> elems = {1, 1, 2, 2, 2};
  cout << BinarySearchUpperBound(elems, 3) << endl;
  cout << BinarySearchUpperBound2(elems, 3) << endl;
}
  return 0;
}
