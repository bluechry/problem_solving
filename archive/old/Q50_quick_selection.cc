// Given an array of N items, find a k-th smallest item.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   Quicksort의 partition 기법을 사용하여 pivot 원소의 위치를 알아내고,
//   pivot 원소의 위치를 k와 비교하여 left subarray 또는 right subarray에서
//   k번째 원소를 찾는다.
//
//   lo = 0, hi = size() -1;
//   while (lo < hi) {
//     pivot = Partition(elems, lo, hi);
//     if (pivot > k) hi = pivot - 1;
//     else if (pivot < k) lo = pivot + 1;
//     else return elems[k];
//   }
//   return elems[k];
//
// Time Complexity
//   * Best case
//     Partition을 한 번 수행해서 k번째 원소를 찾는 경우이다.
//     따라서 time complexity는 O(N)이다.
//
//   * Worst case
//     이미 정렬된 원소들 중에서 마지막 원소를 찾는 경우이다.
//     마지막 원소를 찾을 때까지 매번 1:(n-1)로 partition하게 된다.
//
//     T(N) = N + T(N-1), T(1) = 0
//          = N + (N-1) + (N-2) + ... + 2 + T(1) = ~N^2/2 = O(N^2)
//
//     따라서 time complexity는 O(N^2)이다.
//
//     Random shuffle을 통하여 worst case를 피할 수 있다.
//
//   * Average case
//     T(N)         = N-1 + T(1)/N + T(2)/N + T(3)/N + ... + T(N-1)/N
//     N*T(N)       = N(N-1) + T(1) + T(2) + ... + T(N-1)
//     (N-1)*T(N-1) = (N-1)(N-2) + T(1) + T(2) + ... + T(N-2)
//
//     N*T(N) - (N-1)*T(N-1) = N(N-1) - (N-1)(N-2) + T(N-1)
//                           = 2N - 2 + T(N-1)
//     N*T(N) - N*T(N-1) = 2N - 2
//     T(N) = T(N-1) + 2 - 2/N <= T(N-1) + 2
//
//     Let T(N) = T(N-1) + 2,
//     T(N) = T(N-1) + 2 = T(N-2) + 2 + 2 = ... = T(1) + 2 * (N-1) = O(N)
//
// Space Complexity
//   Function argument들을 저장하기 위한 공간, 지역 변수를 저장하는 공간 외에
//   추가 공간이 필요가 없다.
//   따라서 space complexity는 O(1)이다.

template<typename T, typename Compare>
int Partition(vector<T>* elems, Compare comp, int lo, int hi) {
  int i = lo, j = hi + 1;
  while (true) {
    while (!comp((*elems)[lo], (*elems)[++i]))
      if (i == hi) break;
    while (!comp((*elems)[--j], (*elems)[lo]))
      if (j == lo) break;
    if (i >= j) break;
    swap((*elems)[i], (*elems)[j]);
  }
  swap((*elems)[lo], (*elems)[j]);
  return j;
}

template<typename T, typename Compare>
T QuickSelect(vector<T>* elems, Compare comp, int k) {
  random_shuffle(elems->begin(), elems->end());

  int lo = 0, hi = elems->size() - 1;
  while (lo < hi) {
    int pivot = Partition(elems, comp, lo, hi);
    if (pivot > k) hi = pivot - 1;
    else if (pivot < k) lo = pivot + 1;
    else return (*elems)[k];
  }
  return (*elems)[k];
}

// Solution2
//   Three-way partitioning을 사용하여 해결하자.
//   Time complexity는 그대로이지만 중복된 원소들이 대다수인 경우에
//   좀 더 빠르게 k번째 원소를 찾을 수 있다.

template<typename T>
struct Compare {
  int operator()(const T& lhs, const T& rhs) {
    if (lhs < rhs) return -1;
    else if (lhs > rhs) return 1;
    else return 0;
  }
};

template<typename T, typename Compare>
void ThreeWayPartition(vector<T>* elems, Compare comp, int lo, int hi, int* lt, int* gt) {
  *lt = lo;
  *gt = hi;
  T v = (*elems)[lo];
  int i = lo;
  while (i <= *gt) {
    int cmp = comp((*elems)[i], v);
    if (cmp < 0)
      swap((*elems)[(*lt)++], (*elems)[i++]);
    else if (cmp > 0)
      swap((*elems)[(*gt)--], (*elems)[i]);
    else
      ++i;
  }
}

template<typename T, typename Compare>
T QuickSelect2(vector<T>* elems, Compare comp, int k) {
  random_shuffle(elems->begin(), elems->end());

  int lo = 0, hi = elems->size() - 1;
  while (lo < hi) {
    int lt, gt;
    ThreeWayPartition(elems, comp, lo, hi, &lt, &gt);
    if (k < lt) hi = lt - 1;
    else if (k > gt) lo = gt + 1;
    else return (*elems)[k];
  }
  return (*elems)[k];
}

int main() {
  vector<int> elems = {5, 6, 7, 8, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 0};
  for (auto i: elems)
    cout << i << " ";
  cout << endl;

  cout << '\n';
  cout << "Solution #1" << endl;
  for (int k = 0; k < elems.size(); ++k) {
    int val = QuickSelect(&elems, less_equal<int>(), k);
    printf("%d-th element: %d\n", k, val);
  }

  cout << '\n';
  cout << "Solution #2" << endl;
  for (int k = 0; k < elems.size(); ++k) {
    int val = QuickSelect2(&elems, Compare<int>(), k);
    printf("%d-th element: %d\n", k, val);
  }
  return 0;
}
