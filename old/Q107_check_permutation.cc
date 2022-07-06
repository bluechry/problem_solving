// Given two strings, write a method to decide if one is a permutation of the
// other. Assume that strings have only ascii chracters.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   두 문자열을 정렬한 결과가 동일하면 true, 그렇지 않으면 false를 반환한다.
//
// Time Complexity: O(KlogK), K = max(N, M), N = |s|, M = |t|
//
// Space Complexity: O(1)

bool CheckPermutation(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  return s == t;
}

// Solution
//   두 문자열을 구성하는 문자들의 개수를 세고 동일한지 비교한다.
//   1. 첫 문자열을 읽으면서 각 문자의 개수를 센다.
//   2. 두번째 문자열을 읽으면사 각 문자의 개수를 감소시킨다.
//   3. 문자의 개수가 0이 아닌 것이 존재하면 false를 반환하고,
//      그렇지 않으면 true를 반환한다.
//
// Time Complexity: O(N + M), N = |s|, M = |t|
//
// Space Complexity: O(1), sizeof(int) * 128

bool CheckPermutation2(const string& s, const string& t) {
  vector<int> freq(128, 0);
  for (char c: s) {
    ++freq[c];
  }
  for (char c: t) {
    --freq[c];
  }
  for (int i: freq) {
    if (i) {
      return false;
    }
  }
  return true;
}

int main() {
{
  // Test #1
  // s = "aabbccddee", t = "eeddccbbaa"
  string s = "aabbccddee", t = "eeddccbbaa";
  cout << (CheckPermutation(s, t) ? "true" : "false") << endl;;
  cout << (CheckPermutation2(s, t) ? "true" : "false") << endl;;
}
{
  // Test #2
  // s = "aabbccddeeff", t = "eedccbbaaeeeff"
  string s = "aabbccddeeff", t = "eedccbbaaeeeff";
  cout << (CheckPermutation(s, t) ? "true" : "false") << endl;;
  cout << (CheckPermutation2(s, t) ? "true" : "false") << endl;;
}
{
  // Test #3
  // s = "", t = ""
  string s = "", t = "";
  cout << (CheckPermutation(s, t) ? "true" : "false") << endl;;
  cout << (CheckPermutation2(s, t) ? "true" : "false") << endl;;
}
  return 0;
}
