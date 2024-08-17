// Implement the random iterator type of generic array.

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

template<typename T>
class ArrayIterator: public iterator<random_access_iterator_tag, T> {
 public:
  // Constructors
  ArrayIterator(T* ptr): ptr_(ptr) {}
  ArrayIterator(const ArrayIterator& it): ptr_(it.ptr_) {}

  // Assignment Operator
  ArrayIterator& operator=(const ArrayIterator& it) {
    ptr_ = it.ptr_;
    return *this;
  }

  // Dereference Operators
  T& operator*() {
    return *ptr_;
  }

  T& operator[](size_t idx) {
    return ptr_[idx];
  }

  // Member Access Operator
  T* operator->() {
    return ptr_;
  }

  // Increment & Decrement Operators
  ArrayIterator& operator++() {
    ++ptr_;
    return *this;
  }

  ArrayIterator& operator--() {
    --ptr_;
    return *this;
  }

  ArrayIterator operator++(int) {
    return ArrayIterator(ptr_++);
  }

  ArrayIterator operator--(int) {
    return ArrayIterator(ptr_--);
  }
	
  // Random Access Operators
  ArrayIterator operator+(size_t off) {
    return ArrayIterator(ptr_ + off);
  }

  ArrayIterator operator-(size_t off) {
    return ArrayIterator(ptr_ - off);
  }

  ArrayIterator& operator+=(size_t off) {
    ptr_ += off;
    return *this;
  }
  ArrayIterator& operator-=(size_t off) {
    ptr_ -= off;
    return *this;
  }
	
  // Equality Operators
  bool operator==(const ArrayIterator& it) {
    return (ptr_ == it.ptr_);
  }

  bool operator!=(const ArrayIterator& it) {
    return (ptr_ != it.ptr_);
  }

  // Inequality Operators
  bool operator<(const ArrayIterator& it) {
    return (ptr_ < it.ptr_);
  }

  bool operator>(const ArrayIterator& it) {
    return (ptr_ > it.ptr_);
  }

  bool operator<=(const ArrayIterator& it) {
    return (ptr_ <= it.ptr_);
  }

  bool operator>=(const ArrayIterator& it) {
    return (ptr_ >= it.ptr_);
  }

  // Pointer Difference Operator
  ptrdiff_t operator-(const ArrayIterator& it) {
    return (ptr_ - it.ptr_);
  }

 private:
  T* ptr_;
};

template<typename T, size_t N>
class Array {
 public:
  using Iterator = ArrayIterator<T>;

  Array() = default;
  Array(const Array& arr) = delete;
  Array(Array&& arr) = delete;
  Array& operator=(const Array& arr) = delete;
  Array& operator=(Array&& arr) = delete;

  T& operator[](size_t idx) {
    return elems_[idx];
  }

  const T& operator[](size_t idx) const {
    return elems_[idx];
  }

  size_t Size() const {
    return N;
  }

  Iterator Begin() {
    return Iterator(&elems_[0]);
  }

  Iterator End() {
    return Iterator(&elems_[N]);
  }

 private:
  T elems_[N];
};

//{{{
int main() {
{
  // Test #1
  // Array::operator[], Array::Size()
  Array<int, 8> arr;
  for (int i = 0; i < arr.Size(); ++i) {
    arr[i] = i;
    cout << arr[i] << ' ';
  }
  cout << endl;

  // Test #2
  // Array::Begin(), Array::End(), Array::Iterator::operator*(),
  // Array::Iterator::operator++(int), Array::Iterator::operator!=()
  // Array::Iterator::operator++(), Array::Iterator::operator==()
  Array<int, 8>::Iterator it = arr.Begin();
  while (it != arr.End()) {
    cout << '(' << *(it++) << ',' << *it << ')' << ' ';
  }
  cout << endl;
  it = arr.Begin();
  while (true) {
    cout << *it << ' ';
    if (++it == arr.End()) {
      break;
    }
  }
  cout << endl;

  // Test #3
  // Array::Iterator::operator+=(), Array::Iterator::operator-=()
  // Array::Iterator::operator<(), Array::Iterator::operator>=()
  for (it = arr.Begin(); it < arr.End(); it += 2) {
    cout << *(it) << ' ';
  }
  cout << endl;
  for (it = arr.End() - 1; it >= arr.Begin(); it -= 2) {
    cout << *(it) << ' ';
  }
  cout << endl;

  // Test #4
  // Array::Iterator::operator[], Array::Iterator::operator+()
  // Array::Iterator::opeator-()
  it = arr.Begin();
  cout << it[0] << ' ' << it[2] << ' ' << it[4] << ' ' << it[6] << endl;
  for (int i = 0; i < arr.Size(); i += 2) {
    cout << *(it + i) << ' ';
  }
  cout << endl;
  it = arr.End();
  for (int i = 1; i < arr.Size(); ++i) {
    cout << *(it - i) << ' ';
  }
  cout << endl;

  // Test #5
  // Array::Iterator::Iterator(const Iterator& it),
  // Array::Iterator::operator<=(), Array::Iterator::operator>=()
  // Array::Iterator::operator<(), Array::Iterator::operator>()
  // Array::Iterator::operator-(const Iterator& it)
  it = arr.Begin();
  Array<int, 8>::Iterator it2 = it;
  cout << ((it == it2) ? "true" : "false") << endl;
  it2 = it + 5;
  cout << ((it <= it2) ? "true" : "false") << endl;
  cout << ((it >= it2) ? "true" : "false") << endl;
  cout << ((it < it2) ? "true" : "false") << endl;
  cout << ((it > it2) ? "true" : "false") << endl;
  cout << it2 - it << endl;

  // Test #6
  // Array::Iterator::operator->()
  Array<pair<int, int>, 2> arr2;
  arr2[0] = pair<int, int>(10, 20);
  arr2[1] = pair<int, int>(100, 200);
  auto it3 = arr2.Begin();
  cout << (*it3).first << ' ' << (*it3).second << endl;
  cout << it3->first << ' ' << it3->second << endl;

  // Test #7
  // Array::const operator[](int idx) const
  const Array<int, 8>& ref_arr = arr;
  cout << ref_arr[0] << endl;
}
  return 0;
}
//}}}
