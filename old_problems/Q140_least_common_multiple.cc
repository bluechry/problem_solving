// Write a program that will, given two or more positive integers, calculate and
// print the least common multiple of them all.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//}}}

// Solution
// * gcd(a, b) can be obtained by Euclid's method as follows.
// * lcm(a, b) can be obtained by dividing a * b by gcd(a, b).
// * lcm(a, b, c, d) can be obtained by lcm(lcm(lcm(a, b), c), d).
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

int gcd(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
  // To avoid integer overflow, divide b by gcd(a, b) first.
  return a * (b / gcd(a, b));
}

int lcm(const vector<int>& nums) {
  int result = 1;
  for (int n: nums) {
    result = lcm(result, n);
  }
  return result;
}

//{{{
int main() {
  // Test #1
  // lcm(100, 0) = 0, lcm(0, 100) = 0
  cout << "lcm(100, 0): " << lcm(100, 0) << endl;
  cout << "lcm(0, 100): " << lcm(0, 100) << endl;
  cout << endl;

  // Test #2
  // lcm(2, 3) = 6, lcm(3, 2) = 6
  cout << "lcm(2, 3): " << lcm(2, 3) << endl;
  cout << "lcm(3, 2): " << lcm(3, 2) << endl;
  cout << endl;

  // Test #3
  // lcm(28, 7) = 28, lcm(7, 28) = 28
  cout << "lcm(28, 7): " << lcm(28, 7) << endl;
  cout << "lcm(7, 28): " << lcm(7, 28) << endl;
  cout << endl;

  // Test #4
  // lcm(127, 3) = 381, lcm(3, 127) = 381
  cout << "lcm(127, 3): " << lcm(3, 127) << endl;
  cout << "lcm(3, 127): " << lcm(127, 3) << endl;
  cout << endl;

  // Test #5
  // lcm(1, 2, 0) = 0, lcm(0, 1, 2) = 0
  cout << "lcm(1, 2, 0): " << lcm({1, 2, 0}) << endl;
  cout << "lcm(0, 1, 2): " << lcm({0, 1, 2}) << endl;
  cout << endl;

  // Test #6
  // lcm(10, 20, 30) = 60, lcm(30, 10, 20) = 60
  cout << "lcm(10, 20, 30): " << lcm({10, 20, 30}) << endl;
  cout << "lcm(30, 10, 20): " << lcm({30, 10, 20}) << endl;
  cout << endl;

  // Test #7
  // lcm(2, 3, 5, 7) = 210, lcm(3, 5, 2, 7) = 210
  cout << "lcm(2, 3, 5, 7): " << lcm({2, 3, 5, 7}) << endl;
  cout << "lcm(3, 5, 2, 7): " << lcm({3, 5, 2, 7}) << endl;
}
//}}}
