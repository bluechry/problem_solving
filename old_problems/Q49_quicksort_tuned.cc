// Make quicksort(solution of Q48) faster using the following optimizations.
//  * Insertion sort small subarrays.
//  * Median of 3-samples.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   * Subarray의 크기가 kCutOff 이하이면 insertion sort를 수행한다.
//   * Median of 3-samples를 사용하여 partitioning item을 선정한다.
//     원래는 subarray에서 random하게 세 개의 원소를 골라야하지만,
//     이미subarray가 random shuffle된 상태이므로
//     'lo', 'hi', 'lo + (hi - lo) / 2' 위치에 있는 원소들 중에서 median을
//     찾는다.
//
//     MedianOfThree(elems[], i, j, k) {
//       if (elems[i] <= elems[j]) {
//         if (elems[k] <= elems[i]) return i;
//         else if (elems[k] >= elems[j]) return j;
//         else return k;
//       } else {  // elems[j] < elems[i]
//         if (elems[k] <= elems[j]) return j;
//         else if (elems[k] >= elems[i]) return i;
//         else return k;
//       }
//     }
//
// Time complexity와 space complexity는 Q48과 동일하다.
//

const int kCutOff = 4;

template<typename T>
struct Compare {
  int operator()(const T& lhs, const T& rhs) {
    if (lhs < rhs)
      return -1;
    else if (lhs > rhs)
      return 1;
    else
      return 0;
  }
};

template<typename T, typename Compare>
void InsertionSort(vector<T>* elems, Compare comp, int lo, int hi) {
  for (int i = lo + 1; i <= hi; ++i) {
    for (int j = i; j > 0; --j) {
      if (comp((*elems)[j - 1], (*elems)[j]) > 0)
        swap((*elems)[j - 1], (*elems)[j]);
      else
        break;
    }
  }
}

template<typename T>
int MedianOfThree(const vector<T>& elems, int i, int j, int k) {
  if (elems[i] <= elems[j]) {
    if (elems[k] <= elems[i])
      return i;
    else if (elems[k] >= elems[j])
      return j;
    else
      return k;
  } else {  // elems[j] < elems[i]
    if (elems[k] <= elems[j])
      return j;
    else if (elems[k] >= elems[i])
      return i;
    else
      return k;
  }
}

template<typename T, typename Compare>
void ThreeWayPartition(vector<T>* elems, Compare comp, int lo, int hi, int* lt, int* gt) {
  *lt = lo;
  *gt = hi;
  T pivot = (*elems)[lo];
  int i = lo;
  while (i <= *gt) {
    int cmp = comp((*elems)[i], pivot);
    if (cmp < 0)
      swap((*elems)[(*lt)++], (*elems)[i++]);
    else if (cmp > 0)
      swap((*elems)[(*gt)--], (*elems)[i]);
    else
      ++i;
  }
}

template<typename T, typename Compare>
void Quicksort(vector<T>* elems, Compare comp, int lo, int hi) {
  if (hi - lo + 1 <= kCutOff) {
    InsertionSort(elems, comp, lo, hi);
    return;
  }

  int pivot = MedianOfThree((*elems), lo, hi, lo + (hi - lo) / 2);
  swap((*elems)[lo], (*elems)[pivot]);

  int lt, gt;
  ThreeWayPartition(elems, comp, lo, hi, &lt, &gt);
  Quicksort(elems, comp, lo, lt - 1);
  Quicksort(elems, comp, gt + 1, hi);
}

template<typename T, typename Compare>
void Quicksort(vector<T>* elems, Compare comp) {
  random_shuffle(elems->begin(), elems->end());
  Quicksort(elems, comp, 0, elems->size() - 1);
}

int main() {
  vector<int> elems = {5, 6, 7, 8, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 0};
  Quicksort(&elems, Compare<int>());

  for (auto i : elems)
    cout << i << " ";
  cout << endl;
  return 0;
}
