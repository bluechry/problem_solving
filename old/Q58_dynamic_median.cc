// Design a data type that supports insert in logarithmic time, find-the-median
// in constant time, and remove-the-median in logarithmic time.

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// Solution
//   * 일단, median을 ceil(N/2)로 정의한다.
//     N = 2k일 때, median는 k.
//     N = 2k + 1일 때, median은 k + 1.
//
//   * max heap과 min heap을 두어서 max heap에 <= median 인 값들을 저장하고,
//     min heap에 > median 인 값들을 저장한다.
//
//   * FindMedian():
//     max_heap의 top()을 반환한다.
//
//   * InsertItem():
//     * Item이 median보다 크면 min_heap에 삽입하고, item이 median보다 작으면
//       max_heap에 삽입한다.
//
//     * max_heap.size() > min_heap.size() + 1 이면, max_heap에서 최대 값을
//       pop하여 min_heap에 push한다.
//
//     * min_heap.size() > max_heap.size() 이면, min_heap에서 최소 값을 pop하여
//       max_heap에 push한다.
//
//   * DeleteMedian():
//     max_heap에서 최대값을 pop한 후, max_heap의 크기가 min_heap보다 작게되면
//     min_heap의 최소값을 pop하여
//     max_heap에 push한다.
//
// Time Complexity
//   * FindMedian(): O(1)
//   * InsertItem(): O(logN)
//   * DeleteMedian(): O(logN)
//
// Space Complexity: O(N), N is total size of min heap and max heap.

template<typename T>
class DynamicMedian {
 public:
   const T& FindMedian();
   void InsertItem(const T& item);
   void DeleteMedian();
   bool IsEmpty();
   size_t Size();

 private:
   priority_queue<T> max_heap_;
   priority_queue<T, vector<T>, greater<T>> min_heap_;
};

template<typename T>
const T& DynamicMedian<T>::FindMedian() {
  if (IsEmpty()) {
    throw out_of_range("dynamic median is empty.");
  }
  return max_heap_.top();
}

template<typename T>
void DynamicMedian<T>::InsertItem(const T& item) {
  if (IsEmpty()) {
    max_heap_.push(item);
    return;
  }

  T median = FindMedian();
  if (item > median) {
    min_heap_.emplace(item);
  } else {
    max_heap_.emplace(item);
  }
  if (max_heap_.size() > min_heap_.size() + 1) {
    min_heap_.emplace(median);
    max_heap_.pop();
  } else if (min_heap_.size() > max_heap_.size()) {
    max_heap_.emplace(min_heap_.top());
    min_heap_.pop();
  }
}

template<typename T>
void DynamicMedian<T>::DeleteMedian() {
  if (IsEmpty()) {
    throw out_of_range("dynamic median is empty.");
  }
  max_heap_.pop();
  if (max_heap_.size() < min_heap_.size()) {
    max_heap_.emplace(min_heap_.top());
    min_heap_.pop();
  }
}

template<typename T>
bool DynamicMedian<T>::IsEmpty() {
  return max_heap_.empty();
}

template<typename T>
size_t DynamicMedian<T>::Size() {
  return max_heap_.size() + min_heap_.size();
}

int main() {
{
  // Test #1
  // Insert-Delete: +1, +2, +3, +4, +5, +6, +7, +8, +9, +10
  // Median:         1,  1,  2,  2,  3,  3,  4,  4,  5,  5
  DynamicMedian<int> dm;
  for (int i = 1; i <= 10; ++i) {
    dm.InsertItem(i);
    cout << dm.FindMedian() << " ";
  }
  cout << endl;
}
{
  // Test #2
  // Insert-Delete: +10, +9, +8, +7, +6, +5, +4, +3, +2, +1
  // Median:         10,  9,  9,  8,  8,  7,  7,  6,  6,  5
  DynamicMedian<int> dm;
  for (int i = 10; i >= 1; --i) {
    dm.InsertItem(i);
    cout << dm.FindMedian() << " ";
  }
  cout << endl;
}
{
  // Test #3
  // Insert-Delete: +1, +2, +3, +4, +5, -M, -M, -M, -M
  // Median:         1,  1,  2,  2,  3,  2,  4,  1,  5
  DynamicMedian<int> dm;
  for (int i = 1; i <= 5; ++i) {
    dm.InsertItem(i);
    cout << dm.FindMedian() << " ";
  }
  while (true) {
    dm.DeleteMedian();
    if (dm.IsEmpty()) break;
    cout << dm.FindMedian() << " ";
  }
  cout << endl;
}
  return 0;
}
