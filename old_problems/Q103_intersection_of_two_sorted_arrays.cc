// Write a program which takes as input two sorted arrays, and returns a new
// array containing elements that are present in both of the input arrays.
// The input arrays may have duplicate entries, but the returned array should
// be free of duplicates.
// For example, the input is <2, 3, 3, 5, 5, 6, 7, 7, 8, 12> and
// <5, 5, 6, 8, 8, 9, 10, 10>, your output should be <5, 6, 8>.
// You may assume that the two sorted arrays are not empty.

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
//   주어진 두 배열을 각각 A[], B[]라고 하자. A[]의 모든 원소들에 대해서
//   B[]에 동일한 원소가 존재하는지 확인한다. 단, A[a - 1] == A[a]인 경우
//   B[]에서 찾지않고 skip한다.
//
// Time Complexity: O(N * M), N = |A|, M = |B|
//
// Space Complexity: O(1)

vector<int> FindIntersection(const vector<int>& A, const vector<int>& B) {
  vector<int> intersection;
  for (int i = 0; i < A.size(); ++i) {
    if (i == 0 || A[i - 1] != A[i]) {
      for (int b: B) {
        if (A[i] == b) {
          intersection.emplace_back(b);
          break;
        }
      }
    }
  }
  return intersection;
}

// Solution #2
//   A[]와 B[] 배열중에서 긴 배열을 outer[], 짧은 배열을 inner[]라고 하자.
//   outer[]의 모든 원소들에 대하여 inner[] 배열에 존재하는지 binary search를
//   사용하여 확인한다.
//
// Time Complexity: O(NlogM), N = |outer|, M = |inner|
//
// Space Complexity: O(1)

vector<int> FindIntersection2(const vector<int>& A, const vector<int>& B) {
  vector<int> intersection;
  for (int i = 0; i < A.size(); ++i) {
    if (i == 0 || A[i - 1] != A[i]) {
      if (binary_search(B.begin(), B.end(), A[i])) {
        intersection.emplace_back(A[i]);
      }
    }
  }
  return intersection;
}

// Solution #3
//   Mergesort의 merge() 함수를 응용하여 두 배열의 intersection을 찾는다.
//   * A[a]와 B[b]를 비교하여 A[a] > B[b] 이면 b를 증가시키고,
//     A[a] < B[b]이면 a를 증가시킨다.
//   * A[a]와 B[b]가 같으면 결과 배열에 A[a]를 추가한다.
//     이때 A[a]와 A[a - 1]이 같다면 A[a]에 추가하지 않고 skip한다.
//
// Time Complexity: O(N + M), N = |A|, M  = |B|
//
// Space Complexity: O(K), K <= min(N, M)

vector<int> FindIntersection3(const vector<int>& A, const vector<int>& B) {
  vector<int> intersection;
  int a = 0, b = 0;
  while (a < A.size() && b < B.size()) {
    if (A[a] < B[b]) {
      ++a;
    } else if (A[a] > B[b]) {
      ++b;
    } else if (a == 0 || A[a - 1] != A[a]) {  // A[a] == B[b]
      intersection.emplace_back(A[a]);
      ++a, ++b;
    } else {
      ++a, ++b;
    }
  }
  return intersection;
}

int main() {
{
  // Test #1.
  // A[] = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12}
  // B[] = {5, 5, 6, 8, 8, 9, 10, 10}
  // return value = {5, 6, 8}
  vector<int> A = {2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
  vector<int> B = {5, 5, 6, 8, 8, 9, 10, 10};
  vector<int> intersection = FindIntersection(A, B);
  for (int i: intersection) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> intersection2 = FindIntersection2(A, B);
  for (int i: intersection2) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> intersection3 = FindIntersection3(A, B);
  for (int i: intersection3) {
    cout << i << ' ';
  }
  cout << endl;
}
  return 0;
}
