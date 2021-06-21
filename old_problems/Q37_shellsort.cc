// Implement shellsort.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   h = 1, 4, 13, 40, ..., 3*x+1 < N 에 대하여, 큰 h 값에서 작은 h 값 순으로
//   elems를 h-sort 한다.
//
//   h-sort는 elems[h] ~ elems[n-1] 까지의 원소들에 대하여 stride가 h인
//   inserttion sort를 수행한다.
//
// Time complexity
//   h 값의 수열로 3*x+1을 사용하는 경우 O(N^1.5)가 된다.
//   증명은 어려우니 그렇다고만 알아두자.
template<typename T, typename Compare>
void Shellsort(vector<T>* elems, Compare comp) {
  vector<T>& v = *elems;
  int h = 1;
  while (h < v.size() / 3) {
    h = 3 * h + 1;
  }
  while (h >= 1) {
    for (int i = h; i < v.size(); ++i) {
      for (int j = i; j >= h; j -= h) {
        if (comp(v[j - h], v[j]) == false) {
          swap(v[j - h], v[j]);
        } else {
          break;
        }
      }
    }
    h /= 3;
  }
}

int main() {
  vector<int> v = {100, 90, 80, 30, 20, 50, 60, 100, 10, 30};
  Shellsort(&v, less_equal<int>());
  for (auto i : v) {
    cout << i << endl;
  }
  return 0;
}
