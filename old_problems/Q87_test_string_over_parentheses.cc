// A string over the characters "{, }, (, ), [, ]" is said to be well-formed if
// the different types of brackets match in the correct order. For example,
// "([]){()}" is well-formed, as is "[()[]{()()}]". However, "{)" and
// "[()[]{()()" are not well-formed. Write a program that tests if a string made
// up of the characters "{, }, (, ), [, ]" is well-formed.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   * '{', '(', '['를 만나면 stack에 push 한다.
//   * '}', ')', ']'를 만나면 stack top에 올바른 짝이 저장되었는지 확인한다.
//     올바른 짝이 있으면 stack에서 pop하고, 그렇지 않으면 false를 반환한다.
//
// Time Complexity: O(N), N is the length of the expression.
//
// Space Complexity: O(N)

bool CheckParentheses(const string& expr) {
  stack<char> s;
  for (char c: expr) {
    if (c == '{' || c == '(' || c == '[') {
      s.emplace(c);
    } else {
      if (s.empty()) {
        return false;
      }
      char top = s.top();
      if (c == '}' && top != '{') {
        return false;
      } else if (c == ')' && top != '(') {
        return false;
      } else if (c == ']' && top != '[') {
        return false;
      }
      s.pop();
    }
  }
  return s.empty();
}

int main() {
{
  // Test #1.
  // expr = "([]){()}", return value = true
  string expr = "([]){()}";
  cout << (CheckParentheses(expr) ? "true" : "false") << endl;
}
{
  // Test #2.
  // expr = "[()[]{()()}]", return value = true
  string expr = "[()[]{()()}]";
  cout << (CheckParentheses(expr) ? "true" : "false") << endl;
}
{
  // Test #3.
  // expr = "{)", return value = false
  string expr = "{)";
  cout << (CheckParentheses(expr) ? "true" : "false") << endl;
}
{
  // Test #4.
  // expr = "[()[]{()()", return value = false
  string expr = "[()[]{()()";
  cout << (CheckParentheses(expr) ? "true" : "false") << endl;
}
{
  // Test #5.
  // expr = "[(]{)}", return value = false
  string expr = "[(]{)}";
  cout << (CheckParentheses(expr) ? "true" : "false") << endl;
}
  return 0;
}
