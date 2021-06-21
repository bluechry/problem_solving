// An inversion in array a[] is a pair of entries a[i] and a[j] such that i < j
// but a[i] > a[j]. Given an array, design a linearithmic algorithm to count the
// number of inversions.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution #1
//   For all pair of (i, j), i < j, check elems[i] > elems[j].
//
// Time Complexity: O(N^2), N is the length of elems[].
//
// Space Complexity: O(1)

template<typename T>
int CountInv(const vector<T> elems) {
  int count = 0;
  for (int i = 0; i < elems.size(); ++i) {
    for (int j = i + 1; j < elems.size(); ++j) {
      if (elems[i] > elems[j]) {
        ++count;
      }
    }
  }
  return count;
}

// Solution #2
//   Count # of inversions while mergesorting elems[].
//
// Time Complexity: O(NlogN), N is the length of elems[].
//
// Space Complexit: O(N), N is the length of the auxiliary array.

template<typename T>
int CountSplitInv(vector<T>* elems_ptr, vector<T>* aux_ptr, int lo, int mid, int hi) {
  auto& elems = *elems_ptr;
  auto& aux = *aux_ptr;

  int i = lo, j = mid + 1, k = lo;
  int count = 0;
  while (i <= mid && j <= hi) {
    if (elems[i] <= elems[j]) {
      aux[k++] = elems[i++];
    } else {
      count += mid - i + 1;
      aux[k++] = elems[j++];
    }
  }
  while (i <= mid) {
    aux[k++] = elems[i++];
  }
  while (j <= hi) {
    aux[k++] = elems[j++];
  }
  copy(&aux[lo], &aux[hi + 1], &elems[lo]);
  return count;
}

template<typename T>
int FastCountInv(vector<T>* elems_ptr, vector<T>* aux_ptr, int lo, int hi) {
  if (lo >= hi) {
    return 0;
  }
  int mid = lo + (hi - lo) / 2;
  int inv_left = FastCountInv(elems_ptr, aux_ptr, lo, mid);
  int inv_right = FastCountInv(elems_ptr, aux_ptr, mid + 1, hi);
  int inv_split = CountSplitInv(elems_ptr, aux_ptr, lo, mid, hi);
  return inv_left + inv_right + inv_split;
}

int main() {
{
  // Test #1.
  // elems[] = {5, 4, 3, 2, 1}, return value = 10
  vector<int> elems = {5, 4, 3, 2, 1};
  vector<int> aux(elems.size());
  cout << CountInv(elems) << endl;
  cout << FastCountInv(&elems, &aux, 0, elems.size() - 1) << endl;
}
{
  // Test #2.
  // elems[] = {1, 2, 3, 4, 5}, return value = 0
  vector<int> elems = {1, 2, 3, 4, 5};
  vector<int> aux(elems.size());
  cout << CountInv(elems) << endl;
  cout << FastCountInv(&elems, &aux, 0, elems.size() - 1) << endl;
}
{
  // Test #3.
  // elems[] = {1, 3, 4, 2, 5}, return value = 1
  vector<int> elems = {1, 3, 4, 2, 5};
  vector<int> aux(elems.size());
  cout << CountInv(elems) << endl;
  cout << FastCountInv(&elems, &aux, 0, elems.size() - 1) << endl;
}
  return 0;
}
