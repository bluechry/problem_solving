// Write a program that, given two positive integers, will calculate and print
// the gretest common divisor of the two.

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

// Solution
// * Use Euclid's method.
//   * GCD(a, 0) = a
//   * GCD(a, b) = GCD(b, a % b), (a > b)
//
// Time Complexity: O(1)
//
// Space Complexity: O(1) (didn't consider stack frame size.)

int gcd_recursive(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  return b ? gcd_recursive(b, a % b) : a;
}

int gcd_iterative(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  while (b) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

//{{{
int main() {
  // Test #1
  // gcd(100, 0) = 100
  cout << "gcd(100, 0): " << endl;
  cout << gcd_recursive(100, 0) << endl;
  cout << gcd_iterative(100, 0) << endl;
  cout << endl;

  // Test #2
  // gcd(0, 100) = 100
  cout << "gcd(0, 100): " << endl;
  cout << gcd_recursive(0, 100) << endl;
  cout << gcd_iterative(0, 100) << endl;
  cout << endl;

  // Test #3
  // gcd(39, 26) = 13
  cout <<  "gcd(39, 26): " << endl;
  cout << gcd_recursive(39, 26) << endl;
  cout << gcd_iterative(39, 26) << endl;
  cout << endl;

  // Test #4
  // gcd(26, 39) = 13
  cout <<  "gcd(26, 39): " << endl;
  cout << gcd_recursive(26, 39) << endl;
  cout << gcd_iterative(26, 39) << endl;
  cout << endl;

  // Test #5
  // gcd(100, 99) = 1
  cout << "gcd(100, 99): " << endl;
  cout << gcd_recursive(100, 99) << endl;
  cout << gcd_iterative(100, 99) << endl;
  return 0;
}
//}}}
