// Write a program that takes two lists which contains numbers, assumed to be
// sorted, and returns their merge. The only field your program can change in
// a node is its next field.

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

// Solution
//   Mergesort에서 두 개의 sorted array를 merge하는 것과 동일한 방법을 사용한다.
//   첫번째 리스트와 두번째 리스트 각각에 cursor를 두고 각 cursor가 가리키는
//   원소의 크기를 비교한 후에 작은 원소를 결과 리스트의 끝에 append한다.
//   원소의 크기가 같을 경우 첫번째 리스트의 원소를 결과 리스트의 끝에
//   append한다.
//
// Time Complexity: O(N + M), N is # of elements in the first list.
//                            M is # of elements in the second list.
//
// Space Complexity: O(1), no extra nodes.

template<typename T>
struct ListNode {
  int data_;
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

shared_ptr<ListNode<int>> MergeTwoSortedLists(
    shared_ptr<ListNode<int>> first,
    shared_ptr<ListNode<int>> second) {
  // Create a placeholder for the merged list.
  shared_ptr<ListNode<int>> dummy(new ListNode<int>());
  shared_ptr<ListNode<int>> tail = dummy;

  // Merge two sorted lists.
  while (first && second) {
    if (first->data_ <= second->data_) {
      tail->next_ = first;
      first = first->next_;
    } else {
      tail->next_ = second;
      second = second->next_;
    }
    tail = tail->next_;
  }
  tail->next_ = (first) ? first : second;

  // Return the merged list.
  return dummy->next_;
}

int main() {
{
  // Test #1.
  // first list = {1, 3, 5, 7, 9}
  // second list = {2, 4, 6, 8, 10}
  // result list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  shared_ptr<ListNode<int>> first = CreateSinglyLinkedList({1, 3, 5, 7, 9});
  shared_ptr<ListNode<int>> second = CreateSinglyLinkedList({2, 4, 6, 8, 10});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpSinglyLinkedList(result);
}
{
  // Test #2.
  // first list = {1, 2, 3, 4, 5}
  // second list = {6, 7, 8, 9, 10}
  // result list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  shared_ptr<ListNode<int>> first = CreateSinglyLinkedList({1, 2, 3, 4, 5});
  shared_ptr<ListNode<int>> second = CreateSinglyLinkedList({6, 7, 8, 9, 10});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpSinglyLinkedList(result);
}
{
  // Test #3.
  // first list = {1, 2, 3, 4, 5}
  // second list = {}
  // result list = {1, 2, 3, 4, 5}
  shared_ptr<ListNode<int>> first = CreateSinglyLinkedList({1, 2, 3, 4, 5});
  shared_ptr<ListNode<int>> second = CreateSinglyLinkedList({});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpSinglyLinkedList(result);
}
{
  // Test #4.
  // first list = {}
  // second list = {6, 7, 8, 9, 10}
  // result list = {6, 7, 8, 9, 10}
  shared_ptr<ListNode<int>> first = CreateSinglyLinkedList({});
  shared_ptr<ListNode<int>> second = CreateSinglyLinkedList({6, 7, 8, 9, 10});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpSinglyLinkedList(result);
}
{
  // Test #5.
  // first list = {}
  // second list = {}
  // result list = {}
  shared_ptr<ListNode<int>> first = CreateSinglyLinkedList({});
  shared_ptr<ListNode<int>> second = CreateSinglyLinkedList({});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpSinglyLinkedList(result);
}
  return 0;
}
