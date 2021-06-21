// Implement selection sort.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems[]의 각 index position i에 대하여,
//     1. elems[i + 1, N) 중의 최소값 min을 찾는다.
//     2. elems[i]와 elems[min]을 swap한다.
//
// Time complexity
//   Worst case와 best case가 따로 없다.
//   어떤 경우에도 elems[i]에 대하여 elems[i + 1, N)의 원소들을 비교해야 한다.
//   '# of comparison = (N-1) + (N-2) + ... + 1 = ~N^2/2'
//   '# of swap = N-1 = ~N'
//   따라서 time complexity는 O(N^2)이다.
//
// Space complexity
//   elems[]를 제외한 추가 memory space는 O(1)이다.
//
// Stability
//   Selection sort는 stable하지 않다.
//   예) C1 C2 B A --> A C2 B C1 --> A B C2 C1
template<typename T, typename Compare>
void SelectionSort(vector<T>* elems, Compare comp) {
  vector<T>& v = *elems;
  for (T i = 0; i < v.size() - 1; ++i) {
    T min_pos = i;
    for (T j = i + 1; j < v.size(); ++j) {
      if (comp(v[min_pos], v[j]) == false)
        min_pos = j;
    }
    swap(v[i], v[min_pos]);
  }
}

int main() {
  vector<int> v = {100, 90, 80, 30, 20, 50, 60, 100, 10, 30};
  SelectionSort(&v, less_equal<int>());
  for (auto i : v) {
    cout << i << endl;
  }
  return 0;
}
