// Problem ID: BRACKETS2
//
// 문제 설명
//  '()','{}','[]'로 구성된 문자열이 주어질 때, bracket들의 짝이 잘 맞는지
//  확인하라. 잘 맞는다고 함은, opening bracket과 closing bracket이 같은
//  종류이고, bracket pair 간에는 교차가 없음을 의미한다.

#include <iostream>
#include <stack>

using namespace std;

// 풀이 방법 #1
//
// 시간 복잡도
//   주어진 bracket들의 문자열들을 한 번 스캔하므로,
//   T(N) = O(N), N = length of a string
//
// 공간 복잡도
//   Opening bracket들을 stack에 저장하므로,
//   S(N) = O(N), N = length of a string
//
bool IsWellMatched(const string& brackets) {
  const string opening = "({[";
  const string closing = ")}]";
  stack<char> openStack;

  for (auto b: brackets) {
    if (opening.find(b) != string::npos)
      openStack.push(b);
    else {
      if (openStack.empty())
        return false;
      if (opening.find(openStack.top()) != closing.find(b))
        return false;
      openStack.pop();
    }
  }
  return openStack.empty();
}

int main() {
  int C;
  cin >> C;
  while (C-- != 0) {
    string brackets;
    cin >> brackets;

    if (IsWellMatched(brackets))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
