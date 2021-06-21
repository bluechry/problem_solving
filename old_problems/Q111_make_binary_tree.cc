// Given a tree description string like "(A(B()())(C()()))", return a
// binary tree corresponding the string. The tree description string is defined
// recursively as follows:
//
// Tree := ()
//      := (node_value Tree Tree)
//
// Assume that the string has no whitespace between adjacent characters.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
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
//   주어진 문자열을 scan하면서,
//   * '(' 다음 ')'가 바로 나오면 terminal node로 간주하고 nullptr을 반환한다.
//   * '(' 다음 ')'가 아니라면 node를 생성하고 node value를 읽는다.
//   * node value 다음에 '('가 나오면 left subtree를 만든다.
//   * 이어서 right subtree를 만든다.
//   * node를 반환한다.
//
// Time Complexity: O(N), N is the length of the string.
//
// Space Complexity: O(M), M is the number of nodes in the tree.

template<typename T>
struct TreeNode {
  T value_;
  unique_ptr<TreeNode<T>> left_, right_;
};

unique_ptr<TreeNode<int>> MakeTreeHelper(const char* start, char** end) {
  char* ptr = const_cast<char*>(start);
  if (*(++ptr) == ')') {
    *end = ptr;
    return unique_ptr<TreeNode<int>>(nullptr);
  }
  TreeNode<int>* node = new TreeNode<int>();
  node->value_ = strtol(ptr, &ptr, 10);
  node->left_ = MakeTreeHelper(ptr, &ptr);
  node->right_ = MakeTreeHelper(++ptr, &ptr);
  *end = ++ptr;
  return unique_ptr<TreeNode<int>>(node);
}

unique_ptr<TreeNode<int>> MakeTree(const string& s) {
  char* end;
  return MakeTreeHelper(s.c_str(), &end);
}

void PreorderTraverse(const unique_ptr<TreeNode<int>>& ptr) {
  TreeNode<int>* node = ptr.get();
  if (!node) {
    return;
  }
  cout << node->value_ << ' ';
  PreorderTraverse(node->left_);
  PreorderTraverse(node->right_);
}

int main() {
{
  // Test #1.
  // tree description: "(0(1(3()())(4()()))(2(5()())()))"
  // output: 0 1 3 4 2 5
  string s = "(0(1(3()())(4()()))(2(5()())()))";
  unique_ptr<TreeNode<int>> root = MakeTree(s);
  PreorderTraverse(root);
  cout << endl;
}
{
  // Test #2.
  // tree description: "()"
  // output: no output
  string s = "()";
  unique_ptr<TreeNode<int>> root = MakeTree(s);
  PreorderTraverse(root);
  cout << endl;
}
  return 0;
}
