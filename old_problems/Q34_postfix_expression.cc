// Change a given infix expression to a postfix expression and solve it.
// Assume that an operand has one digit and an operator is surrounded by two
// values within parentheses.
// e.g.) (1 + ((2 + 3) * (4 * 5))) --> 123+45**+ == 101

#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   infix_expr을 scan하면서 각 문자에 따라서 다음과 같이 처리한다.
//   * 숫자를 만나면 postfix_expr에 append한다.
//   * 연산자를 만나면 op_stack에 push한다.
//   * ')'를 만나면 op_stack 연산자를 pop하여 postfix_expr에 append한다.
//
// Time Complexity: O(N), N is the length of the infix_expr.
//
// Space Complexity: O(N)

string InfixToPostfix(const string& infix_expr) {
  stack<char> op_stack;
  stringstream postfix_expr;
  for (auto c: infix_expr) {
    if (c >= '0' && c <= '9') {
      postfix_expr << c;
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      op_stack.push(c);
    } else if (c == ')') {
      postfix_expr << op_stack.top();
      op_stack.pop();
    }
  }
  return postfix_expr.str();
}

// Solution
//   postfix_expr을 scan하면서 각 문자에 따라서 다음과 같이 처리한다.
//   * 숫자를 만나면 result stack에 push한다.
//   * 연산자를 만나면 result stack에서 두 개의 숫자를 pop하여 계산한 후,
//     그 결과를 다시 result stack에 push한다.
//
// Time Complexity: O(N), N is the length of the postfix_expr.
//
// Space Complexity: O(N)

int CalculatePostfix(const string& postfix_expr) {
  stack<int> result;
  for (auto c: postfix_expr) {
    if (c >= '0' && c <= '9') {
      result.push(c - '0');
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      int right = result.top();
      result.pop();
      int left = result.top();
      result.pop();

      switch (c) {
        case '+':
          result.push(left + right);
          break;
        case '-':
          result.push(left - right);
          break;
        case '*':
          result.push(left * right);
          break;
        case '/':
          result.push(left / right);
          break;
        default:
          break;
      }
    }
  }
  return result.top();
}

int main() {
{
  // Test #1.
  // expr: (1 + ((2 + 3) * (4 * 5)))
  // postfix: 123+45**+
  // result: 101
  string infix_expr = "(1 + ((2 + 3) * (4 * 5)))";
  string postfix_expr = InfixToPostfix(infix_expr);
  cout << postfix_expr << " = " << CalculatePostfix(postfix_expr) << endl;
}
{
  // Test #2.
  // expr: ((2 * (4 / 2)) + ((5 * 8) / 2))
  // postfix: 242/*58*2/+ = 24
  // return value: 2
  string infix_expr = "((2 * (4 / 2)) + ((5 * 8) / 2))";
  string postfix_expr = InfixToPostfix(infix_expr);
  cout << postfix_expr << " = " << CalculatePostfix(postfix_expr) << endl;
}
  return 0;
}
