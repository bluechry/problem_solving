// Write a program that takes the head of a singly linked list and returns
// true if a cycle is present and returns false if a cycle does not exist.

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
// Helper functions for creating a singly linked list.
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

// Solution
//
// Time Complexity
//
// Space Complexity

bool FindCycle(shared_ptr<ListNode<int>> lst) {
  auto slow = lst, fast = lst;
  while (fast && fast->next_) {
    slow = slow->next_;
    fast = fast->next_->next_;
    if (slow == fast) {
      return true;
    }
  }
  return false;
}

int main() {
{
  // Test #1.
  // lst = {0, 1, 2, 3, 4, 5, 3} (cycle length = 4)
  // return value: true
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4, 5});
  lst->next_->next_->next_->next_->next_ = lst->next_->next_->next_;
  cout << (FindCycle(lst) ? "there is a cycle." : "no cycle.") << endl;
}
{
  // Test #2.
  // lst = {0, 0} (cycle length = 1)
  // return value: true
  auto lst = CreateSinglyLinkedList({0});
  lst->next_ = lst;
  cout << (FindCycle(lst) ? "there is a cycle." : "no cycle.") << endl;
}
{
  // Test #3.
  // lst = {0, 1, 2, 3, 4, 5} (cycle length = 0)
  // return value: false
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4, 5});
  cout << (FindCycle(lst) ? "there is a cycle." : "no cycle.") << endl;
}
{
  // Test #4.
  // lst = {} (cycle length = 0)
  // return value: false
  auto lst = CreateSinglyLinkedList({});
  cout << (FindCycle(lst) ? "there is a cycle." : "no cycle.") << endl;
}
  return 0;
}
