// Write a program which takes a singly linked list L and two integers s and f
// as arguments, and reverse the order of the nodes from the s-th node to f-th
// node, inclusive. The numbering begins at 1, i.e., the head node is the first
// node. Do not allocate additional nodes.

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

// Helper functions to create a singly linked list.
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

// Solution
//  1. 'start' node를 second_part_head node라하고, 'start' node의 앞 node를
//     first_part_tail node라고 하자.
//  2. first_part_tail node를 prev node로, second_part_head node를 cur node로
//     하여 Q129에서 썼던 방식대로 start node부터 end node까지의  node들을
//     reverse한다.
//  3. Node 하나를 reverse할 때마다 first_part_tail node는 cur node를 가리키고,
//     second_part_head node는 cur node의 다음 node를 가리키도록 한다.
//
// Time Complexity: O(f), f is the index of the f-th node.
//
// Space Complexity: O(1)

shared_ptr<ListNode<int>> ReverseSubList(const shared_ptr<ListNode<int>>& lst,
                                         int start,
                                         int end) {
  if (!lst || start == end) {
    return lst;
  }

  // 1. Find the tail of the first part of the list and the head of the second
  //    part of the list.
  auto dummy_head = shared_ptr<ListNode<int>>(new ListNode<int>({0, lst}));
  auto first_part_tail = dummy_head;
  int pos = 0;
  while (++pos < start) {
    first_part_tail = first_part_tail->next_;
  }
  auto second_part_head = first_part_tail->next_;

  // 2. Reverse the second part of the list.
  auto prev = first_part_tail;
  auto cur = second_part_head;
  while (start++ <= end) {
    auto next = cur->next_;
    cur->next_ = prev;
    first_part_tail->next_ = cur;
    second_part_head->next_ = next;
    prev = cur;
    cur = next;
  }
  return dummy_head->next_;
}

int main() {
{
  // Test #1.
  // lst = {1, 2, 3, 4, 5, 6, 7, 8}, start = 3, end = 6
  // result = {1, 2, 6, 5, 4, 3, 7, 8}
  auto lst = CreateSinglyLinkedList({1, 2, 3, 4, 5, 6, 7, 8});
  DumpSinglyLinkedList(lst);
  lst = ReverseSubList(lst, 3, 6);
  DumpSinglyLinkedList(lst);
  cout << endl;
}
{
  // Test #2.
  // lst = {1, 2, 3, 4, 5, 6, 7, 8}, start = 1, end = 8
  // result = {8, 7, 6, 5, 4, 3, 2, 1}
  auto lst = CreateSinglyLinkedList({1, 2, 3, 4, 5, 6, 7, 8});
  DumpSinglyLinkedList(lst);
  lst = ReverseSubList(lst, 1, 8);
  DumpSinglyLinkedList(lst);
  cout << endl;
}
{
  // Test #3.
  // lst = {1, 2, 3, 4, 5, 6, 7, 8}, start = 4, end = 4
  // result = {1, 2, 3, 4, 5, 6, 7, 8};
  auto lst = CreateSinglyLinkedList({1, 2, 3, 4, 5, 6, 7, 8});
  DumpSinglyLinkedList(lst);
  lst = ReverseSubList(lst, 4, 4);
  DumpSinglyLinkedList(lst);
  cout << endl;
}
{
  // Test #4.
  // lst = {}, start = 0, end = 0
  // result = {}
  auto lst = CreateSinglyLinkedList({});
  DumpSinglyLinkedList(lst);
  lst = ReverseSubList(lst, 0, 0);
  DumpSinglyLinkedList(lst);
  cout << endl;
}
  return 0;
}
