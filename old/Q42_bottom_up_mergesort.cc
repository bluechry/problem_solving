// Implement bottom-up mergesort.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems의 크기를 2^k라고 가정하자.
//   elems의 원소들을 2^i 개씩 짝지어서 merge하는 것을 0부터 k-1까지의 i에
//   대하여 반복한다.
//
// Time Complexity
//   각 i에 대하여 O(N)의 merge cost가 발생한다.
//   i는 0부터 k-1까지 총 k개의 값을 가지며, k = lgN과 같다.
//   따라서, mergesort의 time complexity는 O(NlogN)이다.
//
// Space Complexity
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
void Mergesort(vector<T>* elems, Compare comp) {
  int n = elems->size();
  vector<T> aux(n);
  for (int size = 1; size < n; size *= 2) {
    for (int lo = 0; lo + size < n; lo += 2 * size) {
      int mid = lo + size - 1;
      int hi = min(lo + 2 * size - 1, n - 1);
      Merge(elems, &aux, comp, lo, mid, hi);
    }
  }
}

int main() {
  vector<int> elems = {5, 6, 7, 8, 1, 2, 3, 4, 0};
  Mergesort(&elems, less_equal<int>());
  for (auto i : elems)
    cout << i << " ";
  cout << endl;
  return 0;
}
