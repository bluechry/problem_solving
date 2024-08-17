// Reverse an Array.

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

// Solution #1
// Let A is a given array and N is the number of elements in the array.
// For each i-th element in A[0 ... N/2-1], swap A[i] and A[N-1 - i].
//
// Time Complexity: O(N), N is # of elements in the array.
//
// Space Complexity: O(N)

template<typename T>
void ReverseArray(T* elems, size_t len) {
  size_t end = len / 2;
  for (size_t i = 0; i < end; ++i) {
    swap(elems[i], elems[len - 1 - i]);
  }
}

// Solution #2
// Set the two cursor on the array. Head cursor points to the first element and
// tail cursor points to the last element. The head cursor moves forward and the
// tail cursor moves backward. While the head cursor is followed by the tail
// cursor, swap the two elements that are pointed by the two cursors.
//
// Time Complexity: O(N)
//
// Space Complexity: O(N)

template<typename T>
void ReverseArray2(T* elems, size_t len) {
  size_t head = 0, tail = len - 1;
  while (head < tail) {
    swap(elems[head++], elems[tail--]);
  }
}

//{{{
int main() {
  int elems[10];
  for (int i = 0; i < 10; ++i) {
    elems[i] = i;
    cout << i << ' ';
  }
  cout << endl;

  cout << "Reverse them: " << endl;
  ReverseArray(elems, 10);
  for (auto i : elems) {
    cout << i << ' ';
  }
  cout << endl;

  cout << "Reverse them: " << endl;
  ReverseArray2(elems, 10);
  for (auto i : elems) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
//}}}
