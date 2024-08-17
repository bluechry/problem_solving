// Implement a queue using a linked list.

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
// * Use a single linked list to store objects.
// * When enqueue an object, insert a new node that has the object before the
//   head node.
// * When dequeue an object, remove the tail node.
// * When examine the first node, read the head node.
// * When examine the last node, read the tail node.
//
// Time Complexity
// * Enqueue(): O(1)
// * Dequeue(): O(1)
// * Front(): O(1)
// * End(): O(1)
//
// Space Complexity: O(N), N is # of elements in the queue.

template<typename T>
class Queue {
 public:
  Queue():
    head_(nullptr),
    tail_(nullptr),
    num_elems_(0) {
  }

  void Enqueue(const T& elem) {
    if (IsEmpty()) {
      head_ = tail_ = make_shared<ListNode>(ListNode({elem, nullptr}));
    } else {
      tail_->next_ = make_shared<ListNode>(ListNode({elem, nullptr}));
      tail_ = tail_->next_;
    }
    ++num_elems_;
  }

  void Dequeue() {
    if (IsEmpty()) {
      throw length_error("queue is empty.");
    } else if (head_ == tail_) {
      head_ = tail_ = nullptr;
    } else {
      head_ = head_->next_;
    }
    --num_elems_;
  }

  const T& Front() const {
    if (IsEmpty()) {
      throw length_error("queue is empty.");
    } else {
      return head_->value_;
    }
  }

  const T& End() const {
    if (IsEmpty()) {
      throw length_error("queue is empty.");
    } else {
      return tail_->value_;
    }
  }

  size_t Size() const {
    return num_elems_;
  }

  bool IsEmpty() const {
    return (Size() == 0);
  }

 private:
  struct ListNode {
    T value_;
    shared_ptr<ListNode> next_;
  };

  shared_ptr<ListNode> head_, tail_;
  size_t num_elems_;
};

//{{{
int main() {
  Queue<int> q;

  // Test #1. enqueue 10 integers, 0 ~ 9.
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, front: %d, end: %d\n", q.Size(), q.Front(), q.End());
  }

  // Test #2. print front value while dequeueing 10 integers.
  while (q.Size()) {
    q.Dequeue();
    if (q.IsEmpty())
      printf("queue size: %ld\n", q.Size());
    else
      printf("queue size: %ld, front: %d, end: %d\n", q.Size(), q.Front(), q.End());
  }

  // Test #3. read front & end value.
  try {
    cout << q.Front() << endl;
  } catch (exception& e) {
    cout << "can't read front value: " << e.what() << endl;
  }
  try {
    cout << q.End() << endl;
  } catch (exception& e) {
    cout << "can't read end value: " << e.what() << endl;
  }

  // Test #4. dequeue an element from empty queue.
  try {
    q.Dequeue();
  } catch (exception& e) {
    cout << "can't dequeue: " << e.what() << endl;
  }
  return 0;
}
//}}}
