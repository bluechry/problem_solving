// Problem Statement
// Multiply two positive integers using karatsuba multiplication method.
// The integers have different number of digits and there is no guarantee that
// the number of digits are 2^k.

// Solution: Karatsuba multiplication
// For two positive integers A and B, assume that A has n digits and B has m
// digits, n >= m.
// * m > n / 2
//   A = a1*10^(n/2) + a0
//   B = b1*10^(n/2) + b0
//   A * B = a1*b1*10^n + (a0*b1+a1*b0)*10^(n/2) + a0*b0
//         = a1*b1*10^n + {(a1+a0)*(b1+b0)-a1*b1-a0*b0}*10^(n/2) + a0*b0
// * m <= n / 2
//   A = a1 * 10^(n/2) + a0
//   B = b0
//   A * B = a1*b0*10^(n/2) + a0*b0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Convert primitive an integer number to a number vector.
vector<int> setInt(int num) {
  vector<int> result;
  while (num) {
    result.push_back(num % 10);
    num /= 10;
  }
  if (result.size() == 0)
    result.push_back(0);
  return result;
}

// Print a number vector.
void printInt(const vector<int>& num) {
  for (int i = num.size() - 1; i >= 0; --i)
    cout << num[i];
}

// Normalize a unnormalized integer. Check whether each digit number is smaller
// than 0 or larger than 9. If smaller than 0, borrow number from the next digit
// and if larger than 9, propagate carry to the next digit.
void normalize(vector<int>& num) {  // unnormalized number
  int num_digits = static_cast<int>(num.size());
  num.push_back(0);
  for (int i = 0; i < num_digits; ++i) {
    if (num[i] < 0) {
      int borrow = (abs(num[i]) + 9) / 10;
      num[i + 1] -= borrow;
      num[i] += borrow * 10;
    } else if (num[i] > 9) {
      num[i + 1] += num[i] / 10;
      num[i] %= 10;
    }
  }
  while (num.size() > 1 && num.back() == 0)
    num.pop_back();
}

// Multiply two positive integers. Assume that the integers are positive.
vector<int> multiply(const vector<int>& op1,  // the first number
                     const vector<int>& op2) {  // the second number
  vector<int> result(op1.size() + op2.size(), 0);
  int digits_op1 = static_cast<int>(op1.size());
  int digits_op2 = static_cast<int>(op2.size());
  for (int i = 0; i < digits_op1; ++i)
    for (int j = 0; j < digits_op2; ++j)
      result[i + j] += op1[i] * op2[j];
  normalize(result);
  return result;
}

// Add two positive integers. Assume the # of digits of the first one is longer
// than or equal to the # of digits of the second one.
vector<int> sum(const vector<int>& op1,    // the first number
                const vector<int>& op2) {  // the second number
  if (op1.size() < op2.size())
    return sum(op2, op1);
  vector<int> result(op1);
  int num_digits = static_cast<int>(op2.size());
  for (int i = 0; i < num_digits; ++i)
    result[i] += op2[i];
  normalize(result);
  return result;
}

// Find the difference between two positive integers. Assume that the first one
// is greater than the second one.
vector<int> diff(const vector<int>& op1,    // the first number
                 const vector<int>& op2) {  // the second number
  vector<int> result = op1;
  int num_digits = static_cast<int>(op2.size());
  for (int i = 0; i < num_digits; ++i)
    result[i] -= op2[i];
  normalize(result);
  return result;
}

// Multiply an integer by 10^n.
vector<int> exp(const vector<int>& op,
                const int n) {
  vector<int> result;
  for (int i = 0; i < n; ++i)
    result.push_back(0);
  for (auto i:op)
    result.push_back(i);
  return result;
}

// Calculate the product of two numbers using Karatsuba method.
vector<int> karatsuba(const vector<int>& op1,    // the first number
                      const vector<int>& op2) {  // the second number
  if (op1.size() < op2.size())
    return karatsuba(op2, op1);
  if (op2.size() == 1)
    return multiply(op1, op2);
  int half = op1.size() / 2;
  vector<int> a0(op1.begin(), op1.begin() + half);
  vector<int> a1(op1.begin() + half, op1.end());
  if (static_cast<int>(op2.size()) > half) {
    vector<int> b0(op2.begin(), op2.begin() + half);
    vector<int> b1(op2.begin() + half, op2.end());
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z1 = karatsuba(sum(a1, a0), sum(b1, b0));
    z1 = diff(z1, z2);
    z1 = diff(z1, z0);
    z1 = exp(z1, half);
    z2 = exp(z2, half * 2);
    vector<int> result = sum(z2, z1);
    result = sum(result, z0);
    return result;
  } else {
    vector<int> b0(op2.begin(), op2.end());
    vector<int> z1 = karatsuba(a1, b0);
    vector<int> z0 = karatsuba(a0, b0);
    z1 = exp(z1, half);
    vector<int> result = sum(z1, z0);
    return result;
  }
}

int main() {
  const vector<int> op1s = {5678, 134, 21};
  const vector<int> op2s = {134, 35, 983};
  int num_ints = static_cast<int>(op1s.size());

  // Test of karatsuba
  for (int i = 0; i < num_ints; ++i) {
    vector<int> op1 = setInt(op1s[i]);
    vector<int> op2 = setInt(op2s[i]);
    vector<int> res1 = multiply(op1, op2);
    vector<int> res2 = karatsuba(op1, op2);
    printInt(res1); cout << endl;
    printInt(res2); cout << endl;
  }

  // Try big number multiplication
  string str_op1 = "3141592653589793238462643383279502884197169399375105820974944592";
  string str_op2 = "2718281828459045235360287471352662497757247093699959574966967627";
  vector<int> op1, op2;
  for (auto ch: str_op1)
    op1.push_back(ch - '0');
  for (auto ch: str_op2)
    op2.push_back(ch - '0');
  reverse(op1.begin(), op1.end());
  reverse(op2.begin(), op2.end());

  vector<int> res = karatsuba(op1, op2);
  printInt(res); cout << endl;
  return 0;
}
