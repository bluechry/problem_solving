// Implement top-down mergesort.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems를 절반으로 쪼개어 왼쪽, 오른쪽 subarray를 각각 mergesort한 후,
//   두 subarray를 하나의 array로 merge한다.
//   이 작업을 각 subarray에 대해서도 동일하게 수행하여 정렬한다.
//
// Time complexity
//   Cost model은 '# of comparisons', '# of array accesses'으로 한다.
//   Mergesort에서 cost가 발생하는 부분은 Merge() 함수이며,
//   '# of comparisons' + '# of array accesses' <= cN 이다.
//
//   N = 2^k라고 가정하면,
//   'T(N) = 2 * T(N/2) + cN, T(1) = 0'
//
//   * Recurrence relation을 전개하면,
//     T(2^k) = 2 * T(2^(k-1)) + cN
//            = 2 * (2 * T(2^(k-2)) + cN/2) + cN = 2^2 * T(2^(k-2)) + 2 * cN
//            = 2^k * T(2^0) + k * cN
//            = k * cN
//            = cNlgN = O(NlogN)
//
//   * Master theorem에 의하여,
//     T(N) = NlgN = O(NlogN)
//
// Space complexity
//   두 subarray를 merge하는 과정에서 auxiliary array가 필요하다.
//   Auxiliary array의 크기는 원래 array의 크기와 동일해야한다.
//   따라서, S(N) = N = O(N)
//
// Stability
//   두 subarray를 merge하는 과정에서 두 subarray에서 비교가 되는 값이 같으면,
//   왼쪽 subarray의 값을 먼저 선택하므로 stable하게 정렬된다.

template<typename T, typename Compare>
void Merge(vector<T>* elems, vector<T>* aux, Compare comp, int lo, int mid, int hi) {
  int i = lo, j = mid + 1, k = lo;
  while (i <= mid && j <= hi) {
    if (comp((*elems)[i], (*elems)[j]) == true)
      (*aux)[k++] = (*elems)[i++];
    else
      (*aux)[k++] = (*elems)[j++];
  }
  while (i <= mid)
    (*aux)[k++] = (*elems)[i++];
  while (j <= hi)
    (*aux)[k++] = (*elems)[j++];
  copy(&(*aux)[lo], &(*aux)[hi + 1], &(*elems)[lo]);
}

template<typename T, typename Compare>
void Mergesort(vector<T>* elems, vector<T>* aux, Compare comp, int lo, int hi) {
  if (lo >= hi)
    return;
  int mid = lo + (hi - lo) / 2;
  Mergesort(elems, aux, comp, lo, mid);
  Mergesort(elems, aux, comp, mid + 1, hi);
  Merge(elems, aux, comp, lo, mid, hi);
}

template<typename T, typename Compare>
void Mergesort(vector<T>* elems, Compare comp) {
  vector<T> aux((*elems).size());
  Mergesort(elems, &aux, comp, 0, (*elems).size() - 1);
}

int main() {
  vector<int> elems = {5, 6, 7, 8, 1, 2, 3, 4, 0};
  Mergesort(&elems, less_equal<int>());
  for (auto i : elems)
    cout << i << " ";
  cout << endl;
  return 0;
}
