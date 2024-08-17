// Given a binary tree, return the sequence of level order traversal.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//
// Helper functions for creating a binary tree.
//

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

// Solution
//   1. root node를 queue에 삽입한다.
//   2. queue에서 node를 하나 pop한 후, 그 node의 children을 queue에 push한다.
//      node의 value를 result vector에 삽입한다.
//   3. queue가 빌 때까지 2번을 반복한다.
//
// Time Complexity: O(N), N is # of nodes in the tree.
//
// Space Complexity: O(M), M is the max number of nodes in a level.
//                         if the tree is a perfect binary tree, M is N/2.

vector<int> LevelOrderTraversal(const unique_ptr<TreeNode<int>>& root) {
  vector<int> result;
  if (!root.get()) {
    return result;
  }

  queue<TreeNode<int>*> q;
  q.emplace(root.get());
  while (!q.empty()) {
    TreeNode<int>* node = q.front();
    q.pop();
    if (node->left_) {
      q.emplace(node->left_.get());
    }
    if (node->right_) {
      q.emplace(node->right_.get());
    }
    result.emplace_back(node->value_);
  }
  return result;
}

int main() {
{
  // Test #1.
  // tree description: "(0(1(3()())(4()()))(2(5()())()))"
  // output: 0 1 2 3 4 5
  string s = "(0(1(3()())(4()()))(2(5()())()))";
  unique_ptr<TreeNode<int>> root = MakeTree(s);
  vector<int> result = LevelOrderTraversal(root);
  for (auto i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
{
  // Test #2.
  // tree description: "()"
  // output: no output
  string s = "()";
  unique_ptr<TreeNode<int>> root = MakeTree(s);
  vector<int> result = LevelOrderTraversal(root);
  for (auto i: result) {
    cout << i << ' ';
  }
  cout << endl;
}
  return 0;
}
