// Implement a stack using singly linked list.

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
 public:
  Stack();
  void Push(const T& elem);
  void Pop();
  const T& Top() const;
  bool IsEmpty() const;
  int64_t Size() const;

 private:
  template<typename N>
  struct Node {
    N elem_;
    Node<N>* next_;
  };

  Node<T>* head_;
  int64_t num_elems_;
};

template<typename T>
Stack<T>::Stack():
    num_elems_(0),
    head_(nullptr) {
}

// Solution
// * 새로운 node를 만들어서 'elem'을 저장한 후 list의 head 앞에 추가한다.
// * Worst case runtime cost는,
//   '# of node accesses = O(1)'
template<typename T>
void Stack<T>::Push(const T& elem) {
  // 'new' throws 'bad_alloc' exception when memory allocation fails.
  Node<T>* node = new Node<T>();
  node->elem_ = elem;
  node->next_ = head_;
  head_ = node;
  ++num_elems_;
}

// Solution
// * List의 head를, head가 가리키는 node의 다음 node를 가리키도록 만들고,
//   기존에 head가 가리키던 node를 삭제한다.
// * Worst case runtime cost는,
//   '# of node accesses = O(1)'
template<typename T>
void Stack<T>::Pop() {
  if (IsEmpty())
    throw out_of_range("[error] stack is empty.");
  Node<T>* node = head_;
  head_ = head_->next_;
  // 'delete' throws an exception when dtor of the node throws the exception.
  delete node;
  --num_elems_;
}

template<typename T>
const T& Stack<T>::Top() const {
  if (IsEmpty())
    throw out_of_range("[error] stack is empty.");
  return head_->elem_;
}

template<typename T>
bool Stack<T>::IsEmpty() const {
  return (Size() == 0);
}

template<typename T>
int64_t Stack<T>::Size() const {
  return num_elems_;
}

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
