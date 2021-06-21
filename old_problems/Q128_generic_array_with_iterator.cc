/*
Design generic type array like std::array.
Here, there are interfaces of class Array and class Iterator.

template<typename T>
class Iterator : public iterator<random_access_iterator_tag, T> {
 public:
  // Constructors
  Iterator(T* ptr);
  Iterator(const Iterator& it);

  // Assignment operator
  Iterator& operator=(const Iterator& it);

  // Dereference operators
  T& operator*();  // dereference
  T& operator[](int idx)  // dereference with random access

  // Member access operator
  T* operator->()  // access member of object

  // Increment & decrement operators
  Iterator& operator++();  // prefix increment operator
  Iterator operator++(int);  // postfix increment operator
  Iterator& operator--();  // prefix decrement operator
  Iterator operator--(int);  // postfix decrement operator

  // Random access operators
  Iterator operator+(int n);  // return new iterator that goes n positions further
  Iterator operator-(int n);  // return new iterator that goes n positions back
  Iterator& operator+=(int n);  // move iterator forward by n positions
  Iterator& operator-=(int n);  // move iterator backward by n positions

  // Equality test operators
  bool operator==(const Iterator& it);
  bool operator!=(const Iterator& it);

  // Inequality test operators
  bool operator<=(const Iterator& it);
  bool operator>=(const Iterator& it);
  bool operator<(const Iterator& it);
  bool operator>(const Iterator& it);

  // Pointer difference operator
  ptrdiff_t operator-(const Iterator& it);
};

template<typename T, size_t N>
class Array {
 public:
  using Iterator=::Iterator<T>;

  Array() = default;
  Array(const Array& arr) = delete;
  Array(Array&& arr) = delete;
  Array& operator=(const Array& arr) = delete;
  Array& operator=(Array&& arr) = delete;

  T& operator[](int idx);
  const T& operator[](int idx) const;

  size_t Size() const;
  Iterator Begin();
  Iterator End();
};
*/

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

template<typename T>
class Iterator : public iterator<random_access_iterator_tag, T> {
 public:
  // Constructors
  Iterator(T* ptr): ptr_(ptr) {}

  Iterator(const Iterator& it) {
    ptr_ = it.ptr_;
  }

  // Assignment operator
  Iterator& operator=(const Iterator& it) {
    ptr_ = it.ptr_;
    return *this;
  }

  // Dereference operators
  T& operator*() {
    return *ptr_;
  }

  T& operator[](int idx) {
    return ptr_[idx];
  }

  // Member access operator
  T* operator->() {
    return ptr_;
  }

  // Increment & decrement operators
  Iterator& operator++() {
    ++ptr_;
    return *this;
  }

  Iterator operator++(int n) {
    Iterator prev = *this;
    ++ptr_;
    return prev;
  }

  Iterator operator--() {
    --ptr_;
    return *this;
  }

  Iterator operator--(int n) {
    Iterator prev = *this;
    --ptr_;
    return prev;
  }

  // Random access operators
  Iterator operator+(int n) {
    return Iterator(ptr_ + n);
  }

  Iterator operator-(int n) {
    return Iterator(ptr_ - n);
  }

  Iterator& operator+=(int n) {
    ptr_ += n;
    return *this;
  }

  Iterator& operator-=(int n) {
    ptr_ -= n;
    return *this;
  }

  // Equality operators
  bool operator==(const Iterator& it) {
    return ptr_ == it.ptr_;
  }

  bool operator!=(const Iterator& it) {
    return ptr_ != it.ptr_;
  }

  // Inequality operators
  bool operator<=(const Iterator& it) {
    return ptr_ <= it.ptr_;
  }

  bool operator>=(const Iterator& it) {
    return ptr_ >= it.ptr_;
  }

  bool operator<(const Iterator& it) {
    return ptr_ < it.ptr_;
  }

  bool operator>(const Iterator& it) {
    return ptr_ > it.ptr_;
  }

  // Pointer difference operator
  ptrdiff_t operator-(const Iterator& it) {
    return ptr_ - it.ptr_;
  }

 private:
  T* ptr_;
};

template<typename T, size_t N>
class Array {
 public:
  using Iterator = ::Iterator<T>;

  Array() = default;
  Array(const Array& arr) = delete;
  Array(Array&& arr) = delete;
  Array& operator=(const Array& arr) = delete;
  Array& operator=(Array&& arr) = delete;

  T& operator[](int idx) {
    return elems_[idx];
  }

  const T& operator[](int idx) const {
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
