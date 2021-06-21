// Problem Statement
// Find the n-th Fibonacci number. The Fibonacci sequence is defined as
// follows.
// Assume that the Fibonacci sequence starts from the 0th term.
//   F(0) = 1, F(1) = 1
//   F(n) = F(n - 2) + F(n - 1), n >= 2
// Implement Fib(n) function which returns the n-th Fibonacci number using
// recursion. You have to reduce the number of function calls by avoiding
// recomputation of the same term.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution
// A function implements the Fibonacci definition above using memoization.
// Keep the value of the n-th term in a table and reuse the value instead of
// recomputation. Assume that the number of terms never exceeds 40.

// Function F takes an argument which represents the n-th Fibonacci term.
// Returns 1 if n is 0 or 1, otherwise returns F(n - 2) + F(n - 1).
unsigned long FindFibonacci(int n) {  // n-th term
  static unsigned long table[40];
  if (n == 0 || n == 1)
    return 1;
  else if (table[n])
    return table[n];
  else {
    unsigned long first = FindFibonacci(n - 2);
    unsigned long second = FindFibonacci(n - 1);
    table[n] = first + second;
    return table[n];
  }
}

int main() {
  for (int i = 0; i < 40; ++i)
    cout << "Term " << i << ": " << FindFibonacci(i) << endl;
  return 0;
}
