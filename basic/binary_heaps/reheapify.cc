// Given a heap that has an invalid node which breaks heap-order and its
// position, reheapify the heap correctly. Assume that the heap is max-heap.

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
// * If an node that is broken heap-order is larger than its parent,
//   swim it up (exchange the node with its parent repeatedly) until
//   heap-order is restored.
//
// * If an node is smaller than one or both of its children,
//   sink it down (exchange the node with lager child repeatedly) until
//   heap-order is restored.
//
// Time Complexity: O(lgN), N is the number of nodes in the heap.
//
// Space Complexity: O(N)

void Swim(vector<int>* heap_ptr, int pos) {
  vector<int>& heap = *heap_ptr;
  while (pos > 1 && heap[pos / 2] < heap[pos]) {
    swap(heap[pos / 2], heap[pos]);
    pos /= 2;
  }
}

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

void Reheapify(vector<int>* heap_ptr, int pos) {
  vector<int>& heap = *heap_ptr;
  if (heap[pos / 2] < heap[pos]) {
    Swim(heap_ptr, pos);
  } else if (heap[pos] < heap[2 * pos] || heap[pos] < heap[2 * pos + 1]) {
    Sink(heap_ptr, pos);
  }
}

//{{{
int main() {
{
  // Test #1
  // input = {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 100}
  // output = {dummy, 100, 14, 15, 12, 11, 10, 13, 8, 7, 6, 5, 4, 3, 2, 9}
  vector<int> heap = {-1, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 100};
  Swim(&heap, 15);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #2
  // input = {dummy, 15, 14, 13, 100, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 100, 15, 13, 14, 11, 10, 13, 8, 7, 6, 5, 4, 3, 2, 1}
  vector<int> heap = {-1, 15, 14, 13, 100, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Swim(&heap, 4);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #3
  // input = {dummy, 16, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 16, 15, 13, 12, 14, 10, 9, 8, 7, 6, 11, 4, 3, 2, 1}
  vector<int> heap = {-1, 16, 14, 13, 12, 11, 10, 9, 8, 7, 6, 15, 4, 3, 2, 1};
  Swim(&heap, 11);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #4
  // input = {dummy, 0, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 14, 12, 13, 8, 11, 10, 9, 0, 7, 6, 5, 4, 3, 2, 1}
  vector<int> heap = {-1, 0, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Sink(&heap, 1);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #5
  // input = {dummy, 0, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 14, 12, 13, 8, 11, 10, 9, 0, 7, 6, 5, 4, 3, 2, 1}
  vector<int> heap = {-1, 0, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Sink(&heap, 1);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #6
  // input = {dummy, 15, 14, 0, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 15, 14, 10, 12, 11, 4, 9, 8, 7, 6, 5, 0, 3, 2, 1}
  vector<int> heap = {-1, 15, 14, 0, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Sink(&heap, 3);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #7
  // input = {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  vector<int> heap = {-1, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Swim(&heap, 15);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #8
  // input = {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  // output = {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  vector<int> heap = {-1, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Sink(&heap, 15);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
  return 0;
}
//}}}
