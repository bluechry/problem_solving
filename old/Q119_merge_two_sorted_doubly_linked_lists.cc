// Solve Q118 when the lists are doubly linked.

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

// Definition of the list node for doubly-linked list.
template<typename T>
struct ListNode {
  T data_;
  shared_ptr<ListNode<T>> prev_;
  shared_ptr<ListNode<T>> next_;
};

//
// Helper functions for tests.
//
shared_ptr<ListNode<int>> CreateDoublyLinkedList(const vector<int>& elems) {
  shared_ptr<ListNode<int>> dummy_header(new ListNode<int>());
  shared_ptr<ListNode<int>> tail = dummy_header;

  for (int e: elems) {
    ListNode<int>* node = new ListNode<int>({e, tail, nullptr});
    tail->next_ = shared_ptr<ListNode<int>>(node);
    tail = tail->next_;
  }
  dummy_header = dummy_header->next_;
  if (dummy_header) {
    dummy_header->prev_ = nullptr;
  }
  return dummy_header;
}

void DumpDoublyLinkedList(shared_ptr<ListNode<int>> lst) {
  while (lst) {
    cout << lst->data_ << ' ';
    lst = lst->next_;
  }
  cout << endl;
}

void DumpDoublyLinkedListRev(shared_ptr<ListNode<int>> lst) {
  shared_ptr<ListNode<int>> cur = nullptr;
  while (lst) {
    cur = lst;
    lst = lst->next_;
  }
  while (cur) {
    cout << cur->data_ << ' ';
    cur = cur->prev_;
  }
  cout << endl;
}

// Solution
//   Mergesort에서 두 개의 sorted array를 merge하는 것과 동일한 방법을 사용한다.
//   첫번째 리스트와 두번째 리스트 각각에 cursor를 두고 각 cursor가 가리키는
//   원소의 크기를 비교한 후에 작은 원소를 결과 리스트의 끝에 append한다.
//   원소의 크기가 같을 경우 첫번째 리스트의 원소를 결과 리스트의 끝에
//   append한다.
//
//   Q118과는 다르게 doubly-linked list를 사용하므로 각 node를 merge할 때
//   각 node의 prev pointer를 정확하게 설정해주어야 한다.
//
// Time Complexity: O(N + M), N is # of elements in the first list.
//                            M is # of elements in the second list.
//
// Space Complexity: O(1), no extra node.

shared_ptr<ListNode<int>> MergeTwoSortedLists(
    shared_ptr<ListNode<int>> first,
    shared_ptr<ListNode<int>> second) {
  // Craete a placeholder for the merget list.
  shared_ptr<ListNode<int>>
      dummy_head(new ListNode<int>({-1, nullptr, nullptr}));
  shared_ptr<ListNode<int>> tail = dummy_head;

  // Merge two sorted lists.
  while (first && second) {
    if (first->data_ <= second->data_) {
      tail->next_ = first;
      first->prev_= tail;
      first = first->next_;
    } else {
      tail->next_ = second;
      second->prev_ = tail;
      second = second->next_;
    }
    tail = tail->next_;
  }
  if (first) {
    tail->next_ = first;
    first->prev_ = tail;
  } else if (second) {
    // 'else {}'를 썼다면 second가 nullptr일 때 second->prev에서 SIGSEGV 발생
    tail->next_ = second;
    second->prev_ = tail;
  }

  // Return the merged list.
  dummy_head = dummy_head->next_;
  if (dummy_head) {
    dummy_head->prev_ = nullptr;
  }
  return dummy_head;
}

int main() {
{
  // Test #1.
  // first list = {1, 3, 5, 7, 9}
  // second list = {2, 4, 6, 8, 10}
  // result list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  shared_ptr<ListNode<int>> first = CreateDoublyLinkedList({1, 3, 5, 7, 9});
  shared_ptr<ListNode<int>> second = CreateDoublyLinkedList({2, 4, 6, 8, 10});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpDoublyLinkedList(result);
  DumpDoublyLinkedListRev(result);
}
{
  // Test #2.
  // first list = {1, 2, 3, 4, 5}
  // second list = {6, 7, 8, 9, 10}
  // result list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  shared_ptr<ListNode<int>> first = CreateDoublyLinkedList({1, 2, 3, 4, 5});
  shared_ptr<ListNode<int>> second = CreateDoublyLinkedList({6, 7, 8, 9, 10});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpDoublyLinkedList(result);
  DumpDoublyLinkedListRev(result);
}
{
  // Test #3.
  // first list = {1, 2, 3, 4, 5}
  // second list = {}
  // result list = {1, 2, 3, 4, 5}
  shared_ptr<ListNode<int>> first = CreateDoublyLinkedList({1, 2, 3, 4, 5});
  shared_ptr<ListNode<int>> second = CreateDoublyLinkedList({});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpDoublyLinkedList(result);
  DumpDoublyLinkedListRev(result);
}
{
  // Test #4.
  // first list = {}
  // second list = {6, 7, 8, 9, 10}
  // result list = {6, 7, 8, 9, 10}
  shared_ptr<ListNode<int>> first = CreateDoublyLinkedList({});
  shared_ptr<ListNode<int>> second = CreateDoublyLinkedList({6, 7, 8, 9, 10});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpDoublyLinkedList(result);
  DumpDoublyLinkedListRev(result);
}
{
  // Test #5.
  // first list = {}
  // second list = {}
  // result list = {}
  shared_ptr<ListNode<int>> first = CreateDoublyLinkedList({});
  shared_ptr<ListNode<int>> second = CreateDoublyLinkedList({});
  shared_ptr<ListNode<int>> result = MergeTwoSortedLists(first, second);
  DumpDoublyLinkedList(result);
  DumpDoublyLinkedListRev(result);
}
  return 0;
}
