// Solve a given expression such as (1 + ((2 + 3) * (4 * 5))).
// Assume that an operand has one digit and an operator is surrounded by two
// values within parentheses.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   * Digit을 만나면 operand stack에 push한다.
//   * '+, -, *, /'를 만나면 operator stack에 push한다.
//   * ')'를 만나면 operator를 pop하고, 두 개의 operand들을 pop하여 계산한 후
//     그 결과를 operand stack에 다시 push한다.
//
//   Operand stack과 operator stack, 두 개의 stack을 사용한다.
//   하나의 stack으로 처리할 수 있지만 그러면 code가 좀 더 복잡해진다.
//   두 개의 stack을 사용하여도 저장되는 원소의 개수는 하나의 stack을
//   사용할 때와 동일하므로 space complexity는 차이가 없다.
//
// Time Complexity: O(N), N is the length of the expression.
//
// Space Complexity: O(N)

int Calculate(const string& expr) {
  stack<int> s_operand;
  stack<char> s_operator;

  for (char c: expr) {
    if (c >= '0' && c <= '9') {
      s_operand.push(c - '0');
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      s_operator.push(c);
    } else if (c == ')') {
      // 처음 pop되는 값이 right operand이다.
      int right = s_operand.top();
      s_operand.pop();
      // 두번째 pop되는 값이 left operand이다.
      int left = s_operand.top();
      s_operand.pop();

      switch (s_operator.top()) {
        case '+':
          s_operand.push(left + right);
          break;
        case '-':
          s_operand.push(left - right);
          break;
        case '*':
          s_operand.push(left * right);
          break;
        case '/':
          s_operand.push(left / right);
          break;
        default:
          break;
      }
      s_operator.pop();
    }
  }
  return s_operand.top();
}

int main() {
{
  // Test #1.
  // expr: (1 + ((2 + 3) * (4 * 5)))
  // return value: 101
  string expr = "(1 + ((2 + 3) * (4 * 5)))";
  cout << Calculate(expr) << endl;
}
{
  // Test #2.
  // expr: (2 * (4 / 2) + ((5 * 8) / 2))
  // return value: 24
  string expr = "((2 * (4 / 2)) + ((5 * 8) / 2))";
  cout << Calculate(expr) << endl;
}
  return 0;
}
