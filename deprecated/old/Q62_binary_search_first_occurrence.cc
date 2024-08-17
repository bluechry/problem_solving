// Write a method that takes a sorted array and a key and returns the index of
// the first occurrence of that key in the array.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution #1
//   Binary search를 살짝 변형한다. Key 값을 찾더라도 멈추지 않고 key 값보다
//   왼쪽에 위치한 원소들을 계속해서 검색한다.
//
//   lo와 hi 커서는 key 값과 동일한 '첫번째 원소'에서 만나고,
//   hi가 '첫번째 원소' 밑으로 내려가면 종료하게 된다.
//   (또는, lo와 hi 커서가 key 값과 동일한 '첫번째 원소'의 바로 앞에서 만나고,
//   lo가 '첫번째 원소'로 올라오면서 종료하게 된다.)
//   그러면 lo 위치를 반환하면 된다.
//
//   만약, key 값과 동일한 원소가 없다면 lo와 hi 커서는
//   'key 보다 큰 가장 작은 원소'에서 만나게 되고,
//   hi가 그 원소 밑으로 내려가면 종료하게 된다.
//   (또는, lo와 hi 커서가 'key 보다 큰 가장 작은 원소'의 바로 앞에서 만나고,
//   lo가 'key 보다 큰 가장 작은 원소'로 올라오면서 종료하게 된다.)
//   이 경우에는 -1을 반환한다.
//
// Time Complexity: O(logN)
//
// Space Complexity: O(1)
//
// Note
//   검색 진행상황을 아래와 같이 나누어보면 종료조건을 설계하기 쉬워진다.
//   * mid가 key 값과 동일한 원소들의 중간에 있게 되는 경우
//   * mid가 key 값과 동일한 원소들의 처음에 있게 되는 경우
//   * mid가 key 값과 동일한 원소들의 마지막에 있게 되는 경우
template<typename T>
int BinarySearchFirstKey(const vector<T>& elems, T key) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (key > elems[mid]) {
      lo = mid + 1;
    } else if (key <= elems[mid]) {
      hi = mid - 1;
    }
  }
  if (elems[lo] == key) {
    return lo;
  } else {
    return -1;
  }
}

// Solution #2
//   Solution #1에서 lo 커서의 위치를 반환하는 대신 key 값과 동일한 원소를
//   만날 때마다 위치를 기록해 두었다가 반환한다.
//
// Time Complexity: O(logN)
//
// Space Complexity: O(1)
template<typename T>
int BinarySearchFirstKey2(const vector<T>& elems, T key) {
  int lo = 0, hi = elems.size() - 1, result = -1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (key > elems[mid]) {
      lo = mid + 1;
    } else if (key < elems[mid]) {
      hi = mid - 1;
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
  // return value = 0
  vector<int> elems = {1, 1, 1, 1, 1};
  cout << BinarySearchFirstKey(elems, 1) << endl;
  cout << BinarySearchFirstKey2(elems, 1) << endl;
}
{
  // Test #2
  // elems[] = {1, 1, 2, 2, 2}, key = 2
  // return value = 2
  vector<int> elems = {1, 1, 2, 2, 2};
  cout << BinarySearchFirstKey(elems, 2) << endl;
  cout << BinarySearchFirstKey2(elems, 2) << endl;
}
{
  // Test #3
  // elems[] = {1, 1, 2, 2, 2}, key = 3
  // return value = -1
  vector<int> elems = {1, 1, 2, 2, 2};
  cout << BinarySearchFirstKey(elems, 3) << endl;
  cout << BinarySearchFirstKey2(elems, 3) << endl;
}
{
  // Test #4
  // elems[] = {1, 1, 2, 2, 2}, key = 0
  // return value = -1
  vector<int> elems = {1, 1, 2, 2, 2};
  cout << BinarySearchFirstKey(elems, 0) << endl;
  cout << BinarySearchFirstKey2(elems, 0) << endl;
}
  return 0;
}
