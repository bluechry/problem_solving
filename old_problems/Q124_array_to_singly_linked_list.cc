// Given an array, make a singly-linked list contains all elements of the array.
// The order of elements in the list is the same as the order of elements in
// the array.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include <utility>
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
//
// Time Complexity: O(N), N is # of elements in the array.
//
// Space Complexity: O(N) for the linked list.

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

int main() {
{
  // Test #1.
  vector<int> vec{10, 20, 30, 40, 50, 60};
  shared_ptr<ListNode<int>> lst = CreateSinglyLinkedList(vec);
  DumpSinglyLinkedList(lst);
}
{
  // Test #2.
  vector<int> vec;
  shared_ptr<ListNode<int>> lst = CreateSinglyLinkedList(vec);
  DumpSinglyLinkedList(lst);
}
  return 0;
}
