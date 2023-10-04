// Implement list data structure using singly-linked list.
// The list structure should provide a proper iterator type.

//{{{
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
//}}}

template<typename T>
class ListIterator;

template<typename T>
class List;

template<typename T>
class ListNode {
 public:
  ListNode():
    elem_(T()),
    next_(nullptr) {
  }

  ListNode(const T& elem, shared_ptr<ListNode<T>> next):
    elem_(elem),
    next_(next) {
  }

 private:
  friend class ListIterator<T>;
  friend class List<T>;

  T elem_;
  shared_ptr<ListNode<T>> next_;
};

template<typename T>
class ListIterator: public iterator<forward_iterator_tag, T> {
 public:
  // Constructors.
  ListIterator(shared_ptr<ListNode<T>> ptr):
    ptr_(ptr) {
  }

  ListIterator(const ListIterator<T>& iter):
    ptr_(iter.ptr_) {
  }

  // Assignment operator.
  ListIterator<T>& operator=(const ListIterator<T>& iter) {
    this->ptr_ = iter.ptr_;
    return *this;
  }

  // Dereference operator.
  T& operator*() const {
    return ptr_->elem_;
  }

  // Member access operator.
  T* operator->() const {
    return &(ptr_->elem_);
  }

  // Increment operators.
  ListIterator<T>& operator++() {  // ++it
    ptr_ = ptr_->next_;
    return *this;
  }

  ListIterator<T>& operator++(int dummy) {  // it++
    ListIterator<T> result = *this;
    ptr_ = ptr_->next_;
    return result;
  }

  ListIterator<T>& operator+=(size_t offset) {
    while (offset--) {
      ptr_ = ptr_->next_;
    }
    return *this;
  }

  // Equality operators.
  bool operator==(const ListIterator<T>& iter) {
    return ptr_ == iter.ptr_;
  }

  bool operator!=(const ListIterator<T>& iter) {
    return ptr_ != iter.ptr_;
  }

 private:
  friend class List<T>;

  shared_ptr<ListNode<T>> ptr_;
};

template<typename T>
class List {
 public:
  using Iterator = ListIterator<T>;

  // Create an empty linked list that contains a dummy node.
  List(): num_elems_(0) {
    head_ = tail_ = make_shared<ListNode<T>>();
  }

  // Add an element at the end of the list.
  void PushBack(const T& elem) {
    if (head_ == tail_) {
      head_ = make_shared<ListNode<T>>(elem, head_);
    } else {
      shared_ptr<ListNode<T>> cur = head_;
      while (cur->next_ != tail_) {
        cur = cur->next_;
      }
      cur->next_ = make_shared<ListNode<T>>(elem, cur->next_);
    }
    ++num_elems_;
  }

  // Remove an element at the end of the list.
  void PopBack() {
    if (head_ == tail_) {
      throw length_error("list is empty");
    }
    if (head_->next_ == tail_) {
      head_->next_ = nullptr;
      head_ = tail_;
    } else {
      shared_ptr<ListNode<T>> cur = head_;
      while (cur->next_->next_ != tail_) {
        cur = cur->next_;
      }
      shared_ptr<ListNode<T>>& del_node = cur->next_;
      cur->next_ = tail_;
      del_node->next_ = nullptr;
    }
    --num_elems_;
  }

  // Add an element at the front of the list.
  void PushFront(const T& elem) {
    head_ = make_shared<ListNode<T>>(elem, head_);
    ++num_elems_;
  }

  // Remove an element at the front of the list.
  void PopFront() {
    if (head_ == tail_) {
      throw length_error("list is empty.");
    }
    shared_ptr<ListNode<T>> del_node = head_;
    head_ = head_->next_;
    del_node->next_ = nullptr;
    --num_elems_;
  }

  // Insert the element right after the element the iterator points to and
  // return the iterator points to the inserted element.
  // When the iterator is end() iterator, we should check the following
  // condition:
  // * if the list is not empty, throw an exception.
  // * if the list is empty, insert new element.
  Iterator Insert(Iterator pos, const T& elem) {
    shared_ptr<ListNode<T>> cur = pos.ptr_;
    if (cur != tail_) {
      cur->next_ = make_shared<ListNode<T>>(elem, cur->next_);
      ++num_elems_;
      return Iterator(cur->next_);
    } else if (cur == head_) {
      head_ = make_shared<ListNode<T>>(elem, head_);
      ++num_elems_;
      return Iterator(head_);
    } else {
      throw invalid_argument("invalid iterator");
    }
  }

