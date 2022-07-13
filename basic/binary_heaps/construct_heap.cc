// Create a max heap with given integer keys.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//}}}

// Solution
// From the N/2-th node down to the first node, sink each node down.
//
// Time Complexity: O(N), N is the number of nodes in a heap.
//
// Space Complexity: O(N)

void Sink(vector<int>* heap_ptr, int pos) {
  vector<int>& heap = *heap_ptr;
  while (2 * pos < heap.size()) {
    int cand = 2 * pos;
    if (cand + 1 < heap.size() && heap[cand] < heap[cand + 1]) {
      ++cand;
    }
    if (heap[pos] >= heap[cand]) {
      break;
    }
    swap(heap[pos], heap[cand]);
    pos = cand;
  }
}

void CreateHeap(vector<int>* heap_ptr) {
  vector<int>& heap = *heap_ptr;
  for (int i = (heap.size() - 1) / 2; i >= 1; --i) {
    Sink(heap_ptr, i);
  }
}

//{{{
int main() {
{
  // Test #1
  // input: {dummy, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
  // output: {dummy, 15, 11, 14, 9, 10, 13, 7, 8, 4, 2, 5, 12, 6, 3, 1}
  vector<int> heap = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  CreateHeap(&heap);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
  return 0;
}
//}}}
