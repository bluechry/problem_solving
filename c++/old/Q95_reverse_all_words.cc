// Given a string containing a set of words separated by whitespace, we would
// like to transform it to a string in which the words appear in the reverse
// order. For example, "Alice likes Bob" transforms to "Bob likes Alice".
// We do not need to keep the original string.
// Implement a function for reversing the words in a string s.
//
// Assume that
// * You may handle only the space character, ' ' as whitespace.
// * There is no leading and trailing spaces.
// * There are two or more spaces between two words.

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

// Solution #1
//   문장 전체를 뒤집고, 각 단어별로 한번 더 뒤집는다.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

void ReverseWords(string* s_ptr) {
  string& s = *s_ptr;
  reverse(s.begin(), s.end());

  string::iterator start, end;
  start = end = s.begin();
  while (true) {
    while (end != s.end() && !isspace(*end)) {
      ++end;
    }
    reverse(start, end);
    if (end == s.end()) {
      break;
    } else {
      start = ++end;
    }
  }
}

// Another implementation of Solution #1 using string::find().
// It is more readable that the previous codes.

void ReverseWords2(string* s_ptr) {
  string& s = *s_ptr;
  reverse(s.begin(), s.end());

  size_t start = 0, end;
  while ((end = s.find(" ", start)) != string::npos) {
    reverse(s.begin() + start, s.begin() + end);
    start = end + 1;
  }
  reverse(s.begin() + start, s.end());
}

int main() {
{
  // Test #1.
  // str: "Alice likes Bob"
  // return value: "Bob likes Alice"
  string s = "Alice likes Bob";
  ReverseWords(&s);
  cout << s << endl;

  s = "Alice likes Bob";
  ReverseWords2(&s);
  cout << s << endl;
}
{
  // Test #2.
  // str: ""
  // return value: ""
  string s = "";
  ReverseWords(&s);
  cout << s << endl;

  s = "";
  ReverseWords2(&s);
  cout << s << endl;
}
{
  // Test #3.
  // str: "Alice    likes  Bob"
  // return value: "Bob  likes    Alice"
  string s = "Alice    likes  Bob";
  ReverseWords(&s);
  cout << s << endl;

  s = "Alice    likes  Bob";
  ReverseWords2(&s);
  cout << s << endl;
}
  return 0;
}
