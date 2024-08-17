// Implement a stack using a variable-sized array.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>

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
// * When push an object, push back the object to the array.
// * When pop an object, pop back the object from the array.
// * When examine the top object, read the end of the array.
// * If the array is already full when push an object, double the array.
// * If the array is one-quarter full when pop an object, halve the array.
//
// Time Complexity
// * Push(): amortized O(1)
// * Pop(): amortized O(1)
// * Top(): O(1)
//
// Space Complexity: O(N), N is the # of objects.

template<typename T>
class Stack {
 public:
  Stack(size_t capacity):
    capacity_(capacity),
    top_(-1),
    num_elems_(0) {
    elems_ = (T*)(malloc(sizeof(T) * capacity_));
  }

  ~Stack() {
    free(elems_);
  }

  void Push(const T& elem) {
    if (IsFull()) {
      size_t new_capacity = num_elems_ * 2;
      T* new_elems = (T*)malloc(sizeof(T) * new_capacity);
      if (new_elems == nullptr) {
        throw bad_alloc();
      }
      for (int i = 0; i < num_elems_; ++i) {
        new(new_elems + i) T;
        new_elems[i] = elems_[i];
      }
      free(elems_);
      elems_ = new_elems;
      capacity_ = new_capacity;
    }

    new(elems_ + top_) T;
    elems_[++top_] = elem;
    ++num_elems_;
  }

  void Pop() {
    if (IsEmpty()) {
      throw length_error("stack is empty.");
    }
    elems_[top_--].~T();
    --num_elems_;

    if (num_elems_ <= capacity_ / 4) {
      size_t new_capacity = capacity_ / 2;
      T* new_elems = (T*)malloc(sizeof(T) * new_capacity);
      if (new_elems == nullptr) {
        throw bad_alloc();
      }
      for (int i = 0; i < num_elems_; ++i) {
        //new(new_elems + i) T;
        new_elems[i] = elems_[i];
      }
      free(elems_);
      elems_ = new_elems;
      capacity_ = new_capacity;
    }
  }

  const T& Top() const {
    if (IsEmpty()) {
      throw length_error("stack is empty.");
    }
    return elems_[top_];
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
  size_t capacity_;
  size_t top_;  // points to the last element.
  size_t num_elems_;
};

//{{{
int main() {
  Stack<int> s(1);

  // Test #1. push 16 elements, 0 ~ 15.
  for (int i = 0; i < 16; ++i) {
    s.Push(i);
    printf("stack size: %ld, capacity: %ld, top: %d\n",
           s.Size(), s.Capacity(), s.Top());
  }

  // Test #2. pop 16 elements.
  while (s.Size()) {
    printf("stack size: %ld, capacity: %ld, top: %d\n",
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
//}}}
