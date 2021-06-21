// Write a program that takes the head of a singly linked list and returns null
// if there does not exist a cycle, and the node at the start of the cycle,
// if a cycle is present. (You do not know the length of the list in advance.)

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
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
//  * Q131에서 사용한 방법으로 list내의 cycle을 찾는다.
//  * List 내의 cycle이 존재하면,
//    1. Cycle의 길이를 구한다.
//    2. Slow cursor와 fast cursor를 list의 head로 설정하고,
//       fast cursor를 cycle의 길이만큼 앞으로 이동한다.
//    3. Slow cursor와 fast cursor가 만날 때까지 한 번씩 이동한다.
//    4. Slow cursor와 fast cursor가 만나는 node가 cycle이 시작하는 node다.
//
// Time Complexity: O(N), N is # of nodes in a linked list.
//
// Space Complexity: O(1)

shared_ptr<ListNode<int>> FindCycleEntryPoint(
    const shared_ptr<ListNode<int>>& lst) {
  auto slow = lst, fast = lst;
  while (fast && fast->next_) {
    slow = slow->next_;
    fast = fast->next_->next_;
    // If a cycle has been detected, find the entry point of the cycle.
    if (slow == fast) {
      // Get the length of the cycle.
      int length = 0;
      do {
        fast = fast->next_;
        ++length;
      } while (slow != fast);

      // Move the fast cursor forward by 'length' positions.
      slow = fast = lst;
      while (length--) {
        fast = fast->next_;
      }

      // Move until the slow and the fast cursors meet each other.
      while (slow != fast) {
        slow = slow->next_;
        fast = fast->next_;
      }
      return slow;
    }
  }
  return nullptr;
}

// Solution #2
//  * Q131에서 사용한 방법으로 list내의 cycle을 찾는다.
//  * List 내의 cycle이 존재하면,
//    1. Slow cursor를 list의 head로 설정한다.
//    2. Slow cursor와 fast cursor가 서로 만날 때까지 한 node씩 움직인다.
//    3. Slow cursor와 fast cursor가 만나는 node를 반환한다.
//
// Proof of Solution #2
//  Let L = the length of the cycle,
//      M = the length of sublist from the head to the entry of the cycle.
//      K = # of moves of the cursors
//      P = length of sublist from the entry of the cycle to the node that
//          two cursors met each other.
//
//      Prove that M = L - P.
//
//      Distances that the slow cursor moved, K = M + P       - (1)
//      Distances that the fast cursor moved, 2K = M + P + L  - (2)
//
//      (2) - (1): K = L  - (3)
//      (1) and (3): L = M + P
//
//      Therefore, M = L - P
//
// Time Complexity: O(N), N is # of nodes in a linked list.
//
// Space Complexity: O(1)

shared_ptr<ListNode<int>> FindCycleEntryPoint2(
    const shared_ptr<ListNode<int>>& lst) {
  auto slow = lst, fast = lst;
  while (fast && fast->next_) {
    slow = slow->next_;
    fast = fast->next_->next_;
    // If a cycle has been detected, find the entry point of the cycle.
    if (slow == fast) {
      // Set the slow cursor to the head of the list.
      slow = lst;

      // Move until the slow and the fast cursors meet each other.
      while (slow != fast) {
        slow = slow->next_;
        fast = fast->next_;
      }
      return slow;
    }
  }
  return nullptr;
}

int main() {
{
  // Test #1.
  // lst = {0, 1, 2, 3, 4, 5, 3} (cycle length = 4)
  // return value: 3
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4, 5});
  lst->next_->next_->next_->next_->next_ = lst->next_->next_->next_;
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << ' ';
  entry_point = FindCycleEntryPoint2(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
{
  // Test #2.
  // lst = {0, 0} (cycle length = 1)
  // return value: 0
  auto lst = CreateSinglyLinkedList({0});
  lst->next_ = lst;
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << ' ';
  entry_point = FindCycleEntryPoint2(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
{
  // Test #3.
  // lst = {0, 1, 2, 3, 4, 5} (cycle length = 0)
  // return value: -1
  auto lst = CreateSinglyLinkedList({0, 1, 2, 3, 4, 5});
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << ' ';
  entry_point = FindCycleEntryPoint2(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
{
  // Test #4.
  // lst = {} (cycle length = 0)
  // return value: -1
  auto lst = CreateSinglyLinkedList({});
  auto entry_point = FindCycleEntryPoint(lst);
  cout << (entry_point ? entry_point->data_ : -1) << ' ';
  entry_point = FindCycleEntryPoint2(lst);
  cout << (entry_point ? entry_point->data_ : -1) << endl;
}
  return 0;
}
