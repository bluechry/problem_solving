// Implement a queue using a variable-sized array.

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
// * Use an array to store objects.
// * When enqueue an object, push back the object to the array.
// * When dequeue an object, pop front the object from the array.
// * If the array is already full when enqueue an object, double the array.
// * If the array is one-quarter full when dequeue an object, halve the array.
//
// Time Complexity
// * Enqueue: amortized O(1)
// * Dequeue: amortized O(1)
//
// Space Complexity: O(N), N is the # of objects.

template<typename T>
class Queue {
 public:
  Queue(size_t capacity):
    head_(0),
    tail_(-1),
    num_elems_(0),
    capacity_(capacity) {
    elems_ = (T*)malloc(sizeof(T) * capacity_);
    if (elems_ == nullptr) {
      throw bad_alloc();
    }
  }

  ~Queue() {
    free(elems_);
  }

  void Enqueue(const T& elem) {
    if (IsFull()) {
      size_t new_capacity = capacity_ * 2;
      T* new_elems = (T*)malloc(sizeof(T) * new_capacity);
      if (new_elems == nullptr) {
        throw bad_alloc();
      }
      for (int i = 0; i < capacity_; ++i) {
        new (new_elems + i) T;
        new_elems[i] = elems_[(head_ + i) % capacity_];
      }
      free(elems_);
      elems_ = new_elems;
      head_ = 0;
      tail_ = capacity_ - 1;
      capacity_ = new_capacity;
    }

    tail_ = ++tail_ % capacity_;
    elems_[tail_] = elem;
    ++num_elems_;
  }

  void Dequeue() {
    if (IsEmpty()) {
      throw length_error("queue is empty.");
    }
    elems_[head_].~T();
    head_ = ++head_ % capacity_;
    --num_elems_;

    if (num_elems_ <= capacity_ / 4) {
      size_t new_capacity = capacity_ / 2;
      T* new_elems = (T*)malloc(sizeof(T) * new_capacity);
      if (new_elems == nullptr) {
        throw bad_alloc();
      }
      for (int i = 0; i < num_elems_; ++i) {
        new (new_elems + i) T;
        new_elems[i] = elems_[(head_ + i) % capacity_];
      }
      free(elems_);
      elems_ = new_elems;
      head_ = 0;
      tail_ = num_elems_ - 1;
      capacity_ = new_capacity;
    }
  }

  const T& Front() const {
    if (IsEmpty()) {
      throw length_error("queue is empty.");
    }
    return elems_[head_];
  }

  const T& End() const {
    if (IsEmpty()) {
      throw length_error("queue is empty.");
    }
    return elems_[tail_];
  }

  size_t Size() const {
    return num_elems_;
  }

  size_t Capacity() const {
    return capacity_;
  }

  bool IsEmpty() const {
    return (num_elems_ == 0);
  }

  bool IsFull() const {
    return (num_elems_ == capacity_);
  }

 private:
  T* elems_;
  size_t head_, tail_;
  size_t num_elems_;
  size_t capacity_;
};

//{{{
int main() {
  Queue<int> q(1);

  // Test #1. enqueue 10 integers, 0 ~ 9.
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, capacity: %ld, front: %d, end: %d\n",
           q.Size(), q.Capacity(), q.Front(), q.End());
  }

  // Test #2. print front value while dequeueing 10 integers.
  while (q.Size()) {
    q.Dequeue();
    if (q.IsEmpty()) {
      printf("queue size: %ld, capacity: %ld\n", q.Size(), q.Capacity());
    } else {
      printf("queue size: %ld, capacity: %ld, front: %d, end: %d\n",
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
    printf("queue size: %ld, capacity: %ld, front: %d, end: %d\n",
           q.Size(), q.Capacity(), q.Front(), q.End());
  }
  q.Dequeue();
  printf("queue size: %ld, capacity: %ld, front: %d, end: %d\n",
         q.Size(), q.Capacity(), q.Front(), q.End());
  q.Dequeue();
  printf("queue size: %ld, capacity: %ld, front: %d, end: %d\n",
         q.Size(), q.Capacity(), q.Front(), q.End());
  for (int i = 10; i < 21; ++i) {
    q.Enqueue(i);
    printf("queue size: %ld, capacity: %ld, front: %d, end: %d\n",
           q.Size(), q.Capacity(), q.Front(), q.End());
  }
  return 0;
}
//}}}
