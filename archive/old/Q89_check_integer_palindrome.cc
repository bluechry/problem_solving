// A palindromic string is one which reads the same forwards and backwards,
// e.g., "redivider". In this problem, you are to write a program which
// determines if the decimal representation of an integer is a palindromic
// string. For example, your program should return true for the inputs
// 0, 1, 7, 11, 121, 333, and 2147447412, and false for the inputs
// -1, 12, 100, and 2147483647.
//
// Write a program that takes an integer and determines if that integer's
// representation as a decimal string is a palindrome.

#include <algorithm>
#include <chrono>
#include <cmath>
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

// Solution #1
//   주어진 정수의 digit을 reverse한 후 원래의 정수와 비교한다.
//
// Time Complexity: O(N), N is the # of digits in the integer.
//
// Space Complexity: O(1)

long ReverseBits(int n) {
  bool is_negative = n < 0;
  long result = 0, n_remaining = abs(n);
  while (n_remaining) {
    result = result * 10 + n_remaining % 10;
    n_remaining /= 10;
  }
  return is_negative ? -result : result;
}

bool IsPalindromeNumber(int n) {
  if (n < 0) {
    return false;
  }
  return n == ReverseBits(n);
}

// Solution #2
//   주어진 정수의 i번째 digit과 N - i - 1 (0 <= i < N)번째 digit이 동일한지
//   확인한다.
//
// Time Complexity: O(N/2), N is the # of digits in the integer.
//
// Space Complexity: O(1)

bool IsPalindromeNumber2(int n) {
  if (n < 0) {
    return false;
  } else if (n == 0) {
    return true;
  }

  int num_digits = static_cast<int>(floor(log10(n))) + 1;
  int msd_mask = static_cast<int>(pow(10, num_digits - 1));
  while (n >= 10) {
    if (n / msd_mask != n % 10) {
      return false;
    }
    n = n % msd_mask;
    n /= 10;
    msd_mask /= 100;
  }
  return true;
}

int main() {
  vector<int> v = {0, 1, 7, 11, 121, 333, 2147447412, -1, 12, 100, 2147483647};
  for (int i: v) {
    cout << (IsPalindromeNumber(i) ? "true" : "false") << " ";
    cout << (IsPalindromeNumber2(i) ? "true" : "false") << endl;
  }
  return 0;
}
