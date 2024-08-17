// Solve the same problem for expressions in Polish Notation, i.e.,
// when A, B, o is replaced by o, A, B in Rule (2.) on the Q99.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <stack>
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
//   Q99와 다르게 infix notation을 사용한다. 하지만 expression을 거꾸로 읽고
//   operand들의 순서만 바꾸면 풀이법은 동일하다.
//   예를 들면, "+,A,B" -> "B,A,+" -> "A,B,+" 이다.
//   "A,B,+"를 푸는 방법은 Q99와 동일하다.
//
// Time Complexity: O(N), N is the length of the expression.
//
// Space Complexity: O(C), C is # of operands in the expression. (C <= N)

float EvaluatePN(const string& expr) {
  // Tokenize the expression
  istringstream expr_stream(expr);
  string token;
  vector<string> token_vec;
  while (getline(expr_stream, token, ',')) {
     token_vec.emplace_back(token);
  }

  // Scan the token vector in reverse order, evaluate the expression.
  stack<float> operand_stack;
  for (auto it = token_vec.rbegin(); it != token_vec.rend(); ++it) {
    if (*it == "+" || *it == "-" || *it == "*" || *it == "/") {
      float lhs = operand_stack.top();
      operand_stack.pop();
      float rhs = operand_stack.top();
      operand_stack.pop();

      switch ((*it).front()) {
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
      operand_stack.emplace(stof(*it));
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
  cout << EvaluatePN(expr) << endl;
}
{
  // Test #2
  // expr: "+,*,+,3,4,2,1"
  // return: 15
  string expr = "+,*,+,3,4,2,1";
  cout << EvaluatePN(expr) << endl;
}
{
  // Test #3
  // expr: "*,+,1,1,-2"
  // return: -4
  string expr = "*,+,1,1,-2";
  cout << EvaluatePN(expr) << endl;
}
{
  // Test #4
  // expr: "/,/,-641,6,28"
  // return: -3.81548
  string expr = "/,/,-641,6,28";
  cout << EvaluatePN(expr) << endl;
}
  return 0;
}
