// Implement a queue with enqueue, dequeue, and max operations. The max
// operation returns the maximum element currently stored in the queue.

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
//   Deque를 두어 queue에 원소를 넣고 뺄 때마다 최대값의 후보들을 업데이트한다.
//   * Queue에 원소가 삽입될 때, deque의 뒤에서부터 삽입되는 원소보다 작은
//     원소들을 제거한다. 이 원소들은 최대값으로 반환될 일이 없기 때문이다.
//   * Queue에서 원소가 삭제될 때, deque의 앞에 놓인 원소가 삭제되는 원소와
//     동일하면 이 원소 역시 삭제한다.
//
// Time Complexity
//   * Enqueue: amortized complexity of O(1)
//              N개의 원소들을 enqueue 할 경우, 각 원소들은 deque에
//              최대 1번 저장되고 최대 1번 삭제된다.
//              따라서, N개의 원소들을 enqueue하는 시간은 O(N)이고,
//              1개의 원소를 enqueue하는 평균 시간은 O(1)이다.
//   * Dequeue: O(1)
//
// Space Complexity: O(N)
//   원소들이 내림차순으로 삽입되는 경우 모든 원소들이 deque에 저장된다.

template<typename T>
class QueueWithMax {
 public:
  void Enqueue(const T& elem);
  void Dequeue();
  const T& Max() const;

 private:
  queue<T> elems_;
  deque<T> max_;
};

template<typename T>
void QueueWithMax<T>::Enqueue(const T& elem) {
  elems_.emplace(elem);
  while (!max_.empty()) {
    if (max_.back() >= elem) {
      break;
    }
    max_.pop_back();
  }
  max_.emplace_back(elem);
}

template<typename T>
void QueueWithMax<T>::Dequeue() {
  if (elems_.empty()) {
    throw out_of_range("queue is empty.");
  }
  if (elems_.front() == max_.front()) {
    max_.pop_front();
  }
  elems_.pop();
}

template<typename T>
const T& QueueWithMax<T>::Max() const {
  if (elems_.empty()) {
    throw out_of_range("queue is empty.");
  }
  return max_.front();
}

int main() {
{
  // Test #1.
  // Enqueue-Dequeue: E10, E20, E30, E40, E50
  // Max: 10, 20, 30, 40, 50
  QueueWithMax<int> q;
  vector<int> v = {10, 20, 30, 40, 50};
  for (int i: v) {
    q.Enqueue(i);
    cout << "Current max: " << q.Max() << endl;
  }
  cout << endl;
}
{
  // Test #2.
  // Enqueue-Dequeue: E50, E40, E30, E20, E10, D, D, D, D, D
  // Max: 50, 50, 50, 50, 50
  QueueWithMax<int> q;
  vector<int> v = {50, 40, 30, 20, 10};
  for (int i: v) {
    q.Enqueue(i);
    cout << "Current max: " << q.Max() << endl;
  }
  try {
    while (true) {
      cout << "Current max: " << q.Max() << endl;
      q.Dequeue();
    }
  } catch (exception& e) {
    cout << e.what() << endl;
  }
  cout << endl;
}
  return 0;
}
