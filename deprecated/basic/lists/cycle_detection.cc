// Write a program that takes the head of a singly linked list and returns null
// if there does not exist a cycle, and the node at the start of the cycle,
// if a cycle is present. (You do not know the length of the list in advance.)

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//}}}

//
// Helper functions for creating a linked list.
//
//{{{
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
//}}}

// Solution
// Finding a cycle:
//   Use two iterators, one moves one node at a time and the other moves two
//   nodes at a time. If the two iterators meet each other, a cycle must exist.
// 
// Finding a start node of the cycle:
//   Use new two iterators, one starts at where the slow and fast iterators have
//   met each other in the cycle detection process, the other starts at the
//   first node of the list. Both iterators move one node at a time. The node
//   where the two iterators meet each other is the start node of the cycle.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

template<typename T>
shared_ptr<ListNode<T>> FindCycleEntryPoint(
  const shared_ptr<ListNode<T>>& lst) {
  auto slow = lst, fast = lst;
  while (fast && fast->next_) {
    slow = slow->next_;
    fast = fast->next_->next_;
    if (slow == fast) {
      fast = lst;
      while (slow != fast) {
        slow = slow->next_;
        fast = fast->next_;
      }
      return slow;
    }
  }
  return nullptr;
}

//{{{
int main() {
{
  // Test #1.
  // lst = {0, 1, 2, 3, 4, 5, 3} (cycle length = 4)
  // return value: 3
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4, 5});
  lst->next_->next_->next_->next_->next_ = lst->next_->next_->next_;
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
{
  // Test #2.
  // lst = {0, 0} (cycle length = 1)
  // return value: 0
  auto lst = CreateSinglyLinkedList({0});
  lst->next_ = lst;
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
{
  // Test #3.
  // lst = {0, 1, 2, 3, 4, 5} (cycle length = 0)
  // return value: -1
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4, 5});
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
{
  // Test #4.
  // lst = {} (cycle length = 0)
  // return value: -1
  auto lst = CreateSinglyLinkedList({});
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
  return 0;
}
//}}}
