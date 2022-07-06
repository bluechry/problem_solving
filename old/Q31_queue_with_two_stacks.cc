// Implement a queue with two stacks so that each queue operations takes a
// constant amortized number of stack operations.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
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
//   Stack 1개로는 절대 구현할 수 없다. 2개로 구현해야한다.
//
//   Enqueue 용 stack과 dequeue 용 stack을 두고 dequeue 연산이 일어나면,
//   enqueue stack에 있는 원소들을 pop하여 dequeue stack으로 push한 후
//   dequeue stack에서 pop한다.
//
//   Dequeue stack에 원소가 존재하는 동안 dequeue 연산이 발생하면
//   dequeue stack에서 바로 pop하고, dequeue stack이 빈 상태에서 deqeue 연산이
//   발생할 때만 enqueue stack에서 원소들을 가지고 온다.
//
// Time Complexity
//   N 개의 원소를 enqueue, dequeue하는데 드는 비용은 O(N)이다.
//   왜냐하면 각 원소는 최대 2번 enqueue 되고, 최대 2번 dequeue 되기때문이다.
//
//   각 원소에 대한 enqueue, dequeue 비용은 다음과 같다.
//   * Enqueue: amortized time of O(1).
//   * Dequeue: amortized time of O(1).
//
// Space Complexity: O(N), N is # of elements.

template<typename T>
class QueueWithTwoStacks {
 public:
  void Enqueue(const T& elems);
  void Dequeue();
  const T& Front() const;
  bool Empty() const;

 private:
  void Transfer() const;
  mutable stack<T> in_, out_;
};

template<typename T>
void QueueWithTwoStacks<T>::Enqueue(const T& elems) {
  in_.emplace(elems);
}

template<typename T>
void QueueWithTwoStacks<T>::Dequeue() {
  if (Empty()) {
    throw out_of_range("stack is empty.");
  }
  if (out_.empty()) {
    Transfer();
  }
  out_.pop();
}

template<typename T>
const T& QueueWithTwoStacks<T>::Front() const {
  if (Empty()) {
    throw out_of_range("stack is empty.");
  }
  if (out_.empty()) {
    Transfer();
  }
  return out_.top();
}

template<typename T>
bool QueueWithTwoStacks<T>::Empty() const {
  return (in_.empty() && out_.empty()) ? true : false;
}

template<typename T>
void QueueWithTwoStacks<T>::Transfer() const {
  while (!in_.empty()) {
    out_.push(in_.top());
    in_.pop();
  }
}

int main() {
  QueueWithTwoStacks<int> q;

  // Test #1. enqueue 10 integers, 0 ~ 9.
  for (int i = 0; i < 10; ++i) {
    q.Enqueue(i);
  }

  // Test #2. dequeue all integers.
  while (!q.Empty()) {
    cout << q.Front() << " ";
    q.Dequeue();
  }
  cout << endl;

  // Test #3. dequeue from the empty queue.
  try {
    q.Dequeue();
  } catch (exception& e) {
    cerr << e.what() << endl;
  }

  // Test #4. enqueue & dequeue alternatively.
  for (int i = 0; i < 20; ++i) {
    cout << "Enqueue " << i * 2 << endl;
    q.Enqueue(2 * i);
    if (i % 4 == 3) {
      cout << "Dequeue " << q.Front() << endl;
      q.Dequeue();
      cout << "Dequeue " << q.Front() << endl;
      q.Dequeue();
    }
  }
  return 0;
}
