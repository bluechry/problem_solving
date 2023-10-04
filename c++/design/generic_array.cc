// Implement generic array type.

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

template<typename T, size_t N>
class Array {
 public:
  // For simple implementation, we support only default constructor.
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

 private:
  T elems_[N];
};

//{{{
int main() {
  // Test #1
  // Array::operator[], Array::Size()
  Array<int, 8> arr;
  for (int i = 0; i < arr.Size(); ++i) {
    arr[i] = i;
    cout << arr[i] << ' ';
  }
  cout << endl;

  // Test #2
  // const Array::operator[] const
  const Array<int, 8>& ref_arr = arr;
  for (int i = 0; i < ref_arr.Size(); ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
//}}}
