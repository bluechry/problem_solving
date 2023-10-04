// Problem Statement
// Subtract two integers. The integers are positive and have any number of
// digits. The first integer is always larger then the second one. So your
// result is always positive. You should implement the grade school subtra-
// ction algorithm. Your implementation must have O(n) time complexity.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution
// Integers are represented by vector<int>. Digit numbers of an integers are
// stored in reverse order. For example, 1234 is stored in a vector<int> like
// {4, 3, 2, 1}. Borrowing will not be handled during subtraction. After
// subtract two integers digit by digit, borrowing will be occurred as a
// normalization process.

// Normalize a unnormalized integer. Check whether each digit number is
// smaller than 0 and if yes, borrow a 10 from the next digit.
void normalizeInteger(vector<int>& v) {  // unnormalized integer
  for (int i = 0; i < static_cast<int>(v.size()); ++i)
    if (v[i] < 0) {
      int borrow = (abs(v[i]) + 9) / 10;
      v[i + 1] -= borrow;
      v[i] += 10 * borrow;
    }
  while (v.size() > 1 && v.back() == 0)
    v.pop_back();
}

// Subtract two integers represented by vector<int> and store the result in
// new vector<int>. Subract two vectors digit by digit and then call the
// normalization function to handle borrowing. Assume that the first integer
// should be larger than the second one.
vector<int> subIntegers(const vector<int>& first,     // the first integer
                        const vector<int>& second) {  // the second integer
  vector<int> result(max(first.size(), second.size()), 0);
  const_cast<vector<int>&>(second).resize(result.size(), 0);
  for (int i = 0; i < static_cast<int>(result.size()); ++i)
    result[i] = first[i] - second[i];
  normalizeInteger(result);
  return result;
}

int main() {
  vector<int> a = {1, 1, 1, 1, 2};  // 11112
  vector<int> b = {8, 8, 0, 9};     // 8809
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  vector<int> c = subIntegers(a, b);
  reverse(c.begin(), c.end());
  for (auto i: c)
    cout << i;
  cout << endl;
  return 0;
}
