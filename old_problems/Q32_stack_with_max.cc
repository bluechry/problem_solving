// Create a data structure that efficiently supports the stack operations
// (push and pop) and also a return-the-maximum operation. Assume the elements
// are real numbers so that you can compare them.

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
//   Stack에는 두 수의 pair가 저장된다. 첫번재 수는 원소이고,
//   두번째 수는 원소가 저장된 직후에 stack에서 가장 큰 원소의 값이다.
//
//   첫 원소를 삽입할 때는 원소 자신이 현재 가장 크므로 <원소, 원소> pair를
//   저장한다.
//   두 번째 원소부터는 stack top에 저장된 pair의 두 번째 수와
//   삽입할 원소의 크기를 비교하여 둘 중에 큰 값을 원소와 함께 저장한다.
//
//   현재 stack에서 가장 큰 값은 stack top에 저장된 pair의 두 번째 수이다.
//
// Time Complexity
//   Push(): amortized time of O(1)
//   Pop(): amortized time of O(1)
//
// Space Complexity: O(N), N is # of elements.

template<typename T>
class StackWithMax {
 public:
  void Push(const T& elem);
  void Pop();
  const T& Top() const;
  const T& Max() const;
  size_t Size() const;

 private:
  stack<pair<T, T>> stack_;
};

template<typename T>
void StackWithMax<T>::Push(const T& elem) {
  const T& cur_max = (Size() == 0) ? elem : max(elem, Max());
  // Note: elem과 cur_max에 std::move()를 적용해야할 것 같지만,
  // const T& 타입이기 때문에 std::move()를 적용하여도 copy ctor가 불리는 것을
  // 피할 수가 없다.
  stack_.emplace(elem, cur_max);
}

template<typename T>
void StackWithMax<T>::Pop() {
  if (Size() == 0) {
    throw out_of_range("stack is empty.");
  }
  stack_.pop();
}

template<typename T>
const T& StackWithMax<T>::Top() const {
  if (Size() == 0) {
    throw out_of_range("stack is empty.");
  }
  return stack_.top().first;
}

template<typename T>
const T& StackWithMax<T>::Max() const {
  if (Size() == 0) {
    throw out_of_range("stack is empty.");
  }
  return stack_.top().second;
}

template<typename T>
size_t StackWithMax<T>::Size() const {
  return stack_.size();
}

int main() {
  // Test #1
  // Push {100, 10, 200, 300, 250, 500}.
  // Max: {100, 100, 200, 300, 300, 500}.
  StackWithMax<int> s;
  vector<int> v = {100, 10, 200, 300, 250, 500};
  for (auto i : v) {
    s.Push(i);
    cout << "Push: " << s.Top() << " Max: " << s.Max() << endl;
  }

  // Test #2
  // Pop all elements.
  // Max: {500, 300, 300 200, 100, 100}
  cout << endl;
  while (s.Size() != 0) {
    cout << "Pop: " << s.Top() << " Max: " << s.Max() << endl;
    s.Pop();
  }
  return 0;
}
