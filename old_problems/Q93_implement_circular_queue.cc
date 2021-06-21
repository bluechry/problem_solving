// Implement a queue API using an array for storing elements. Your API should
// include a constructor function, which takes as argument the initial capacity
// of the queue, enqueue and dequeue functions, and a function which returns
// the number of elements stored. Implement dynamic resizing (only extension)
// to support storing an arbitrarily large number of elements.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
// * APIs
//   * Queue<T>::Queue(int size)
//   * void Queue<T>::Enqueue(const T& elem)
//   * T Queue<T>::Dequeue()
//   * size_t Size() const()
//
// * 내부 자료구조
//   * vector<T> elems_ 변수에 원소들을 저장한다.
//     Resizable queue를 구현해야하므로 std::vector<T>를 사용한다.
//   * head_ 변수는 첫번째 원소를 가리킨다. (queue가 비어있지 않을 때)
//   * tail_ 변수는 마지막 원소의 다음 칸을 가리킨다.
//   * num_elems_ 변수는 queue 안에 저장된 원소들의 개수를 저장한다.
//
// * Enqueue()의 구현
//   * Queue가 꽉 찼으면,
//     1. head부터 tail-1까지의 원소들을 elems_[0]부터 저장되도록 rotate한다.
//     2. elems_를 doubling한다.
//   * tail_ 변수의 위치에 원소를 저장하고 tail_ 변수를 1 증가시킨다.
//
// * Dequeue()의 구현
//   * Queue가 비었으면, exception을 throw한다.
//   * head_ 변수의 위치에 저장된 원소를 반환하고 head_ 변수를 1 증가시킨다.
//
// * Size()의 구현
//   원소를 하나 삽입하고 삭제할 때마다 1씩 증가 또는 감소시킨다.
//
// Time Complexity: amortized order of O(N) for N enqueue/dequeue operations.
//
// Space Complexity: O(M), M is # of elements.

template<typename T>
class Queue {
 public:
  Queue(size_t capacity): elems_(capacity) {}

  void Enqueue(const T& elem) {
    if (num_elems_ == elems_.size()) {
      rotate(elems_.begin(), elems_.begin() + head_, elems_.end());
      head_ = 0;
      tail_ = num_elems_;
      elems_.resize(num_elems_ * kScaleFactor);
    }
    elems_[tail_] = elem;
    tail_ = (tail_ + 1) % elems_.size();
    ++num_elems_;
  }

  T Dequeue() {
    if (!num_elems_) {
      throw length_error("queue is empty");
    }
    T front = elems_[head_];
    head_ = (head_ + 1) % elems_.size();
    --num_elems_;
    return front;
  }

  size_t Size() const {
    return num_elems_;
  }

 private:
  vector<T> elems_;
  size_t head_ = 0;  // point the first element
  size_t tail_ = 0;  // point the next position of the last element
  size_t num_elems_ = 0;  // # of elements in queue
  const int kScaleFactor = 2;
};

int main() {
{
  // Test #1
  Queue<int> q(10);
  cout << "Size: " << q.Size() << endl;
  try {
    cout << q.Dequeue() << endl;
  } catch (exception& e) {
    cout << e.what() << endl;
  }
}
{
  // Test #2
  Queue<int> q(10);
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
  }
  cout << "Size: " << q.Size() << endl;
  while (q.Size()) {
    cout << q.Dequeue() << ' ';
  }
  cout << endl;
  cout << "Size: " << q.Size() << endl;
}
  return 0;
}
