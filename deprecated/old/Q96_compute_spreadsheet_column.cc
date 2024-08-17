// Spreadsheets often use an alphanumerical encoding of the successive columns.
// Specifically, columns are identified by "A", "B", "C", ..., "X", "Y", "Z",
// "AA", "AB", ..., "ZZ", "AAA", "AAB", ....
//
// Implement a function that converts a spreadsheet column id to the
// corresponding integer, with "A" corresponding to 1. For example, you should
// return 4 for "D", 27 for "AA", 702 for "ZZ", etc.

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
//   Column string을 26진수(0~25가 아닌 1~26까지 숫자로 이루어진)로 보고
//   10진수로 변환한다.
//
// Time Complexity: O(N), N is the length of a column string.
//
// Space Complexity: O(1)

int DecodeSpreadSheetColumn(const string& col) {
  int num = 0;
  for (char c: col) {
    num = num * 26 + (c - 'A' + 1);
  }
  return num;
}

int main() {
  vector<string> v = {"A", "B", "C", "D", "Z",
                      "AA", "AB", "AC", "AD", "AZ",
                      "ZA", "ZB", "ZC", "ZD", "ZZ"};
  for (string& s: v) {
    cout << s << " = " << DecodeSpreadSheetColumn(s) << endl;
  }
  return 0;
}
