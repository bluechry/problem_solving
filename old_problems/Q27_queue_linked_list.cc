// Implement a queue using singly-linked list.

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
 public:
  Queue();
  void Enqueue(const T& elem);
  void Dequeue();
  const T& Front() const;
  const T& End() const;
  int64_t Size() const;
  bool Empty() const;

 private:
  template<typename N>
  struct Node {
    N elem_;
    Node<N>* next_;
  };
  Node<T>* head_;
  Node<T>* tail_;
  int64_t num_elems_;
};

template<typename T>
Queue<T>::Queue():
    head_(nullptr),
    tail_(nullptr),
    num_elems_(0) {
}

// Solution
// * 새로운 node를 생성하고 'elem'을 저장한 후 tail 뒤에 추가한다.
//   이 때 tail이 nullptr인지 확인해야한다.
// * Worst case runtime cost는,
//   '# of node accesses = O(1)'
template<typename T>
void Queue<T>::Enqueue(const T& elem) {
  Node<T>* n = new Node<T>();
  n->elem_ = elem;
  n->next_ = nullptr;
  if (tail_ == nullptr) {
    // case #1. empty queue
    head_ = tail_ = n;
  } else {
    // case #2. not empty queue
    tail_->next_ = n;
    tail_ = n;
  }
  ++num_elems_;
}

// Solution
// * head가 가리키는 node를 삭제하고, head를 head가 가리켰던 node로 이동한다.
//   * head가 nullptr인지 확인해야 한다.
//   * element가 1개인 경우에는 head 뿐만 아니라 tail도 nullptr로 수정되어야 한다.
// * Worst case runtime cost는,
//   '# of node accesses = O(1)'
template<typename T>
void Queue<T>::Dequeue() {
  if (head_ == nullptr) {
    // case #1. empty queue
    throw out_of_range("[error] queue is empty.");
  } else if (head_ == tail_) {
    // case #2. queue size == 1
    delete head_;
    head_ = tail_ = nullptr;
  } else {
    // case #3. queue size >= 2
    Node<T>* temp = head_;
    head_ = head_->next_;
    delete temp;
  }
  --num_elems_;
}

template<typename T>
const T& Queue<T>::Front() const {
  if (head_ == nullptr) {
    throw out_of_range("[error] queue is empty.");
  }
  return head_->elem_;
}

template<typename T>
const T& Queue<T>::End() const {
  if (tail_ == nullptr) {
    throw out_of_range("[error] queue is empty.");
  }
  return tail_->elem_;
}

template<typename T>
int64_t Queue<T>::Size() const {
  return num_elems_;
}

template<typename T>
bool Queue<T>::Empty() const {
  return (Size() == 0);
}

int main() {
  Queue<int> q;

  // Test #1. enqueue 10 integers, 0 ~ 9.
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, front: %ld, end: %ld\n", q.Size(), q.Front(), q.End());
  }

  // Test #2. print front value while dequeueing 10 integers.
  while (q.Size()) {
    q.Dequeue();
    if (q.Empty())
      printf("queue size: %ld\n", q.Size());
    else
      printf("queue size: %ld, front: %ld, end: %ld\n", q.Size(), q.Front(), q.End());
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
