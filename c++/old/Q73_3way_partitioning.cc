// Write a program that takes an array A and an index i into A, and rearranges
// the elements such that all elements less than A[i] (the "pivot") appear
// first, followed by elements equal to the pivot, followed by elements greater
// than the pivot.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution #1
//   * 두 번 scan하면서 pivot보다 작은 원소들과 큰 원소들을 모은다.
//     각 scan은 selection sort와 유사하게 동작한다.
//   * 첫 번째 scan에서는,
//     i를 0부터 N-1까지 증가시키면서 i+1부터 N-1까지 원소들 중 pivot보다 작은
//     원소를 찾아서 i 위치의 원소와 swap한다.
//   * 두 번째 scan에서는,
//     i를 N-1부터 0까지 감소시키면서 i-1부터 0까지 원소들 중 pivot보다 큰
//     원소를 찾아서 i 위치의 원소와 swap한다.
//
// Time Complexity: O(N^2)
//
// Space Complexity: O(1)

void ThreeWayPartition1(int pivot_idx, vector<int>* A_ptr) {
  if (A_ptr->empty()) {
    return;
  }

  vector<int>& A = *A_ptr;
  int pivot = A[pivot_idx];
  // Group the elements which is smaller than pivot.
  for (int i = 0; i < A.size(); ++i) {
    for (int j = i + 1; j < A.size(); ++j) {
      if (A[j] < pivot) {
        swap(A[i], A[j]);
        break;
      }
    }
  }
  // Group the elements which is larger than pivot.
  for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i) {
    for (int j = i - 1; j >= 0 && A[i] >= pivot; --j) {
      if (A[j] > pivot) {
        swap(A[i], A[j]);
        break;
      }
    }
  }
}

// Solution #2
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

void ThreeWayPartition2(int pivot_idx, vector<int>* A_ptr) {
  if (A_ptr->empty()) {
    return;
  }

  vector<int>& A = *A_ptr;
  int pivot = A[pivot_idx];
  // Group the elements which is smaller than pivot.
  int lt = 0;
  for (int i = 0; i < A.size(); ++i) {
    if (A[i] < pivot) {
      swap(A[i], A[lt++]);
    }
  }
  // Group the elements which is larger than pivot.
  int gt = A.size() - 1;
  for (int i = A.size() - 1; i >= 0; --i) {
    if (A[i] > pivot) {
      swap(A[i], A[gt--]);
    }
  }
}


// Solution #3
//   한 번 scan하는 동안 삼분할한다. Scan하는 동안 분할되는 영역은 다음과 같다.
//   * [0, lt)는 pivot보다 작은 값들의 영역
//   * (gt, N)은 pivot보다 큰 값들의 영역
//   * [lt, i)는 pivot과 같은 값들의 영역 (i는 current scan pointer)
//   * [i, gt]는 아직 분류되지 않은 영역
//
//   Scan하는 동안 다음 과정을 진행한다.
//   * A[i] < pivot 이면, swap(A[i++], A[lt++])
//   * A[i] > pivot 이면, swap(A[i], A[gt--]), must not increase i!!!
//   * A[i] == pivot, ++i
//
//   두 번째 조건에서 i를 증가시키지 않는 것에 유의한다.
//   gt 위치에 있다가 i 위치로 이동한 원소는 pivot과의 크기 비교가 된 적이
//   없기때문데 다음 턴에서 pivot과 비교가 되어야 한다.
//   따라서 i를 증가시켜서는 안 된다.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

void ThreeWayPartition3(int pivot_idx, vector<int>* A_ptr) {
  if (A_ptr->empty()) {
    return;
  }

  vector<int>& A = *A_ptr;
  int lt = 0, gt = A.size() - 1, i = 0;
  int pivot = A[pivot_idx];
  while (i <= gt) {
    if (A[i] < pivot) {
      swap(A[i++], A[lt++]);
    } else if (A[i] > pivot) {
      swap(A[i], A[gt--]);
    } else {
      ++i;
    }
  }
}

int main() {
{
  // Test #1.
  // A[] = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2}
  // return value = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2}
  vector<int> A = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2};
  ThreeWayPartition1(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;

  A = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2};
  ThreeWayPartition2(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;

  A = {1, 1, 1, 1, 0, 0, 0, 0, 2, 2, 2, 2};
  ThreeWayPartition3(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #2.
  // A[] = {1, 1, 1, 1, 0, 0, 0, 0}
  // return value = {0, 0, 0, 0, 1, 1, 1, 1}
  vector<int> a = {1, 1, 1, 1, 0, 0, 0, 0};
  ThreeWayPartition1(0, &a);
  for (int i: a) {
    cout << i << " ";
  }
  cout << endl;

  a = {1, 1, 1, 1, 0, 0, 0, 0};
  ThreeWayPartition2(0, &a);
  for (int i: a) {
    cout << i << " ";
  }
  cout << endl;

  a = {1, 1, 1, 1, 0, 0, 0, 0};
  ThreeWayPartition3(0, &a);
  for (int i: a) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #3.
  // A[] = {1, 1, 1, 1}
  // return value = {1, 1, 1, 1}
  vector<int> A = {1, 1, 1, 1};
  ThreeWayPartition1(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;

  A = {1, 1, 1, 1};
  ThreeWayPartition2(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;

  A = {1, 1, 1, 1};
  ThreeWayPartition3(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #4.
  // A[] = {}
  // return value = {}
  vector<int> A;
  ThreeWayPartition1(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;

  ThreeWayPartition2(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;

  ThreeWayPartition3(0, &A);
  for (int i: A) {
    cout << i << " ";
  }
  cout << endl;
}
  return 0;
}
