// Implement stack using an array.
// Assume that stack is resizable.

#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Stack {
 public:
  Stack(int64_t capacity);
  ~Stack();
  void Push(const T& elem);
  void Pop();
  const T& Top() const;
  bool IsEmpty() const;
  bool IsFull() const;
  int64_t Size() const;
  int64_t Capacity() const;

 private:
  T* elems_;
  int64_t top_;
  int64_t capacity_;
};

template<typename T>
Stack<T>::Stack(int64_t capacity):
    elems_(new T[capacity]),
    top_(-1),
    capacity_(capacity) {
  if (capacity <= 0) {
    throw bad_alloc();
  }
}

template<typename T>
Stack<T>::~Stack() {
  delete [] elems_;
}

// Solution
// * top_을 증가시킨 후 elems_[top_]에 'elem'을 저장한다.
// * Stack이 꽉 차면 크기를 두 배로 증가시킨 후 'elem'을 push한다.
// * Worst case는 stack이 두 배로 증가할 때 발생한다. Runtime cost는,
//   '# of array accesses = O(N)' 이다.
// * Amortized cost는 O(1)이다.
//   * N개의 element들을 push할 때 발생하는 array access 횟수는,
//     'N + (2 + 4 + 8 + ... + N) < 3N = O(N)' 이다.
//     e.g.) N = 128,
//           # of array accesses = 128 + (2 + 4 + 8 + 16 + 32 + 64 + 128)
//                               < 128 + (126 + 128) < 3 * 128
//   * 이 경우, 1개의 element를 push할 때 발생하는 array access 횟수는,
//     '3N / N = 3 = O(1)' 이다.
template<typename T>
void Stack<T>::Push(const T& elem) {
  if (IsFull()) {
    // double elems_ when stack is full.
    int64_t new_capacity = capacity_ * 2;
    T* temp = new T[new_capacity * 2];
    for (int i = 0; i < capacity_; ++i) {
      temp[i] = elems_[i];
    }
    delete [] elems_;
    elems_ = temp;
    capacity_ = new_capacity;
  }
  // delete old element in the next top position before overwrite it.
  // Note:
  //   상당히 tricky한 코드이고, 심지어 정확한 코드도 아니다.
  //   여기서 destructor를 호출하지 않고 Pop()에서 호출할 수도 있지만,
  //   그러면 ~Stack()에서 elems_[]를 delete할 때 double destruction이 발생한다.
  //   여기서 destructor를 호출하자마자 새로운 object로 덮어써버리면
  //   double destruction이 일어나지 않는다.
  //   문제는 destructor를 호출한 후에 assignment operator가 불리는데,
  //   이건 T class가 어떻게 정의되었느냐에 따라 문제가 될 수 있다.
  //
  //   Double destruction 문제를 해결하려면, elems_[]를 void 타입으로 선언하고
  //   각 element에 대하여 constructor와 destructor를 일일이 호출하면 된다.
  elems_[++top_].~T();
  elems_[top_] = elem;
}

// Solution
// * top_을 감소시켜서 element를 제거한다.
//   * top_에 위치한 element의 destructor를 호출하지 않는다.
//   * Element의 destructor는 Push()에 의해서 element가 overwrite될 때와
//     ~Stack()에서 elems_[]가 소멸될 때 호출되도록 하였다.
// * Element의 수가 stack 크기의 1/4 이하가 되면, stack을 절반으로 줄인다.
//   * Element의 수가 stack 크기의 1/2 이하가 될 때 stack을 절반으로 줄이면
//     빈번하게 stack 크기를 늘였다 줄였다를 반복할 수 있다.
//     e.g. element의 수가 stack 크기의 1/2일 때 Push()와 Pop()을 반복하면
//     stack 크기가 늘어났다 줄어들었다를 반복하게 된다.
//     따라서, Stack의 크기를 남아있는 element의 수보다 더 크게 줄여야 한다.
//   * Stack의 space utilization은 25% ~ 100%를 유지하게 된다.
// * Worst case는 stack이 절반으로 줄어들 때 발생한다. Runtime cost는,
//   '# of array accesses = O(N)' 이다.
// * Armortized cost는 O(1)이다.
//   * N개의 element들을 Pop()하는 cost는,
//     '# of array accesses = N + (N + N/2 + N/4 + ... + 2) < 3N = O(N)
//   * 1개의 element를 Pop()하는 cost는 O(1)
template<typename T>
void Stack<T>::Pop() {
  if (IsEmpty()) {
    throw out_of_range("stack is empty.");
  }
  --top_;
  int64_t size = Size();
  if (size <= capacity_ / 4) {
    // halve elems_ when stack is one-quarter full.
    int64_t new_capacity = capacity_ / 2;
    T* temp = new T[new_capacity];
    for (int i = 0; i < size; ++i) {
      temp[i] = elems_[i];
    }
    delete [] elems_;
    elems_ = temp;
    capacity_ = new_capacity;
  }
}

template<typename T>
const T& Stack<T>::Top() const {
  if (IsEmpty()) {
    throw out_of_range("stack is empty.");
  }
  return elems_[top_];
}

template<typename T>
bool Stack<T>::IsEmpty() const {
  return (top_ == -1);
}

template<typename T>
bool Stack<T>::IsFull() const {
  return (top_ + 1 == capacity_);
}

template<typename T>
int64_t Stack<T>::Size() const {
  return (top_ + 1);
}

template<typename T>
int64_t Stack<T>::Capacity() const {
  return capacity_;
}

int main() {
  Stack<int> s(1);

  // Test #1. push 16 elements, 0 ~ 15.
  for (int i = 0; i < 16; ++i) {
    s.Push(i);
    printf("stack size: %ld, capacity: %ld, top: %ld\n",
           s.Size(), s.Capacity(), s.Top());
  }

  // Test #2. pop 16 elements.
  while (s.Size()) {
    printf("stack size: %ld, capacity: %ld, top: %ld\n",
           s.Size(), s.Capacity(), s.Top());
    s.Pop();
  }

  // Test #3. read stack top from empty stack.
  try {
    cout << s.Top() << endl;
  } catch (exception& e) {
    cerr << "can't read stack top: " << e.what() << endl;
  }

  // Test #4. pop an element from empty stack.
  try {
    s.Pop();
  } catch (exception& e) {
    cerr << "can't pop: " << e.what() << endl;
  }
  return 0;
}