  // Remove the element right after the element the iterator points to and
  // return the iterator.
  // If the iterator is the end() iterator, throw exception.
  // When the iterator points to the last element, we should check the following
  // condition:
  // * if the list has two or more elements, throw an exception.
  // * if the list has only one element, remove it. In this case, return end()
  //   iterator.
  Iterator Erase(Iterator pos) {
    shared_ptr<ListNode<T>> cur = pos.ptr_;
    if (cur == tail_) {
      throw invalid_argument("invalid iterator.");
    }
    if (cur->next_ == tail_) {
      if (cur == head_) {
        head_->next_ = nullptr;
        head_ = tail_;
        --num_elems_;
        return Iterator(tail_);
      } else {
        throw invalid_argument("invalid iterator.");
      }
    } else {
      shared_ptr<ListNode<T>> del_node = cur->next_;
      cur->next_ = cur->next_->next_;
      del_node->next_ = nullptr;
      --num_elems_;
      return pos;
    }
  }

  // Check whether the list is empty or not.
  bool Empty() const {
    return (num_elems_ == 0);
  }

  // Get the # of elements.
  size_t Size() const {
    return num_elems_;
  }

  // Return an iterator that points to the first element.
  Iterator Begin() {
    return Iterator(head_);
  }

  // Return an iterator that points to the last element.
  Iterator End() {
    return Iterator(tail_);
  }

  // Dump list.
  void Dump() {
    shared_ptr<ListNode<T>> cur = head_;
    while (cur != tail_) {
      cout << cur->elem_ << ' ';
      cur = cur->next_;
    }
    cout << endl;
  }

 private:
  shared_ptr<ListNode<T>> head_;
  shared_ptr<ListNode<T>> tail_;
  size_t num_elems_;
};

//{{{
int main() {
{
  // Test #1
  cout << '\n' << "Test #1 - test empty list." << endl;
  List<int> lst;
  cout << "Is empty: " << (lst.Empty() ? "true" : "false") << endl;
  cout << "Size: " << lst.Size() << endl;
  cout << "Scanning: ";
  lst.Dump();

  cout << "Pop front: ";
  try {
    lst.PopFront();
  } catch (exception& e) {
    cout << e.what() << endl;
  }

  cout << "Pop back: ";
   try {
    lst.PopFront();
  } catch (exception& e) {
    cout << e.what() << endl;
  }
}
{
  // Test #2
  cout << '\n' << "Test #2 - test insertion." << endl;
  List<int> lst;
  cout << "push back {6, 7, 8, 9, 10}: ";
  for (int i = 6; i <= 10; ++i) {
    lst.PushBack(i);
  }
  lst.Dump();

  cout << "Size(): " << lst.Size() << endl;
  cout << "push front {5, 4, 3, 2, 1}: ";
  for (int i = 5; i >= 1; --i) {
    lst.PushFront(i);
  }
  lst.Dump();

  cout << "insert after End() iterator: ";
  try {
    List<int>::Iterator it = lst.End();
    lst.Insert(it, 100);
  } catch (exception& e) {
    cout << e.what() << endl;
  }

  cout << "insert after Begin() iteratror: ";
  List<int>::Iterator it = lst.Begin();
  it = lst.Insert(it, 100);
  lst.Dump();

  cout << "insert after '3': ";
  it += 2;
  it = lst.Insert(it, 300);
  lst.Dump();
}
{
  // Test #3
  cout << '\n' << "Test #3 - test deletion." << endl;
  cout << "list: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}" << endl;
  List<int> lst;
  for (int i = 1; i <= 10; ++i) {
    lst.PushBack(i);
  }
  lst.Dump();

  cout << "pop front." << endl;
  lst.PopFront();
  lst.Dump();
  cout << "Size: " << lst.Size() << endl;

  cout << "pop back." << endl;
  lst.PopBack();
  lst.Dump();
  cout << "Size: " << lst.Size() << endl;

  cout << "erase '3'." << endl;
  List<int>::Iterator it = lst.Begin();
  it = lst.Erase(it);
  lst.Dump();
  cout << "Size: " << lst.Size() << endl;

  cout << "erase '6'." << endl;
  it += 2;
  it = lst.Erase(it);
  lst.Dump();
  cout << "Size: " << lst.Size() << endl;

  cout << "erase next of the last element: ";
  try {
    it = lst.End();
    lst.Erase(it);
  } catch (exception& e){
    cout << e.what() << endl;
  }
}
{
  // Test #4
  cout << '\n' << "Test #4 - test iterator." << endl;
  cout << "list: {}" << endl;
  cout << "insert {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} using iterator." << endl;
  List<int> lst;
  List<int>::Iterator it = lst.Begin();
  for (int i = 1; i <= 10; ++i) {
    it = lst.Insert(it, i);
  }
  cout << "scanning using iterator: " << endl;
  for (auto it = lst.Begin(); it != lst.End(); ++it) {
    cout << *it << ' ';
  }
  cout << endl;

  cout << "delete at end() iterator: ";
  try {
    it = lst.End();
    lst.Erase(it);
  } catch (exception& e) {
    cout << e.what() << endl;
  }

  cout << "delete {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} using iterator." << endl;
  it = lst.Begin();
  while (!lst.Empty()) {
    it = lst.Erase(it);
  }
  cout << "list dump: ";
  lst.Dump();
}
  return 0;
}
//}}}
