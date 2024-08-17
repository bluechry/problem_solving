// Implement queue using an array.
// Assume that the queue is resizable.

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
 public:
  Queue(int64_t capacity);
  ~Queue();
  void Enqueue(const T& elem);
  void Dequeue();
  const T& Front() const;
  const T& End() const;
  int64_t Size() const;
  int64_t Capacity() const;
  bool IsEmpty() const;
  bool IsFull() const;

 private:
  T* elems_;
  int64_t head_;
  int64_t tail_;
  int64_t capacity_;
};

template<typename T>
Queue<T>::Queue(int64_t capacity):
    elems_(new T[capacity + 1]),
    head_(0),
    tail_(0),
    capacity_(capacity + 1) {  // 빈 queue와 꽉 찬 queue를 구분하기 위하여 빈 공간을 추가한다.
  if (capacity <= 0) {
    throw bad_alloc();
  }
}

template<typename T>
Queue<T>::~Queue() {
  delete elems_;
}

// Solution
// * 배열로 circular queue를 구현한다.
//   * 'tail_ = (tail_ + 1) % capacity_'
//   * '(tail_ + 1) % capacity_ == head_' 이면 full queue.
//   * 꽉 찬 queue에서 tail_과 head_ 사이에는 한 개의 빈 공간이 존재.
// * Queue가 꽉 차면 queue의 크기를 두 배로 증가시킨다.
// * Worst case는 enqueue시에 queue가 두 배로 증가하는 경우이다.
//   Worst case runtime cost = '# of array accesses = O(N)'
// * Amortized runtime cost는 O(1)이다.
template<typename T>
void Queue<T>::Enqueue(const T& elem) {
  if (IsFull()) {
    // if queue is full, double the queue capacity.
    int64_t new_capacity = (capacity_ - 1) * 2 + 1;
    T* new_elems = new T[new_capacity];
    int64_t count = 0;
    // for 문의 종료 조건을 'i < tail_' 이라고 쓰면 안된다.
    // tail_ < head_인 경우를 처리할 수 없게 된다.
    for (int64_t i = head_; i != tail_; i = (i + 1) % capacity_) {
      new_elems[count++] = elems_[i];
    }
    delete [] elems_;
    elems_ = new_elems;
    head_ = 0;
    tail_ = count;
    capacity_ = new_capacity;
  }
  // destroy the element at tail_ position before overwrite it.
  elems_[tail_].~T();
  elems_[tail_] = elem;
  tail_ = (tail_ + 1) % capacity_;
}

// Solution
// * 배열로 circular queue를 구현한다.
//   * 'head_ = (head_ + 1) % capacity_'
//   * 'head_ == tail_' 이면 empty queue.
// * Queue가 1/4 차면 queue의 크기를 절반으로 줄인다.
// * Worst case는 enqueue시에 queue가 절반으로 줄어드는 경우이다.
//   Worst case runtime cost = '# of array accesses = O(N)'
// * Amortized runtime cost는 O(1)이다.
template<typename T>
void Queue<T>::Dequeue() {
  if (IsEmpty()) {
    throw out_of_range("queue is empty.");
  }
  head_ = (head_ + 1) % capacity_;
  if (Size() <= (capacity_- 1) / 4) {
    // if queue is a quarter full, halve the queue capacity.
    int64_t new_capacity = (capacity_ - 1) / 2 + 1;
    T* new_elems = new T[new_capacity];
    int64_t count = 0;
    // for 문의 종료 조건을 'i < tail_' 이라고 쓰면 안된다.
    // tail_ < head_인 경우를 처리할 수 없게 된다.
    for (int64_t i = head_; i != tail_; i = (i + 1) % capacity_) {
      new_elems[count++] = elems_[i];
    }
    delete [] elems_;
    elems_ = new_elems;
    head_ = 0;
    tail_ = count;
    capacity_ = new_capacity;
  }
}

template<typename T>
const T& Queue<T>::Front() const {
  if (IsEmpty()) {
    throw out_of_range("queue is empty.");
  }
  return elems_[head_];
}

template<typename T>
const T& Queue<T>::End() const {
  if (IsEmpty()) {
    throw out_of_range("queue is empty.");
  }
  int64_t offset = (tail_ == 0) ? (capacity_ - 1) : ((tail_ - 1) % capacity_);
  return elems_[offset];
}

template<typename T>
int64_t Queue<T>::Size() const {
  if (head_ <= tail_) {
    return (tail_ - head_);
  }
  return (capacity_ - head_ + tail_);
}

template<typename T>
int64_t Queue<T>::Capacity() const {
  return capacity_;
}

template<typename T>
bool Queue<T>::IsEmpty() const {
  return (Size() == 0);
}

template<typename T>
bool Queue<T>::IsFull() const {
  return (Size() == capacity_ - 1);
}

int main() {
  Queue<int> q(1);

  // Test #1. enqueue 10 integers, 0 ~ 9.
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, capacity: %ld, front: %ld, end: %ld\n",
           q.Size(), q.Capacity(), q.Front(), q.End());
  }

  // Test #2. print front value while dequeueing 10 integers.
  while (q.Size()) {
    q.Dequeue();
    if (q.IsEmpty()) {
      printf("queue size: %ld, capacity: %ld\n", q.Size(), q.Capacity());
    } else {
      printf("queue size: %ld, capacity: %ld, front: %ld, end: %ld\n",
             q.Size(), q.Capacity(), q.Front(), q.End());
    }
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

  // Test #5. enqueue 10 integers - dequeue 2 integers - equeue 10 integers
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, capacity: %ld, front: %ld, end: %ld\n",
           q.Size(), q.Capacity(), q.Front(), q.End());
  }
  q.Dequeue();
  printf("queue size: %ld, capacity: %ld, front: %ld, end: %ld\n",
         q.Size(), q.Capacity(), q.Front(), q.End());
  q.Dequeue();
  printf("queue size: %ld, capacity: %ld, front: %ld, end: %ld\n",
         q.Size(), q.Capacity(), q.Front(), q.End());
  for (int i = 10; i < 21; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, capacity: %ld, front: %ld, end: %ld\n",
           q.Size(), q.Capacity(), q.Front(), q.End());
  }
  return 0;
}
