// A string is said to be an arithmetical expression in
// Reverse Polish Notation (RPN) if:
//   1. It is a single digit or a sequence of digits, prefixed with an option -,
//      e.g., "6", "123", "-42".
//   2. It is of the form "A, B, o" where A and B are RPN expressions and o is
//      one of +, -, *, /.
//
// For example, the following strings satisfy these rules:
//   "1729"
//   "3,4,+,2,*,1,+"
//   "1,1,+,-2,*"
//   "-641,6,/,28,/"
//
// An RPN expression can be evaluated uniquely to an integer, which is
// determined recursively. The base case corresponds to
//   Rule 1. an integer expressed in base-10 positional system.
//   Rule 2. corresponds to the recursive case, and the RPNs are evaluated in
//           the natural way, e.g., if A evaluates to 2 and B evaluates to 3,
//           then "A, B, x" evaluates to 6.
//
// Write a program that takes an arithmetical expression in RPN and returns the
// number that the expression evaluates to.
//
// Assume that
// * the return value is real number. (use float data type.)
// * the given expression is not empty and always right.
// * there are no whitespaces in the expression.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
// 1. 주어진 expression을 ','로 tokenize한다.
//    각 token마다 다음 과정을 수행한다.
//   * token이 '+', '-', '*', '/' 이면,
//     operand_stack에서 두 개의 operand들을 pop하여 연산한 후 결과를 다시
//     stack에 push한다.
//   * token이 number라면,
//     number를 float type으로 변환하여 operand_stack에 push한다.
// 2. Expression을 끝까지 읽었다면 stack top을 반환한다.
//
// Time Complexity: O(N), N is the length of the given expression string.
//
// Space Complexity: O(K), K is the # of operands in the expression.

float EvaluateRPN(const string& expr) {
  istringstream expr_stream(expr);
  stack<float> operand_stack;
  string token;
  while (getline(expr_stream, token, ',')) {
    if (token == "+" || token == "-" || token == "/" || token == "*") {
      float rhs = operand_stack.top();
      operand_stack.pop();
      float lhs = operand_stack.top();
      operand_stack.pop();
      switch (token.front()) {
        case '+':
          operand_stack.emplace(lhs + rhs);
          break;
        case '-':
          operand_stack.emplace(lhs - rhs);
          break;
        case '*':
          operand_stack.emplace(lhs * rhs);
          break;
        case '/':
          operand_stack.emplace(lhs / rhs);
          break;
      }
    } else {
      operand_stack.emplace(stof(token));
    }
  }
  return operand_stack.top();
}

int main() {
{
  // Test #1
  // expr: "1729"
  // return: 1729
  string expr = "1729";
  cout << EvaluateRPN(expr) << endl;
}
{
  // Test #2
  // expr: "3,4,+,2,*,1,+"
  // return: 15
  string expr = "3,4,+,2,*,1,+";
  cout << EvaluateRPN(expr) << endl;
}
{
  // Test #3
  // expr: "1,1,+,-2,*"
  // return: -4
  string expr = "1,1,+,-2,*";
  cout << EvaluateRPN(expr) << endl;
}
{
  // Test #4
  // expr: "-641,6,/,28,/"
  // return: -3.81548
  string expr = "-641,6,/,28,/";
  cout << EvaluateRPN(expr) << endl;
}
  return 0;
}
