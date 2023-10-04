//  How would you implement a stack API using a heap?

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
//   Max heap을 사용하여 원소를 저장하되, 원소와 함께 timestamp를 저장한다.
//   Timestamp를 사용하여 heapify하면 가장 마지막에 들어온 원소가 max heap의
//   top에 위치하게 된다.
//
// Time Complexity:
//   * Push 1 element: O(logN), N is current # of elements in the heap.
//   * Pop 1 element: O(logN), N is current # of elements in the heap.
//
// Space Complexity: O(N) for max heap.

template<typename T>
class Stack {
 public:
  Stack(): global_time_(0) {
  }

  void Push(const T& elem) {
    max_heap_.emplace(Item{elem, global_time_++});
  }

  void Pop() {
    if (max_heap_.empty()) {
      throw out_of_range("stack is empty.");
    }
    max_heap_.pop();
  }

  const T& Top() const {
    if (max_heap_.empty()) {
      throw out_of_range("stack is empty.");
    }
    return max_heap_.top().value_;
  }

  bool Empty() const {
    return max_heap_.empty();
  }

 private:
  struct Item {
    T value_;
    int time_;

    bool operator<(const Item& item) const {
      return time_ < item.time_;
    }
  };

  int global_time_;
  priority_queue<Item> max_heap_;
};

int main() {
  Stack<int> s;

  // Test #1
  // Push {10, 30, 0, 50, 20}
  vector<int> elems = {10, 30, 0, 50, 20};
  for (int i: elems) {
    s.Push(i);
    cout << s.Top() << " ";
  }
  cout << endl;

  // Test #2
  // Pop all elements.
  while (!s.Empty()) {
    cout << s.Top() << " ";
    s.Pop();
  }
  cout << endl;

  // Test #3
  // Push {10, 30, 0}, Pop twice, Push {50, 20}
  s.Push(10);
  cout << s.Top() << " ";
  s.Push(30);
  cout << s.Top() << " ";
  s.Push(0);
  cout << s.Top() << " ";
  s.Pop();
  cout << s.Top() << " ";
  s.Pop();
  cout << s.Top() << " ";
  s.Push(50);
  cout << s.Top() << " ";
  s.Push(20);
  cout << s.Top() << endl;
  return 0;
}
