// Write a program which deletes a node in a singly linked list. The input node
// is guaranteed not to be the tail node.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Helper functions to create a linked list.

template<typename T>
struct ListNode {
  T data_;
  shared_ptr<ListNode<T>> next_;
};

shared_ptr<ListNode<int>> CreateSinglyLinkedList(const vector<int>& elems) {
  shared_ptr<ListNode<int>> dummy_head(new ListNode<int>({-1, nullptr}));
  shared_ptr<ListNode<int>> tail = dummy_head;

  for (int i: elems) {
    ListNode<int>* node = new ListNode<int>({i, nullptr});
    tail->next_ = shared_ptr<ListNode<int>>(node);
    tail = tail->next_;
  }
  return dummy_head->next_;
}

void DumpSinglyLinkedList(const shared_ptr<ListNode<int>>& lst) {
  shared_ptr<ListNode<int>> cur = lst;
  while (cur) {
    cout << cur->data_ << ' ';
    cur = cur->next_;
  }
  cout << ' ' << endl;
}

// Solution:
//   del_node가 가리키는 node의 이전 node를 알 수 없으므로 del_node를 지울 수는
//   없다. del_node를 지우는 대신에 next node의 data를 del_node로 복사하고
//   next node를 지운다.
//
//   next node는 shared pointer에 의해 참조되므로 next node를 삭제할 때
//   next node의 next_ pointer를 reset할 필요가 없고,
//   next node를 exlicit하게 delete할 필요도 없다.
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

void DeleteNodeFromLinkedList(const shared_ptr<ListNode<int>>& del_node) {
  del_node->data_ = del_node->next_->data_;
  del_node->next_ = del_node->next_->next_;
}

int main() {
  // Test #1.
  // lst = {0, 1, 2, 3, 4}, del_node = 3
  // return result = {0, 1, 2, 4}
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4});
  DumpSinglyLinkedList(lst);
  DeleteNodeFromLinkedList(lst->next_->next_->next_);
  DumpSinglyLinkedList(lst);

  // Test #2.
  // lst = {0, 1, 2, 4}, del_node = 0
  // return result = {1, 2, 4}
  DeleteNodeFromLinkedList(lst);
  DumpSinglyLinkedList(lst);
  return 0;
}
