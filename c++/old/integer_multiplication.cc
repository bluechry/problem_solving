// Problem Statement
// Multiply two integers. The integers are positive and have arbitrary number
// of digits. You should implement the grade school multiplication algorithm.
// Your implementation must have O(n^2) time complexity.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solution
// Integers are represented by vector<int>. Digit numbers of an integers are
// stored in reverse order. For example, 1234 is stored in a vector<int> like
// {4, 3, 2, 1}. Carry is not propagated during addition. After multiplying
// two integers digit by digit, handle carry propagation as a normalization
// process.

// Normalize a unnormalized integer. Check whether each digit number is
// larger than 10 and if yes, propagate a carry to the next digit.
void normalizeInteger(vector<int>& v) {  // unnormalized integer
  v.push_back(0);
  for (int i = 0; i < static_cast<int>(v.size()) - 1; ++i)
    if (v[i] >= 10) {
      v[i + 1] += v[i] / 10;
      v[i] = v[i] %= 10;
    }
  while (v.size() > 1 && v.back() == 0)
    v.pop_back();
}

// Multiply two integers represented by vector<int> and store the result in
// new vector<int>. Multiply two vectors digit by digit and then call the
// normalization function to handle carry propagation.
vector<int> multIntegers(const vector<int>& first,     // the first integer
                         const vector<int>& second) {  // the second integer
  vector<int> result(first.size() +  second.size(), 0);
  for (int i = 0; i < static_cast<int>(first.size()); ++i)
    for (int j = 0; j < static_cast<int>(second.size()); ++j)
      result[i + j] += first[i] * second[j];
  normalizeInteger(result);
  return result;
}

int main() {
  vector<int> a = {9, 9, 9, 9, 8};  // 99998
  vector<int> b = {9, 9, 9, 8};     // 9998
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  vector<int> c = multIntegers(a, b);
  reverse(c.begin(), c.end());
  for (auto i: c)
    cout << i;
  cout << endl;
  return 0;
}
