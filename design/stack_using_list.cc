// Implement a stack using a singly-linked list.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
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
// * Use a singly linked list to store objects.
// * When push an object, insert a new node that has the object before the
//   head node.
// * When pop an object, remove the head node.
// * When examine the top object, read the head node.
//
// Time Complexity
// * Push(): O(1)
// * Pop()/Top(): O(1)
//
// Space Complexity: O(N), N is # of objects.

template<typename T>
class Stack {
 public:
  Stack():
    head_(nullptr),
    num_elems_(0) {
  }

  void Push(const T& elem) {
    head_ = make_shared<ListNode>(ListNode({elem, head_}));
    ++num_elems_;
  }

  void Pop() {
    if (IsEmpty()) {
      throw length_error("stack is empty.");
    } else {
      head_ = head_->next_;
      --num_elems_;
    }
  }

  const T& Top() const {
    if (IsEmpty()) {
      throw length_error("stack is empty.");
    } else {
      return head_->value_;
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

  shared_ptr<ListNode> head_;
  size_t num_elems_;
};

//{{{
int main() {
  Stack<int> s;

  // Test #1. push 10 integers, 0~9.
  for (int i = 0; i < 10; ++i)
    s.Push(i);

  // Test #2. print statck top while poping all elements.
  while (!s.IsEmpty()) {
    cout << s.Top() << endl;
    s.Pop();
  }

  // Test #3. print stack top of the empty stack.
  try {
    cout << s.Top() << endl;
  } catch (exception& e) {
    cerr << "can't read empty stack: " << e.what() << endl;
  }

  // Test #4. pop an element from the empty stack.
  try {
    s.Pop();
  } catch (exception& e) {
    cerr << "can't pop from empty stack: " << e.what() << endl;
  }
  return 0;
}
//}}}
