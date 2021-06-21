// Write a function that reverse a singly linked list. The function should use
// no more than constant storage beyond that needed for the list itself.

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

//
// Helper functions for creating a linked list.
//

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

// Solution #1
//  Recursion을 사용하여 list를 뒤집어보자.
//  List의 첫 node인 head를 제외한 나머지 node를 뒤집은 후,
//  뒤집힌 list의 마지막 node(즉, head->next)의 next를 head로 지정한다.
//
// Time Complexity: O(N), N is # of nodes in a list.
//
// Space Complexity: O(N) for recursion stack.

shared_ptr<ListNode<int>> ReverseLinkedList(
    const shared_ptr<ListNode<int>>& head) {
  if (!head || !head->next_) {
    return head;
  }
  auto rev_lst = ReverseLinkedList(head->next_);
  head->next_->next_ = head;
  head->next_ = nullptr;
  return rev_lst;
}

// Solution #2
//  Space complexity를 O(1)으로 낮추기 위해서 iteration을 사용하여 list를
//  뒤집는다.
//  List를 scan하면서 current node의 next를 previous node로 바꾸어주면 된다.
//  중요한 것은 계속해서 list를 scan해야하므로, current node의 next를
//  update하기 전에 current node의 next node를 기록해 두어야 한다.
//
// Time Complexity: O(N), N is # of nodes in a list.
//
// Space Complexity: O(1)

shared_ptr<ListNode<int>> ReverseLinkedList2(
    const shared_ptr<ListNode<int>>& head) {
  shared_ptr<ListNode<int>> prev = nullptr, cur = head;
  while (cur) {
    auto next = cur->next_;
    cur->next_ = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int main() {
{
  // Test #1.
  vector<int> vec{10, 20, 30, 40, 50, 60};
  shared_ptr<ListNode<int>> lst = CreateSinglyLinkedList(vec);
  DumpSinglyLinkedList(lst);

  lst = ReverseLinkedList(lst);
  DumpSinglyLinkedList(lst);

  lst = ReverseLinkedList2(lst);
  DumpSinglyLinkedList(lst);
}
{
  // Test #2.
  vector<int> vec;
  shared_ptr<ListNode<int>> lst = CreateSinglyLinkedList(vec);
  DumpSinglyLinkedList(lst);

  lst = ReverseLinkedList(lst);
  DumpSinglyLinkedList(lst);

  lst = ReverseLinkedList2(lst);
  DumpSinglyLinkedList(lst);
}
  return 1;
}
