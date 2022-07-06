// Implement quicksort using 3-way partitioning

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems[]를 partition할 때 pivot 원소보다 작은 값과 큰 값 그리고
//   pivot 원소와 같은 값으로 삼분할한다.
//
//   분할된 영역을 나타내기 위한 변수 lt와 gt를 둔다.
//   lt는 pivot 원소보다 작은 원소들의 마지막 원소의 다음 원소를 가리킨다.
//   gt는 pivot 원소보다 큰 원소들의 첫번째 원소의 이전 원소를 가리킨다.
//   (즉, lt는 pivot 원소와 같은 원소들의 첫번째 원소를 가리키고,
//    gt는 pivot 원소와 같은 원소들의 마지막 원소를 가리킨다.)
//
//   lt = lo, gt = hi;  // lt는 lo부터 시작해서 증가, gt는 hi부터 시작해서 감소
//   v = elems[lo];  // pivot 원소는 lo 위치의 원소로 지정
//   i = lo;  // lo부터 원소 하나씩 스캔
//
//   while (i <= gt) {
//     if (elems[i] < v)
//       // lt와 i를 모두 증가.
//       // lt가 가리키던 원소는 이미 v와 비교되었으므로
//       // i의 위치로 옮겨온 후 다시 v와 비교할 필요가 없다.
//       swap(elems[i++], elems[lt++]);
//     else if (elems[i] > v)
//       // gt만 감소.
//       // gt가 가리키던 원소는 v와 비교된 적이 없으므로
//       // i의 위치로 옮겨온 후 다음 turn에서 v와 비교해야한다.
//       // 따라서, i는 증가시키지 않는다.
//       swap(elems[i], elems[gt--]);
//   }
//
// Time Complexity
//   * NlgN when all distinct.
//   * Linear when only a constant number of distinct elements.
//
// Space Complexity
//   Basic quicksort와 동일하다.
//

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
void Quicksort(vector<T>* elems, Compare comp, int lo, int hi) {
  if (lo >= hi) return;
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
