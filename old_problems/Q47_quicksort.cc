// Implement quicksort.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   * elems[]를 random shuffle한다.
//
//   * elems[]를 pivot 원소를 기준으로,
//     elems[pivot]보다 작거나 같은 원소들을 pivot의 왼쪽에
//     elems[pivot]보다 크거나 같은 원소들을 pivot의 오른쪽에 위치시켜
//     elems[]를 partition한다.
//
//     elems[pivot]과 같은 원소들을 pivot의 왼쪽 또는 오른쪽에 몰아놓지않고
//     양옆에 위치시키는 이유는, 중복 원소가 많은 경우에도 even하게
//     partition하기 위함이다.
//     예를 들어, 모든 원소들이 동일하다고 가정하고 pivot과 같은 원소들은
//     오른쪽 subarray에 위치시킨다고 하자.
//
//     elems[] = {A, A, A, A, A, A} ==> {A}, {A, A, A, A, A}
//
//     이러한 경우에는 항상 1: n-1로 partition이 되고
//     quicksort의 time complexity가 quadratic이 되어버린다.
//
//   * Pivot을 중심으로 왼쪽 subarray와 오른쪽 subarray를 각각 quicksort한다.
//
// Time complexity
//   * Best case
//     원소들을 partition할 때마다 left, right subarray들이 이등분되는 경우이다.
//     원소들을 비교하고 교환하는 비용은 다음과 같다.
//
//     T(N) = 2 * T(N/2) + cN, T(1) = 0
//          = O(NlogN)
//
//   * Worst case
//     (Random shuffle을 하지 않아서) 원소들이 이미 내림차순 또는 오름차순으로
//     정렬된 경우이다.
//     이 경우에는 partition이 1:(N-1) 또는 (N-1):1로 쪼개어지므로
//     원소들을 비교하고 교환하는 비용은 다음과 같다.
//
//     T(N) = T(1) + T(N-1) + cN, T(1) = 0
//          = O(N^2)
//
//   * Average case
//     Random하게 배치된 원소들의 경우로 원소들을 비교하고 교환하는 비용은
//     O(NlogN)이다. 증명은 다음과 같다.
//
//     T(N) = cN + 1/N * (T(1) + T(N-1)) + 1/N * (T(2) + T(N-2)) + ... + 1/N * (T(N-1) + T(1))
//     T(1) = 0
//
//     N : partition 비용
//     1/N : i번째 원소가 pivot이 될 확률
//     T(i) + T(N-i) : i번째 원소가 pivot일 때 각 subarrary를 정렬하는 비용
//
//     T(N)           = N + 1/N * (T(1) + T(N-1)) + 1/N * (T(2) + T(N-2)) + ... + 1/N * (T(N-1) + T(1))
//     N * T(N)       = N^2 + 2 * (T(1) + T(2) + ... + T(N-1))     -- (1)
//     (N-1) * T(N-1) = (N-1)^2 + 2 * (T(1) + T(2) + ... + T(N-2)) -- (2)
//
//     (1) - (2) = N * T(N) - (N-1) * T(N-1) = (2N-1) + 2 * T(N-1)
//
//     식을 정리하면,
//     N * T(N) = (2N-1) + (N+1) * T(N-1) <= 2N + (N+1) * T(N-1)
//
//     양쪽 항을 N(N+1)로 나누면,
//     T(N) / (N+1) <= T(N-1)/N + 2/(N+1)
//
//     T(N) / (N+1) <= T(N-2)/(N-1) + 2/N + 2/(N+1)
//                   = T(N-3)/(N-2) + 2/(N-1) + 2/N + 2/(N+1)
//                   = T(1)/2 + 2/3 + 2/4 + 2/5 + ... 2/(N+1)
//                   = 2 * (1/3 + 1/4 + ... 1/(N+1))
//                  <= 2 * lnN
//
//     T(N) <= 2 * (N+1) * lnN = O(NlogN)
//
// Space complexity
//   Recursion에 필요한 stack의 깊이는 O(logN)이고,
//   partition에 사용되는 추가 공간의 크기는 O(1)이다.
//   따라서, quicksort는 in-place sort이다.

// Assume that lo < hi.
template<typename T, typename Compare>
int Partition(vector<T>* elems, Compare comp, int lo, int hi) {
  int i = lo, j = hi + 1;
  while (true) {
    // elems[lo]보다 크거나 같은 값이 나오면 멈춘다.
    while (!comp((*elems)[lo], (*elems)[++i]))
      if (i == hi) break;

    // elems[hi]보다 작거나 같은 값이 나오면 멈춘다.
    while (!comp((*elems)[--j], (*elems)[lo]))
      if (j == lo) break;

    // i와 j가 엇갈리면 멈춘다. 그렇지 않으면 i와 j의 원소를 swap한다.
    if (i >= j) break;
    swap((*elems)[i], (*elems)[j]);
  }

  // lo와 j의 원소를 swap한다. i가 아니라 j의 원소와 swap해야한다.
  // i의 원소는 그 값이 lo의 원소보다 값이 클 수 있으므로 옮겨서는 안된다.
  // j의 원소는 그 값이 lo의 원소보다 작거나 같기때문에 옮겨도 무방하다.
  swap((*elems)[lo], (*elems)[j]);
  return j;
}

template<typename T, typename Compare>
void Quicksort(vector<T>* elems, Compare comp, int lo, int hi) {
  if (lo >= hi) return;

  // Partition 후에는 pivot의 원소는 자기 자리를 찾아간다.
  // pivot 왼쪽과 오른쪽의 원소들은 각각 quicksort를 한다.
  int pivot = Partition(elems, comp, lo, hi);
  Quicksort(elems, comp, lo, pivot - 1);
  Quicksort(elems, comp, pivot + 1, hi);
}

template<typename T, typename Compare>
void Quicksort(vector<T>* elems, Compare comp) {
  // Quicksort가 성능을 발휘하기 위하여 elems[]를 random하게 shuffle한다.
  random_shuffle((*elems).begin(), (*elems).end());
  Quicksort(elems, comp, 0, elems->size() - 1);
}

int main() {
  vector<int> elems = {5, 6, 7, 8, 1, 2, 3, 4, 0};
  Quicksort(&elems, less_equal<int>());
  for (auto i : elems)
    cout << i << " ";
  cout << endl;
  return 0;
}
