// Find the 2's complement of the given number.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
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
//  Invert all bits of the given number and add 1 to the result.
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

int64_t Find2sComplement(int64_t num) {
  return ~num + 1;
}

//{{{
int main() {
  vector<int64_t> v = {1L, 2L, 3L, -1L, -2L, -3L, (long)numeric_limits<int>::min(), numeric_limits<long>::min()};
  for (auto num : v) {
    cout << num << ' ' << Find2sComplement(num) << endl;
  }
  return 0;
}
// }}}
