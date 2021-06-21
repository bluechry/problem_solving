// Implement priority queue using binary heap.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   Binary heap은 complete binary tree이므로 array로 쉽게 구현할 수 있다.
//   Tree의 root node를 1번 원소로하고 left child를 2 * parent no. 원소에,
//   right child를 2 * parent no. + 1 원소에 저장하는 방식으로 tree를
//   array에 저장할 수 있다.
//
//   본 구현에서는 resizing priority queue를 구현하기 위하여 std::vector를
//   사용한다. 0번 원소는 사용하지 않을 것이므로, push_back()을 수행하면
//   1번 원소부터 채워지도록 초기 vector 크기를 1로 지정한다.
//
//   원소의 삽입, 삭제를 위하여 Swim(), Sink() method들을 정의한다.
//   * Swim()은 특정 위치의 원소를 bottom-up 방식으로 root를 향해 가면서
//     parent 원소와 크기 비교를 통하여 위치를 바꾸어 나간다.
//   * Sink()는 특정 위치의 원소를 top-down 방식으로 leaf node를 향해 가면서
//     children 원소들과 크기 비교를 통하여 위치를 바꾸어 나간다.
//
//   원소의 삽입은, vector에 새로운 원소를 push_back()한 후,
//   마지막(n-1번) 원소에서 Swim()을 호출한다.
//
//   원소의 삭제는 vector의 1번 원소와 마지막(n-1)번 원소를 swap한 후,
//   마지막 원소를 pop_back()하고 1번 원소에서 Sink()를 호출한다.
//
// Worst-Case Time Complexity
//   * 원소 삽입의 worst case는 Swim() 할 때 leaf node에서 root node까지
//     원소들을 비교하고 swap하는 경우이다.
//     원소들을 비교하고 swap하는 비용은 heap의 높이에 비례하므로,
//     worst-case time complexity는 O(logN)이다.
//
//   * 원소 삭제의 worst case는 Sink() 할 때 root node에서 leaf node까지
//     원소들을 비교하고 swap하는 경우이다.
//     원소들을 비교하고 swap하는 비용은 heap의 높이에 비례하므로,
//     worst-case time complexity는 O(logN)이다.
//
// Space Complexity
//   Binary heap에 사용되는 vector의 크기는 O(N).
//   그 외 추가 공간은 O(1).
//

// Compare type은 current node와 children node의 크기 관계를 나타내는 타입이다.
// Max heap을 구현하려면 std::less<>를 사용하고,
// min heap을 구현하려면 std::greater<>를 사용한다.
// 이 규칙은 C++ STL과 동일하다.
template<typename T, typename Compare = less<T>>
class PriorityQueue {
 public:
  PriorityQueue();
  void Push(const T& elem);
  void Pop();
  const T& Top() const;
  bool IsEmpty() const;
  int Size() const;
  void Dump();

 private:
  void Swim(int cur);
  void Sink(int cur);

  vector<T> elems_;
  Compare comp_;
};

template<typename T, typename Compare>
PriorityQueue<T, Compare>::PriorityQueue(): elems_(1) {
}

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::Push(const T& elem) {
  elems_.push_back(elem);
  Swim(elems_.size() - 1);
}

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::Pop() {
  if (IsEmpty())
    throw out_of_range("priority queue is empty.");
  int end = elems_.size() - 1;
  swap(elems_[1], elems_[end]);
  elems_.pop_back();
  Sink(1);
}

template<typename T, typename Compare>
const T& PriorityQueue<T, Compare>::Top() const {
  if (IsEmpty())
    throw out_of_range("priority queue is empty.");
  return elems_[1];
}

template<typename T, typename Compare>
bool PriorityQueue<T, Compare>::IsEmpty() const {
  return (elems_.size() == 1);
}

template<typename T, typename Compare>
int PriorityQueue<T, Compare>::Size() const {
  return elems_.size() - 1;
}

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::Dump() {
  for (int i = 1; i < elems_.size(); ++i)
    cout << elems_[i] << " ";
  cout << endl;
}

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::Swim(int cur) {
  while (cur > 1 && comp_(elems_[cur / 2], elems_[cur])) {
    swap(elems_[cur], elems_[cur / 2]);
    cur /= 2;
  }
}

template<typename T, typename Compare>
void PriorityQueue<T, Compare>::Sink(int cur) {
  int end = elems_.size() - 1;
  while (2 * cur <= end) {
    int next = 2 * cur;
    if (next < end && comp_(elems_[next], elems_[next + 1]))
      ++next;
    if (!comp_(elems_[cur], elems_[next]))
      break;
    swap(elems_[cur], elems_[next]);
    cur = next;
  }
}

int main() {
  PriorityQueue<int> pq;

  // Access empty priority queue.
  try {
    cout << pq.Top() << endl;
  } catch (exception& e) {
    cerr << e.what() << endl;
  }

  // Push 10 elements.
  for (int i = 1; i <= 10; ++i) {
    cout << "Push " << i << '\n';
    pq.Push(i);
    cout << "PQ: ";
    pq.Dump();
  }

  // Pop 10 elements.
  while (!pq.IsEmpty()) {
    cout << "Pop " << pq.Top() << '\n';
    pq.Pop();
  }
  return 0;
}
