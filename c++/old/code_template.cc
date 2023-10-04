// Problem Statement
// ...
// ...

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
//
// Time Complexity:
//
// Space Complexity:

void func() {
}

//{{{
int main() {
  return 0;
}
//}}}
