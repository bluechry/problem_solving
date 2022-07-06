// Design an O(logN) algorithm for finding the position of an element k in a
// cyclically sorted array of distinct elements.

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
//   최소 원소(pivot)의 위치를 먼저 찾고,
//   pivot 왼쪽의 subarray와 pivot 오른쪽의 subarray에서 binary search를
//   사용하여 key를 찾는다.
//
// Time Complexity
//   * Pivot을 찾는 비용: O(logN)
//   * Binary search 비용: 2 * O(logN)
//   따라서 총 비용은 3 * O(logN) = O(logN)
//
// Space Complexity: O(1)

int FindPivot(const vector<int>& elems) {
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

int BinarySearch(const vector<int>& elems, int lo, int hi, int key) {
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (elems[mid] < key) {
      lo = mid + 1;
    } else if (elems[mid] > key) {
      hi = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int SearchCyclicallySortedArray(const vector<int>& elems, int key) {
  if (elems.size() == 0) {
    return  -1;
  }

  int pivot = FindPivot(elems);
  if (elems[0] <= key) {
    return BinarySearch(elems, 0, pivot - 1, key);
  } else {
    return BinarySearch(elems, pivot, elems.size() - 1, key);
  }
}

// Solution #2
//   elems[mid]가 pivot의 왼쪽 또는 오른쪽에 위치하였는지에 따라 검색 영역을
//   줄여나가 보자.
//   * elems[mid] == key : return mid
//   * mid가 pivot의 왼쪽에 있는 경우(elems[lo] <= elems[mid])
//     * elems[lo] <= key < elems[mid] : left subarray를 BinarySearch()
//     * 그 외의 경우, right subarray를 SearchCyclicallySortedArray()
//   * mid가 pivot의 오른쪽(pivot 포함)에 있는 경우
//     * elems[mid] < key <= elems[hi] : right subarray를 BinarySearch()
//     * 그 외의 경우, left subarray를 SearchCyclicallySortedArray()
//
// Time Complexity: O(logN)
//
// Space Complexity: O(1)

int SearchCyclicallySortedArray2(const vector<int>& elems, int key) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (elems[mid] == key) {
      return mid;
    }
    if (elems[lo] <= elems[mid]) {
      if (key >= elems[lo] && key < elems[mid]) {
        return BinarySearch(elems, lo, mid - 1, key);
      } else {
        lo = mid + 1;
      }
    } else if (elems[mid] <= elems[hi]) {
      if (key > elems[mid] && key <= elems[hi]) {
        return BinarySearch(elems, mid + 1, hi, key);
      } else {
        hi = mid - 1;
      }
    }
  }
  return -1;
}

// Solution #3
//   잘 살펴보면 solution #2에서 BinarySearch()를 호출할 필요가 없다.
//   lo 또는 hi 값만 변경해주고 SearchCyclicallySortedArray()를 그대로
//   사용해도 문제없이 동작한다.
//
// Time Complexity: O(logN)
//
// Space Complexity: O(1)

int SearchCyclicallySortedArray3(const vector<int>& elems, int key) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (elems[mid] == key) {
      return mid;
    }
    if (elems[lo] <= elems[mid]) {
      if (key >= elems[lo] && key < elems[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    } else if (elems[mid] <= elems[hi]) {
      if (key > elems[mid] && key <= elems[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }
  return -1;
}

int main() {
{
  // Test #1.
  // elems[] = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368}
  // keys = each element, -500, 500
  // return value = 4
  cout << "Test #1" << endl;
  vector<int> elems = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
  for (int i: elems) {
    cout << SearchCyclicallySortedArray(elems, i) << ' ';
  }
  cout << endl;
  for (int i: elems) {
    cout << SearchCyclicallySortedArray2(elems, i) << ' ';
  }
  cout << endl;
  for (int i: elems) {
    cout << SearchCyclicallySortedArray3(elems, i) << ' ';
  }
  cout << endl;
}
{
  // Test #2
  // elems[] = {}
  // key = 100
  // return value = -1
  cout << "Test #2" << endl;
  vector<int> elems;
  cout << SearchCyclicallySortedArray(elems, 100) << endl;
  cout << SearchCyclicallySortedArray2(elems, 100) << endl;
  cout << SearchCyclicallySortedArray3(elems, 100) << endl;
}
  return 0;
}
