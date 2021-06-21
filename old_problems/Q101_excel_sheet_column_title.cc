// Given a positive integer, return its corresponding column title as appear in
// an Excel sheet.
// For example, 1 -> A, 2 -> B, ..., 26 -> Z, 27 -> AA, 28 -> AB, ...

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

// Solution
//
// Time Complexity: O(N), N is # of digits of a given number.
//
// Space Complexity: O(N) for the encoded column string.

string EncodeColumnNo(int num) {
  string col_str;
  while (num) {
    int mod = num % 26;
    num /= 26;
    if (mod == 0) {
      mod = 26;
      --num;
    }
    col_str.push_back('A' + mod - 1);
  }
  reverse(col_str.begin(), col_str.end());
  return col_str;
}

// Another implementation of the solution.
// It is more simpler and readable than the previous code.

string EncodeColumnNo2(int num) {
  string col_str;
  while (num) {
    --num;
    col_str.push_back('A' + (num % 26));
    num /= 26;
  }
  reverse(col_str.begin(), col_str.end());
  return col_str;
}

int main() {
  vector<int> col_nums = {1, 2, 3, 26, 27, 28, 52, 53, 128, 256, 512, 1024};
  for (int i: col_nums) {
    cout << i << " = " << EncodeColumnNo(i) << endl;
    cout << i << " = " << EncodeColumnNo2(i) << endl;
  }
  return 0;
}
