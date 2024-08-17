// Given a binary tree, return the pre-order traversal of its nodes' values.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <stack>
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
// Simulate the recursive version using a stack.
// 1. push a root to a stack.
// 2. while stack is not empty
//    A. pop a node.
//    B. visit the node.
//    C. push the right child of the node.
//    D. push the left child of the node.
//
// Time Complexity: O(N)
//
// Space Complexity: O(h), h is the height of a tree.

vector<int> PreorderTraversal(shared_ptr<TreeNode<int>> root) {
  vector<int> result;
  if (!root) {
    return result;
  }

  stack<shared_ptr<TreeNode<int>>> node_stack;
  node_stack.emplace(root);
  while (!node_stack.empty()) {
    auto temp = node_stack.top();
    node_stack.pop();
    result.emplace_back(temp->value_);
    if (temp->right_) {
      node_stack.emplace(temp->right_);
    }
    if (temp->left_) {
      node_stack.emplace(temp->left_);
    }
  }
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
