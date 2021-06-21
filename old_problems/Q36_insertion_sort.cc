// Implement insertion sort.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems[]의 각 array index i, i>=1에 대하여,
//     * elems[i]와 elems[i-1], elems[i-2], ..., elems[0]를 비교한다.
//     * 비교를 하면서 elems[i] < elems[i-#]이면 두 값을 swap하고,
//       elems[i] >= elems[i-#]이면 비교를 멈춘다.
//
// Worst case time complexity
//   원소들이 역순으로 정렬된 경우가 worst case이다.
//   각 elems[i]에 대하여 elems[0, i-1]의 원소들과 비교하고 swap해야한다.
//   '# of comparison = (1 + 2 + ... + N-1) = ~N^2/2'
//   '# of swap = (1 + 2 + ... + N-1) = ~N^2/2'
//   따라서 worst case time complexity는 O(N^2)이다.
//
// Best case time complexity
//   원소들이 이미 정렬된 경우가 best case이다.
//   각 elems[i]에 대하여 elems[i-1]과 한 번만 비교하고 swap은 일어나지 않는다.
//   '# of comparison = N-1 = ~N'
//   '# of swap = 0'
//   따라서 best case time complexity는 O(N)이다.
//
// Average case time complexity
//   원소들이 random order로 배치된 경우이다.
//   각 elems[i]에 대하여 1/2 * elems[0, i-1]의 원소들과 비교하고 swap한다.
//   '# of comparison = 1/2 * (1 + 2 + ... + N-1) = ~N^2/4'
//   '# of swap = 1/2 * (1 + 2 + ... + N-1) = ~N^2/4'
//   따라서 average case time comlexity는 O(N^2)이다.
//
// Space complexity
//   elems[]를 제외한 추가 memory space는 O(1)이다.
//
// Stability
//   Insertion sort는 stable하다.
//   각 elems[i]에 대하여 elems[j](j<i)가 같으면 swap을 하지않으므로
//   같은 값을 가지면서 뒤에 존재하는 원소가 앞으로 나가는 일은 없다.
template<typename T, typename Compare>
void InsertionSort(vector<T>* elems, Compare comp) {
  vector<T>& v = *elems;
  for (int i = 1; i < v.size(); ++i) {
    for (int j = i; j > 0; --j) {
      if (comp(v[j - 1], v[j]) == false)
        swap(v[j - 1], v[j]);
      else
        break;
    }
  }
}

int main() {
  vector<int> v = {100, 90, 80, 30, 20, 50, 60, 100, 10, 30};
  InsertionSort(&v, less_equal<int>());
  for (auto i : v) {
    cout << i << endl;
  }
  return 0;
}
