// Given a max heap, insert a key and remove maximum key.

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

// Solution of Insert()
// Add a new node at the end of a heap and swim it up until heap order is
// restored.
//
// Time Complexity: O(logN), N is the number of nodes in a heap.
//
// Space Complexity: O(N)

void Swim(vector<int>* heap_ptr, int pos) {
  vector<int>& heap = *heap_ptr;
  while (pos > 1 && heap[pos / 2] < heap[pos]) {
    swap(heap[pos / 2], heap[pos]);
    pos /= 2;
  }
}

void Insert(vector<int>* heap_ptr, int key) {
  vector<int>& heap = *heap_ptr;
  heap.push_back(key);
  Swim(heap_ptr, heap.size() - 1);
}

// Solution of DeleteMax()
// Exchange root with the last node and sink it down until heap order is
// restored.
//
// Time Complexity: O(logN), N is the number of nodes in a heap.
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

int DeleteMax(vector<int>* heap_ptr) {
  vector<int>& heap = *heap_ptr;
  int result = heap[1];
  swap(heap[1], heap[heap.size() - 1]);
  heap.pop_back();
  Sink(heap_ptr, 1);
  return result;
}

//{{{
int main() {
{
  // Test #1
  // input: {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  //         insert 16
  // output: {dummy, 16, 15, 13, 14, 11, 10, 9, 12, 7, 6, 5, 4, 3, 2, 1, 8}
  vector<int> heap = {-1, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  Insert(&heap, 16);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
{
  // Test #2
  // input: {dummy, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 16
  //         delete 15
  // output: {dummy, 14, 12, 13, 8, 11, 10, 9, 1, 7, 6, 5, 4, 3, 2}
  vector<int> heap = {-1, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int max = DeleteMax(&heap);
  for (int i = 1; i < heap.size(); ++i) {
    cout << heap[i] << ' ';
  }
  cout << endl;
}
  return 0;
}
//}}}
