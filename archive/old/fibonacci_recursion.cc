// Problem Statement
// Find the n-th Fibonacci number. The Fibonacci sequence is defined as
// follows.
// Assume that the Fibonacci sequence starts from the 0th term.
//   F(0) = 1, F(1) = 1
//   F(n) = F(n - 2) + F(n - 1), n >= 2
// Implement Fib(n) function which returns the n-th Fibonacci number using
// recursion.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution
// The Fibonacci number formular can be implemented as defined above using the
// recursive function. Assume that the number of terms never exceeds 40.

// Function F takes an arguement which represents the n-th Fibonacci term.
// Returns 1 if n is 0 or 1, otherwise returns F(n - 2) + F(n - 1).
unsigned long FindFibonacci(int n) {  // the n-th term
  if (n == 0 || n == 1)
    return 1;
  else
    return FindFibonacci(n - 2) + FindFibonacci(n - 1);
}

int main() {
  for (int i = 0; i < 40; ++i)
    cout << "Term " << i << ": " << FindFibonacci(i) << endl;
  return 0;
}
