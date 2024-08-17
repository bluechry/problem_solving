// Given a binary tree, return the level-order traversal of its nodes' values.
// Ouput is a vector of vectors. Each vector contains the nodes' values at the
// same level.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
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
// Queueing and returning nodes level by level.
// 1. Push the root node to a queue.
// 2. Get the number of nodes in the queueu.
// 3. While poping every node from the queue one by one,
//    push children of each node to the queue.
// 4. While the queue is not empty, repeat step #2-#4.
//
// Time Complexity: O(N)
//
// Space Complexity: O(M), M is the maximum number of nodes in a same depth.
//                   In a full binary tree, M = N / 2.

vector<vector<int>> LevelOrderTraversal(shared_ptr<TreeNode<int>> root) {
  vector<vector<int>> result;
  if (!root) {
    return result;
  }

  queue<shared_ptr<TreeNode<int>>> node_queue;
  node_queue.emplace(root);
  vector<int> buffer;
  while (!node_queue.empty()) {
    int num_nodes = node_queue.size();
    while (num_nodes--) {
      auto temp = node_queue.front();
      buffer.push_back(temp->value_);
      node_queue.pop();
      if (temp->left_) {
        node_queue.emplace(temp->left_);
      }
      if (temp->right_) {
        node_queue.emplace(temp->right_);
      }
    }
    result.emplace_back(std::move(buffer));
    buffer.clear();
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
  vector<vector<int>> result = LevelOrderTraversal(root);
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
  shared_ptr<TreeNode<int>> root = MakeTree(s);
  vector<vector<int>> result = LevelOrderTraversal(root);
  for (auto& v: result) {
    for (int i: v) {
      cout << i << ' ';
    }
    cout << endl;
  }
}
  return 0;
}
//}}}
