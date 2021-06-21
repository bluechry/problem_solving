// Find the absolute numue of a given integer.
// Assume that the given integer is a 32-bit integer.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
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
//   음수가 주어지면 -1을 곱하여 반환한다.
//   문제가 되는 경우는 INT_MIN(= 1000...000)이다.
//   INT_MIN에 -1을 곱해도 INT_MIN으로 변화가 없기 때문이다.
//   INT_MIN을 양수로 바꾸려면 unsigned int type으로 casting하자.
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

unsigned int absolute(int num) {
  unsigned int abs = (num >= 0) ? num : -num;
  return abs;
}

int main() {
  // Test #1
  // num = INT_MIN, INT_MAX
  int num = numeric_limits<int>::min();
  cout << "abs(" << num << ") = " <<  absolute(num) << endl;

  num = numeric_limits<int>::max();
  cout << "abs(" << num << ") = " <<  absolute(num) << endl;

  // Test #2
  // num = -5 ~ 5
  for (int num = -5; num <= 5; ++num) {
    cout << "abs(" << num << ") = " <<  absolute(num) << endl;
  }
  return 0;
}
