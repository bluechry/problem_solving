// Given a binary tree, return the pre-order traversal of its nodes' values.

//{{{
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

//
// Helper functions for creating a binary tree.
//

template<typename T>
struct TreeNode {
  T value_;
  shared_ptr<TreeNode<T>> left_, right_;
};

shared_ptr<TreeNode<int>> MakeTreeHelper(const char* start, char** end) {
  char* ptr = const_cast<char*>(start);
  if (*(++ptr) == ')') {
    *end = ptr;
    return shared_ptr<TreeNode<int>>(nullptr);
  }
  TreeNode<int>* node = new TreeNode<int>();
  node->value_ = strtol(ptr, &ptr, 10);
  node->left_ = MakeTreeHelper(ptr, &ptr);
  node->right_ = MakeTreeHelper(++ptr, &ptr);
  *end = ++ptr;
  return shared_ptr<TreeNode<int>>(node);
}

shared_ptr<TreeNode<int>> MakeTree(const string& s) {
  char* end;
  return MakeTreeHelper(s.c_str(), &end);
}
//}}}

// Solution
// 1. Visit the root of a given tree.
// 2. Traverse a left subtree.
// 3. Traverse a right subtree.
//
// Time Complexity: O(N)
//
// Space Complexity: O(h), h is the height of a tree.

void HelpTraversal(shared_ptr<TreeNode<int>> root, vector<int>* result) {
  if (!root) {
    return;
  }
  result->emplace_back(root->value_);
  if (root->left_) {
    HelpTraversal(root->left_, result);
  }
  if (root->right_) {
    HelpTraversal(root->right_, result);
  }
}

vector<int> PreorderTraversal(shared_ptr<TreeNode<int>> root) {
  vector<int> result;
  HelpTraversal(root, &result);
  return result;
}

//{{{
int main() {
{
  // Test #1.
  // string: "(0(1(3()())(4()()))(2(5()())()))"
  // return value: {{0}, {1, 2}, {3, 4, 5}}
  string s = "(0(1(3()())(4()()))(2(5()())()))";
  shared_ptr<TreeNode<int>> root = MakeTree(s);
  vector<int> result = PreorderTraversal(root);
  for (auto& i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
{
  // Test #2.
  // string: "()"
  // return value: {}
  string s = "()";
  shared_ptr<TreeNode<int>> root = MakeTree(s);
  vector<int> result = PreorderTraversal(root);
  for (auto& i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
  return 0;
}
//}}}
