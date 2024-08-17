// For the purpose of this problem, define a palindromic string to be a string
// which when all the nonalphanumeric are removed it reads the same front to
// back ignoring case. For example, "A man, a plan, a canal, Panama." and
// "Able was I, ere I saw Elba!" are palindromic, but "Ray a Ray" is not.

#include <algorithm>
#include <cctype>
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
//   문자열의 시작과 끝에 각각 lo, hi 커서를 두고 lo와 hi를 하나씩 증가 또는
//   감소시키면서 각 커서가 가리키는 문자들이 동일한지 확인한다.
//   커서를 증가시킬 때는 알파벳이나 숫자가 아닌 문자들은 skip한다.
//
// Time Complexity: O(N), N is length of a given string.
//
// Space Complexity: O(1)

bool IsPalindrome(const string& str) {
  int lo = 0, hi = str.size() - 1;

  // lo == hi 인 경우에는 loop에 진입할 필요없이 바로 true를 반환한다.
  while (lo < hi) {
    // lo < hi 일 때까지만 loop를 돈다. lo와 hi가 역전되면 안 된다.
    // 예를 들어, 다음과 같이 code를 짜면 lo와 hi가 역전되었는지 따로
    // 확인해야한다.
    //
    // while (!isalnum(str[lo]) && lo < str.size()) { ++lo; }
    // while (!isalnum(str[hi]) && hi >= 0) { --hi; }
    // if (lo > hi) return true;
    //
    // 이렇게 하기보다는 lo < hi를 확인하는 것이 단순하고 깨끗하다.
    while (!isalnum(str[lo]) && lo < hi ) {
      ++lo;
    }
    while (!isalnum(str[hi]) && lo < hi) {
      --hi;
    }
    if (tolower(str[lo]) != tolower(str[hi])) {
      return false;
    }
    ++lo, --hi;
  }
  return true;
}

int main() {
{
  // Test #1
  // str: "A man, a plan, a canal, Panama.";
  // return value: true
  string s = "A man, a plan, a canal, Panama.";
  cout << (IsPalindrome(s) ? "true" : "false") << endl;
}
{
  // Test #2
  // str: "Able was I, ere I saw Elba!";
  // return value: true
  string s = "Able was I, ere I saw Elba!";
  cout << (IsPalindrome(s) ? "true" : "false") << endl;
}
{
  // Test #3
  // str: "..........!@#$%^...";
  // return value: true
  string s = "..........!@#$%^...";
  cout << (IsPalindrome(s) ? "true" : "false") << endl;
}
{
  // Test #4
  // str: "";
  // return value: true
  string s = "";
  cout << (IsPalindrome(s) ? "true" : "false") << endl;
}
{
  // Test #5
  // str: ".........aab.......";
  // return value: false
  string s = ".........aab.......";
  cout << (IsPalindrome(s) ? "true" : "false") << endl;
}
  return 0;
}
