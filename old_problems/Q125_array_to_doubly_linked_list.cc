// Given an array, make a doubly-linked list contains all elements of the array.
// The order of elements in the list is the same as the order of elements in
// the array.

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
//   주어진 배열의 원소를 하나씩 읽을 때마다 새로운 list node를 생성하여
//   결과로 반환될 list의 끝에 append한다.
//   Q124의 singly-linked list와는 다르게 새로운 linst node의 prev pointer는
//   기존 결과 list의 마지막 원소를 가리켜야한다.
//
// Time Complexity: O(N), N is # of elements in the array.
//
// Space Complexity: O(N) for the linked list.

template<typename T>
struct ListNode {
  T data_;
  shared_ptr<ListNode<T>> prev_;
  shared_ptr<ListNode<T>> next_;
};

shared_ptr<ListNode<int>> CreateDoublyLinkedList(const vector<int>& elems) {
  shared_ptr<ListNode<int>>
      dummy_header(new ListNode<int>({-1, nullptr, nullptr}));
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

int main() {
{
  // Test #1.
  vector<int> vec{10, 20, 30, 40, 50, 60};
  shared_ptr<ListNode<int>> lst = CreateDoublyLinkedList(vec);
  DumpDoublyLinkedList(lst);
  DumpDoublyLinkedListRev(lst);
}
{
  // Test #2.
  vector<int> vec;
  shared_ptr<ListNode<int>> lst = CreateDoublyLinkedList(vec);
  DumpDoublyLinkedList(lst);
  DumpDoublyLinkedListRev(lst);
}
  return 0;
}
