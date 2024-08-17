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

// Solution #1
// A node is the lowest common ancestor if
// * Both two nodes are found in the left and the right subtrees.
// * One of the two nodes are found in the left or right subtree and
//   the other node are found in the root node.
//
// Time Complexity: O(N), N is the number of tree nodes.
//
// Space Complexity: O(h), h is the height of the tree.

shared_ptr<TreeNode<int>> FindLCA(shared_ptr<TreeNode<int>> root,
                                  shared_ptr<TreeNode<int>> node0,
                                  shared_ptr<TreeNode<int>> node1) {
#if 1  // straight implementation of the solution.
  if (!root) {
    return nullptr;
  }
  auto left_result = FindLCA(root->left_, node0, node1);
  auto right_result = FindLCA(root->right_, node0, node1);
  if (left_result && right_result) {
    return root;
  }
  if ((left_result || right_result) && (root == node0 || root == node1)) {
    return root;
  } else if (root == node0 || root == node1) {
    return root;
  }
  return left_result ? left_result : right_result;
#else  // short version of the previous code.
  if (!root) {
    return nullptr;
  }
  auto left_result = FindLCA(root->left_, node0, node1);
  auto right_result = FindLCA(root->right_, node0, node1);
  if (left_result && right_result) {
    return root;
  }
  if (root == node0 || root == node1) {
    return root;
  }
  return left_result ? left_result : right_result;
#endif
}

// Solution #2
// Count the number of matched nodes in the two subtrees and
// * return a lca of a subtree which has match count == 2.
// * return the current node if one of the subtrees has match count == 1 and
//   one of the given nodes are match to root.
//
// Time Complexity: O(N), N is the number of tree nodes.
//
// Space Complexity: O(h), h is the height of the tree.

struct Status {
  shared_ptr<TreeNode<int>> result_;
  int num_matched_;
};

Status HelpFindLCA2(shared_ptr<TreeNode<int>> root,
                shared_ptr<TreeNode<int>> node0,
                shared_ptr<TreeNode<int>> node1) {
  if (!root) {
    return Status{nullptr, 0};
  }

  Status left_result = HelpFindLCA2(root->left_, node0, node1);
  if (left_result.num_matched_ == 2) {
    return left_result;
  }

  Status right_result = HelpFindLCA2(root->right_, node0, node1);
  if (right_result.num_matched_ == 2) {
    return right_result;
  }

  int num_matched = left_result.num_matched_ + right_result.num_matched_ +
                    (root == node0) + (root == node1);
  return Status{(num_matched == 2) ? root : nullptr, num_matched};
}

shared_ptr<TreeNode<int>> FindLCA2(shared_ptr<TreeNode<int>> root,
                                   shared_ptr<TreeNode<int>> node0,
                                   shared_ptr<TreeNode<int>> node1) {
  Status result = HelpFindLCA2(root, node0, node1);
  return result.result_;
}


//{{{
int main() {
{
  // Test #1.
  // tree: "(0(1(3()())(4()()))(2(5()())()))"
  // (node0, node1) = (1, 3)
  // return: 0
  string s = "(0(1(3()())(4()()))(2(5()())()))";
  shared_ptr<TreeNode<int>> root = MakeTree(s);
  auto lca = FindLCA(root, root->left_, root->right_);
  cout << "lca of 1 and 3: " << lca->value_ << endl;
  lca = FindLCA2(root, root->left_, root->right_);
  cout << "lca of 1 and 3: " << lca->value_ << endl;

  // Test #2.
  // tree: the same as above
  // (node0, node1) = (3, 4)
  // return: 1
  lca = FindLCA(root, root->left_->left_, root->left_->right_);
  cout << "lca of 3 and 4: " << lca->value_ << endl;
  lca = FindLCA2(root, root->left_->left_, root->left_->right_);
  cout << "lca of 3 and 4: " << lca->value_ << endl;

  // Test #3.
  // tree: the same as above
  // (node0, node1) = (2, 5)
  // return: 2
  lca = FindLCA(root, root->right_, root->right_->left_);
  cout << "lca of 2 and 5: " << lca->value_ << endl;
  lca = FindLCA2(root, root->right_, root->right_->left_);
  cout << "lca of 2 and 5: " << lca->value_ << endl;

  // Test #4.
  // tree: the same as above
  // (node0, node1) = (1, 5)
  // return: 0
  lca = FindLCA(root, root->left_, root->right_->left_);
  cout << "lca of 1 and 5: " << lca->value_ << endl;
  lca = FindLCA2(root, root->left_, root->right_->left_);
  cout << "lca of 1 and 5: " << lca->value_ << endl;

  // Test #5.
  // tree: the same as above
  // (node0, node1) = (1, 1)
  // return: 1
  lca = FindLCA(root, root->left_, root->left_);
  cout << "lca of 1 and 1: " << lca->value_ << endl;
  lca = FindLCA2(root, root->left_, root->left_);
  cout << "lca of 1 and 1: " << lca->value_ << endl;
}
{
  // Test #6.
  // string: "()"
  // return value: {}
  string s = "()";
  shared_ptr<TreeNode<int>> root = MakeTree(s);
  auto lca = FindLCA(root, nullptr, nullptr);
  cout << "lca of null: " << (!lca ? "nullptr" : to_string(lca->value_)) << endl;
  lca = FindLCA2(root, nullptr, nullptr);
  cout << "lca of null: " << (!lca ? "nullptr" : to_string(lca->value_)) << endl;
}
  return 0;
}
//}}}
