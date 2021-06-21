// Implement priority queue using binary heap.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   Heapsort는,
//   (1) 정렬할 원소들을 가지고 heap을 구축하는 과정과
//   (2) heap에서 1번 원소를 반복적으로 꺼내어 정렬하는 과정으로 구성된다.
//
//   * Heap을 구축하는 과정은 N/2번 원소부터 1번원소까지 거꾸로 진행하면서,
//     각 원소를 Sink()한다.
//     오름차순으로 정렬할 경우, max heap을 구축하고
//     내림차순으로 정렬할 경우, min heap을 구축한다.
//
//   * 원소를 정렬할 때는, 1번 원소를 heap의 마지막 원소와 swap한 후
//     1번 원소를 Sink()하는 작업을 반복한다.
//     주의할 점은 1번 원소와 마지막 원소를 swap한 후,
//     마지막 원소를 제외한 나머지 원소들만을 가지고 Sink() 해야한다.
//
// Time Complexity
//   원소를 비교하고 교환하는 연산의 횟수를 세어 time complexity를 계산한다.
//   최악의 경우는 heap이 full binary tree이면서 원소들이 이미 정렬된 경우이다.
//
//   * Heap을 구축하는 과정의 worst case time complexity는 O(N)이다.
//
//     Let N = 2^(k+1) - 1,
//     # of compares =
//       2 * (2^0 * (k - 0) + 2^1 * (k - 1) + ... + 2^(k-1) * (k - (k-1)))
//       = 2 * (k * (2^0 + 2^1 + ... + 2^(k-1)) - (2^1 * 1 + 2^2 * 2 + ... + 2^(k-1) * (k-1)))
//       = 2 * (k * (2^k - 1) - (k-1) * 2^k + 2^k - 1)
//       = 2 * (k * 2^k - k - k * 2^k + 2^k + 2^k - 1)
//       = 2 * (-k + 2^(k + 1) - 1)
//       = 2 * (N - k)
//       = 2 * (N - lg(N + 1) - 1) = ~2N = O(N)
//
//     # of swaps =
//       2^0 * (k - 0) + 2^1 * (k - 1) + ... + 2^(k-1) * (k - (k-1)), N = 2^(k+1) - 1
//       = N - lg(N + 1) - 1 = ~N = O(N)
//
//   * Heap을 정렬하는 과정의 worst case time complexity는 O(NlogN)이다.
//
//     N-1 번 swap()과 Sink()가 반복되며,
//     swap()의 비용은 O(1), Sink()의 비용은 O(logN)이다.
//     따라서 정렬에 필요한 time complexity T(N)은,
//
//     T(N) = c * (log1 + log2 + log3 + ... + log(N - 1))
//          = c * (log(N-1)!) ~ c * (N-1)log(N-1) (by stirling's approximation)
//          = O(NlogN)
//
// Space Complexity
//   원소를 저장한 heap의 크기는 O(N), 그 외의 공간은 O(1)이다.
//   따라서 heapsort는 in-place sort이다.

template<typename T, typename Compare>
void Sink(vector<T>* elems, int cur, int end, Compare comp) {
  while (2 * cur <= end) {
    int next = 2 * cur;
    if (next < end && comp((*elems)[next], (*elems)[next + 1]))
      ++next;
    if (!comp((*elems)[cur], (*elems)[next]))
      break;
    swap((*elems)[cur], (*elems)[next]);
    cur = next;
  }
}

template<typename T, typename Compare>
void Heapsort(vector<T>* elems, Compare comp) {
  // Heapify the elems.
  int end = elems->size() - 1;
  for (int i = end; i >= 1; --i)
    Sink(elems, i, end, comp);

  // Sortdown the elems.
  for (int i = end; i > 1; --i) {
    swap((*elems)[1], (*elems)[i]);
    Sink(elems, 1, i - 1, comp);
  }
}

int main() {
  // '-1' is dummy element to implement binary heap easily.
  vector<int> elems = {-1, 5, 6, 7, 8, 1, 2, 3, 3, 3, 4, 5, 5, 0};
  cout << "Before sorting..." << '\n';
  for (int i = 1; i < elems.size(); ++i)
    cout << elems[i] << " ";
  cout << endl;

  Heapsort(&elems, less<int>());
  cout << "After sorting..." << '\n';
  for (int i = 1; i < elems.size(); ++i)
    cout << elems[i] << " ";
  cout << endl;
  return 0;
}
