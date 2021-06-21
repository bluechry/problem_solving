// Implement binary search algorithm. Assume that all elements are distinct and
// return -1 when a given key is not found.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution: interative version
//   중간 원소의 값과 key 값을 비교하여,
//   * key 값이 중간 원소 값보다 크면, 중간 원소보다 큰 원소들을 검색
//   * key 값이 중간 원소 값보다 작으면, 중간 원소보다 작은 원소들을 검색
//   * key 값이 중간 원소와 같으면 중간 원소의 위치를 반환
//   * 위 과정을 검색할 원소가 없을 때까지 반복
//
// Time complexity: O(logN), N is the length of elems[].
//
// Space complexity: O(1)
//
// Note
//   종료 조건을 다음과 같이 세 가지로 나누어서 생각하면 알고리즘을 설계하기
//   쉬워진다.
//   * lo < mid < hi 인 경우
//   * lo = mid < hi 인 경우
//   * lo = mid = hi 인 경우

template<typename T>
int BinarySearch(const vector<T>& elems, T key) {
  // lo, hi를 unsigned type으로 선언하면 안 된다.
  // lo가 0이고 hi가 -1일때 종료할 수 없게 된다.
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    size_t mid = lo + (hi - lo) / 2;
    if (key > elems[mid]) {
      lo = mid + 1;
    } else if (key < elems[mid]) {
      hi = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

// Solution: recursive version
//   중간 원소의 값과 key 값을 비교하여,
//   * key 값이 중간 원소 값보다 크면, 중간 원소보다 큰 원소들을 검색
//   * key 값이 중간 원소 값보다 작으면, 중간 원소보다 작은 원소들을 검색
//   * key 값이 중간 원소와 같으면 중간 원소의 위치를 반환
//   * 위 과정을 검색할 원소가 없을 때까지 반복
//
// Time complexity: O(logN), N is the length of elems[].
//
// Space complexity: O(logN), size of stack used for recursion.

template<typename T>
int BinarySearchRecur(const vector<T>& elems, T key, int lo, int hi) {
  if (lo > hi) {
    return -1;
  }

  int mid = lo + (hi - lo) / 2;
  if (key > elems[mid]) {
    return BinarySearchRecur(elems, key, mid + 1, hi);
  } else if (key < elems[mid]) {
    return BinarySearchRecur(elems, key, lo, mid - 1);
  } else {
    return mid;
  }
}

template<typename T>
int BinarySearchRecur(const vector<T>& elems, T key) {
  return BinarySearchRecur(elems, key, 0, elems.size() - 1);
}

int main() {
{
  // Test #1
  // elems[] = {1, 2, 3, 4, 5}, key = 1
  // return value = 0
  vector<int> elems = {1, 2, 3, 4, 5};
  cout << BinarySearch(elems, 1) << endl;
  cout << BinarySearchRecur(elems, 1) << endl;
}
{
  // Test #2
  // elems[] = {1, 2, 3, 4, 5}, key = 5
  // return value = 4
  vector<int> elems = {1, 2, 3, 4, 5};
  cout << BinarySearch(elems, 5) << endl;
  cout << BinarySearchRecur(elems, 5) << endl;
}
{
  // Test #3
  // elems[] = {1, 2, 3, 4, 5}, key = 0
  // return value = -1
  vector<int> elems = {1, 2, 3, 4, 5};
  cout << BinarySearch(elems, 0) << endl;
  cout << BinarySearchRecur(elems, 0) << endl;
}
{
  // Test #4
  // elems[] = {1, 2, 3, 4, 5}, key = 6
  // return value = -1
  vector<int> elems = {1, 2, 3, 4, 5};
  cout << BinarySearch(elems, 6) << endl;
  cout << BinarySearchRecur(elems, 6) << endl;
}
{
  // Test #5
  // elems[] = {}, key = 1
  // return value = -1
  vector<int> elems;;
  cout << BinarySearch(elems, 1) << endl;
  cout << BinarySearchRecur(elems, 1) << endl;
}
  return 0;
}
