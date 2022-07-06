// Write a program that takes a double x and an integer y and returns xy.
// You can ignore overflow and underflow.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   Implement Power() as a recursive function.
//   * if y = 2k, Power(x, y) = Power(x, k) * Power(x, k)
//   * if y = 2k + 1, Power(x, y) = Power(x, k) * Power(x, k) * x
//
// Note
//   if y < 0, x = 1.0 / x & y = -y
//
// Time Complexity: O(logN), N is the value of x.
//
// Space Complexity: O(logN), the size of the recursive call stack.

double Power(double x, int y) {
  if (y == 0) {
    return 1;
  }
  if (y < 0) {
    x = 1.0 / x;
    y *= -1;
  }
  double temp = Power(x, y >> 1);
  return (y & 0x1) ? temp * temp * x : temp * temp;
}

// Iterative version of the previous solution.
// Space complexity is O(1).

double Power2(double x, int y) {
  if (y < 0) {
    x = 1.0 / x;
    y *= -1;
  }
  double result = 1.0;
  while (y) {
    if (y & 1) {
      result *= x;
    }
    x *= x;
    y >>= 1;
  }
  return result;
}

int main() {
{
  // Test #1
  // x = 2.0, y = 0
  // return value: 1.0
  printf("%.2lf\n", Power(2.0, 0));
  printf("%.2lf\n", Power2(2.0, 0));
}
{
  // Test #2
  // x = 2.0, y = 1
  // return value: 2.0
  printf("%.2lf\n", Power(2.0, 1));
  printf("%.2lf\n", Power2(2.0, 1));
}
{
  // Test #3
  // x = 2.0, y = 9
  // return value: 512.0
  printf("%.2lf\n", Power(2.0, 9));
  printf("%.2lf\n", Power2(2.0, 9));
}
{
  // Test #4
  // x = 2.0, y = 10
  // return value: 1024.0
  printf("%.2lf\n", Power(2.0, 10));
  printf("%.2lf\n", Power2(2.0, 10));
}
{
  // Test #5
  // x = 2.0, y = -1
  // return value: 0.5
  printf("%.2lf\n", Power(2.0, -1));
  printf("%.2lf\n", Power2(2.0, -1));
}
{
  // Test #5
  // x = 2.0, y = -10
  // return value: 0.5
  printf("%lf\n", Power(2.0, -10));
  printf("%lf\n", Power2(2.0, -10));
}
  return 0;
}
