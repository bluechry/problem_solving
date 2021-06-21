// Write a program which takes an integer and returns the integer corresponding
// to the digits of the input written in reverse order. For example, the reverse
// of 42 is 24, and the reverse of -314 is -413.

#include <algorithm>
#include <chrono>
#include <iostream>
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
//   * 주어진 정수 n을 10으로 나눈 나머지를 구한다.
//   * Result 변수에 10을 곱하여 자리수를 한 자리 앞으로 이동시킨 후
//     위에서 구한 10으로 나눈 나머지를 더한다.
//   * 위 과정을 n이 0이 될 때까지 반복한다.
//
// Note
//   주어진 정수 n을 뒤집었을 때 overflow가 발생할 수 있다.
//
//   예) 1111111119 -> 91111111111 (int 타입일 경우 overflow)
//
//   따라서 정수를 뒤집은 결과는 더 넓은 범위를 갖는 정수형으로 정의해야한다.
//
// Time Complexity: O(N), N is digits of the integer.
//
// Space Complexity: O(1)

long ReverseDigits(int n) {
  bool is_negative = n < 0;
  long result = 0, n_remaining = abs(n);
  while (n_remaining) {
    result = 10 * result + n_remaining % 10;
    n_remaining /= 10;
  }
  return is_negative ? -result : result;
}

int main() {
  vector<int> v = {0, 1, 128, -821, 1111111119, -1111111119};
  for (int i: v) {
    cout << "Reverse of " << i << " : " << ReverseDigits(i) << endl;
  }
  return 0;
}
