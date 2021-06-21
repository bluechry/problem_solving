// Write a program which takes as input a very long sequence of numbers and
// prints the numbers in sorted order. Each number is at most k away from its
// correctly sorted position. (Such an array is sometimes referred to as being
// k-sorted.)
// For example, no number in the sequence <3, -1, 2, 6, 4, 5, 8> is more than
// 2 away from its final sorted position.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   첫번째 원소를 찾으려면 elems[0]~elems[k] 까지 총 k + 1 개의 원소들을
//   확인해야한다. elems[0]가 정해지면, elems[1]~elems[k+1]까지 다시 k + 1 개의
//   원소들을 확인해야한다. 이 과정을 elems[0] 부터 elems[n -1] 까지의 모든
//   원소들에 대하여 수행한다.
//
//   크기가 k + 1인 min heap을 사용하여 다음과 같이 해결할 수 있다.
//   1. elems[0] ~ elems[k] 까지 원소들을 min heap에 삽입한다.
//   2. min value를 꺼내서 result vector에 삽입한다.
//   3. elems[k + 1]를 min heap에 삽입한다.
//   4. 2~3 과정을 elems[n - 1]까지 반복한다.
//   5. min heap에 남은 모든 원소들을 pop하여 result vector에 삽입한다.
//
// Time Complexity: O(Nlogk), N is # of elements.
//
// Space Complexity: O(k), k is size of the min heap.

vector<int> SortKSortedArray(vector<int>* elems_ptr, int k) {
  priority_queue<int, vector<int>, greater<int>> min_heap;
  vector<int>& elems = *elems_ptr;

  // Create initial min heap.
  for (int i = 0; i < elems.size() && i <= k; ++i) {
    min_heap.emplace(elems[i]);
  }

  // Sort elements.
  vector<int> result;
  for (int i = k + 1; i < elems.size(); ++i) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
    min_heap.emplace(elems[i]);
  }
  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
  }
  return result;
}

int main() {
{
  // Test #1.
  // elems[] = {3, -1, 2, 6, 4, 5, 8}
  // result[] = {-1, 2, 3, 4, 5, 6, 8}
  vector<int> elems = {3, -1, 2, 6, 4, 5, 8};
  vector<int> result = SortKSortedArray(&elems, 2);
  for (int i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
{
  // Test #2.
  // elems[] = {3, -1}
  // result[] = {-1, 3}
  vector<int> elems = {3, -1};
  vector<int> result = SortKSortedArray(&elems, 2);
  for (int i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
{
  // Test #3.
  // elems[] = {}
  // result[] = {}
  vector<int> elems;
  vector<int> result = SortKSortedArray(&elems, 2);
  for (int i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
  return 0;
}
