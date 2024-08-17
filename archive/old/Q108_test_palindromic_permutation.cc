// A palindrome is a string that reads the same forwards and backwards,
// e.g., "level", "rotator", and "foobaraboof". Write a program to test whether
// the letters forming a string can be permuted to form a palindrome.
// For example, "edified" can be permuted to form "deified".

#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   주어진 문자열의 각 문자의 개수를 세어 hash table에 저장한다.
//   문자열의 길이가 짝수일 때 문자의 개수가 모두 짝수여야하고,
//   문자열의 길이가 홀수일 때 홀수 개의 문자가 단 하나 존재해야한다.
//
//   간단하게 요약하면, 홀수 개의 문자가 2개 이상이면 false를 반환하고,
//   그렇지 않은 경우에는 true를 반환한다.
//
// Time Complexity: O(N), N is the length of the string.
//
// Space Complexity: O(c), c is the number of distinct characters of the string.

bool IsPalindromicPermutation(const string& s) {
  unordered_map<char, int> freq;
  for (char c: s) {
    ++freq[c];
  }

  int num_odds = 0;
  // 위의 for 문에서는 'const char'를 쓰지 않았는데, 여기서는 'const auto&'를
  // 쓴다. 그 이유는 i가 reference 타입이므로 i를 통하여 freq에 저장된 값이
  // 바뀌는 것을 막기 위함이다.
  for (const auto& i: freq) {
    if ((i.second & 0x1) && ++num_odds > 1) {
      return false;
    }
  }
  return true;
}

int main() {
{
  // Test #1.
  // string: "rotator"
  // return value: true
  string s = "rotator";
  cout << (IsPalindromicPermutation(s) ? "true" : "false") << endl;
}
{
  // Test #2.
  // string: "foobaraboof"
  // return value: true
  string s = "foobaraboof";
  cout << (IsPalindromicPermutation(s) ? "true" : "false") << endl;
}
{
  // Test #2.
  // string: "abcabcde"
  // return value: false
  string s = "abcabcde";
  cout << (IsPalindromicPermutation(s) ? "true" : "false") << endl;
}
{
  // Test #3.
  // string: "abcabcdef"
  // return value: false
  string s = "abcabcdef";
  cout << (IsPalindromicPermutation(s) ? "true" : "false") << endl;
}
  return 0;
}
