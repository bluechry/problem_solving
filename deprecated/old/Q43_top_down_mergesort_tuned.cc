// Make top-down mergesort faster using the following optimizations.
// * Use insertion sort for small subarrays.
// * Stop if already sorted.
// * Eliminate the copy to the auxiliary array.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   Q41의 top-down meresort를 아래의 기법을 사용하여 튜닝한다.
//   * Subarray의 길이가 kCufOff 이하이면 insertion sort를 수행한다.
//     Subarray의 길이가 1이 될 때까지 쪼개어 나가고 merge를 하면서
//     거꾸로 올라오는 과정은 recursive call과 array copy로 인하여
//     비용이 많이 든다. 이 비용보다는 insertion sort를 수행하는 비용이
//     더 작을 수 있다.
//
//     Selection sort를 사용할 수 있지만 insertion sort를 사용하는 이유는
//     partially sorted subarray의 경우에 비용이 O(N) 밖에 되지 않기 때문이다.
//
//   * 왼쪽 subarray의 가장 큰 값이 오른쪽 subarray의 가장 작은 값보다 작다면,
//     두 subarray들을 merge할 필요가 없다.
//
//   * Merge된 auxiliary array를 elems array로 복사하는 비용을 제거하자.
//     Auxiliary array를 elems array로 복사하는 과정을 제거하고,
//     정렬된 결과로 auxiliary array를 반환하자.
//     이렇게 구현하려면 mergesort 내에서 다시 mergesort를 호출할 때
//     elems array와 auxiiary array의 역할을 바꾸어야 한다.
//     또한 정렬 시작 전에 auxiliary array를 elems array와 동일하게 초기화해야 한다.
//
//     Mergesort(elems[], ...) {
//       aux = elems;
//       Mergesort(aux, elems, ...);
//     }
//
//     Mergesort(elems[], aux[], ...) {
//       Mergesort(aux, elems, ...);
//       Mergesort(aux, elems, ...);
//       Merge(elems, aux, ...);
//     }
//

const int kCutOff = 4;

template<typename T, typename Compare>
void InsertionSort(vector<T>* elems, Compare comp, int lo, int hi) {
  for (int i = lo + 1; i <= hi; ++i) {
    for (int j = i; j > lo; --j) {
      if (comp((*elems)[j - 1], (*elems)[j]) == false)
        swap((*elems)[j - 1], (*elems)[j]);
      else
        break;
    }
  }
}

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
}

template<typename T, typename Compare>
void Mergesort(vector<T>* elems, vector<T>* aux, Compare comp, int lo, int hi) {
  if (hi - lo + 1 <= kCutOff) {
    InsertionSort(aux, comp, lo, hi);
    return;
  }
  int mid = lo + (hi - lo) / 2;
  Mergesort(aux, elems, comp, lo, mid);
  Mergesort(aux, elems, comp, mid + 1, hi);
  if (comp((*elems)[mid], (*elems)[mid + 1]) == true)
    return;
  Merge(elems, aux, comp, lo, mid, hi);
}

template<typename T, typename Compare>
void Mergesort(vector<T>* elems, Compare comp) {
  vector<T> aux = *elems;
  Mergesort(&aux, elems, comp, 0, elems->size() - 1);
}

int main() {
  vector<int> elems = {5, 6, 7, 8, 1, 2, 3, 4, 0};
  Mergesort(&elems, less_equal<int>());
  for (auto i : elems)
    cout << i << " ";
  cout << endl;
  return 0;
}
