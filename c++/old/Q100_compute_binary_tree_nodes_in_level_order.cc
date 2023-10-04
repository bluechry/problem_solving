// Given a binary tree, return an array consisting of the keys at the same
// level. Keys should appear in the order of the corresponding nodes' depths,
// breaking ties from left to right.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <queue>
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
//   2. queue에 저장된 node의 개수를 확인한다.
//   3. node 개수만큼 queue에서 node를 pop하고, pop할 때마다 그 node의
//      children을 queue에 push한다.
//   4. queue가 빌 때까지 2~4번과정을 반복한다.
//
// Time Complexity: O(N), N is # of nodes in the tree.
//
// Space Complexity: O(M), M is the max number of nodes in a level.
//                         if the tree is a perfect binary tree, M is N/2.

vector<vector<int>> GetLevelOrder(const unique_ptr<TreeNode<int>>& root) {
  // if root is empty, return an empty vector.
  vector<vector<int>> result;
  if (!root.get()) {
    return vector<vector<int>>();
  }

  queue<TreeNode<int>*> q;
  q.emplace(root.get());
  int num_nodes_in_level = q.size();
  vector<int> buffer;

  while (!q.empty()) {
    size_t num_nodes = q.size();
    while (num_nodes--) {
      auto* p = q.front();
      q.pop();
      buffer.emplace_back(p->value_);
      if (p->left_) {
        q.emplace(p->left_.get());
      }
      if (p->right_) {
        q.emplace(p->right_.get());
      }
    }
    result.emplace_back(move(buffer));
    buffer.clear();
  }
  return result;
}

int main() {
{
  // Test #1.
  // string: "(0(1(3()())(4()()))(2(5()())()))"
  // return value: {{0}, {1, 2}, {3, 4, 5}}
  string s = "(0(1(3()())(4()()))(2(5()())()))";
  unique_ptr<TreeNode<int>> root = MakeTree(s);
  vector<vector<int>> result = GetLevelOrder(root);
  for (auto& v: result) {
    for (int i: v) {
      cout << i << ' ';
    }
    cout << endl;
  }
}
{
  // Test #2.
  // string: "()"
  // return value: {}
  string s = "()";
  unique_ptr<TreeNode<int>> root = MakeTree(s);
  vector<vector<int>> result = GetLevelOrder(root);
  for (auto& v: result) {
    for (int i: v) {
      cout << i << ' ';
    }
    cout << endl;
  }
}
  return 0;
}
