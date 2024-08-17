// Implement an unordered map using a linked list. Here is a declaration of
// unordered map class. You may implement eager deletion for Erase() and
// you don't need to consider the invalidation of the existing iterators.
/*
template<typename K, typename V>
class UnorderedMap {
 public:
  using ValueType = pair<K, V>;
  using Iterator = typename list<ValueType>::iterator;

  // You don't need to implement constructors and assignment operators.
  UnorderedMap() = default;
  UnorderedMap(const UnorderedMap&) = delete;
  UnorderedMap(UnorderedMap&&) = delete;
  UnorderedMap& operator=(const UnorderedMap&) = delete;
  UnorderedMap& operator=(UnorderedMap&&) = delete;

  V& operator[](const K& key);
  void Erase(const K& key);
  void Erase(const Iterator& iter);
  bool Empty() const;
  size_t Size() const;
  Iterator Begin();
  Iterator End();
  Iterator Find(const K& key);
};
*/

#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>

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

template<typename K, typename V>
class UnorderedMap {
 public:
  using ValueType = pair<K, V>;
  using Iterator = typename list<ValueType>::iterator;

  // You don't need to implement constructors and assignment operators.
  UnorderedMap() = default;
  UnorderedMap(const UnorderedMap&) = delete;
  UnorderedMap(UnorderedMap&&) = delete;
  UnorderedMap& operator=(const UnorderedMap&) = delete;
  UnorderedMap& operator=(UnorderedMap&&) = delete;

  V& operator[](const K& key) {
    // if the key is found, return the reference of the value.
    for (auto it = head_.begin(); it != head_.end(); ++it) {
      if (it->first == key) {
        return it->second;
      }
    }
    // if the key is not found, insert the key with default value and return
    // the reference of the value.
    head_.emplace_front(key, V());
    return head_.begin()->second;
  }

  void Erase(const K& key) {
    // if the key is found, erase the key and the corresponding value.
    for (auto it = head_.begin(); it != head_.end(); ++it) {
      if (it->first == key) {
        head_.erase(it);
        return;
      }
    }
  }

  void Erase(const Iterator& it) {
    if (it != head_.end()) {
      head_.erase(it);
    }
  }

  bool Empty() const {
    return head_.empty();
  }

  size_t Size() const {
    return head_.size();
  }

  Iterator Begin() {
    return head_.begin();
  }

  Iterator End() {
    return head_.end();
  }

  Iterator Find(const K& key) {
    // if the key is found, return the iterator to the key.
    for (auto it = head_.begin(); it != head_.end(); ++it) {
      if (it->first == key) {
        return it;
      }
    }
    // if the key is not found, return end() iterator.
    return head_.end();
  }

 private:
  list<ValueType> head_;
};

int main() {
  // Test #1
  // Search a nonexistent key, "RED".
  // return value: 0
  UnorderedMap<string, int> um;
  auto it = um.Find("RED");
  if (it == um.End()) {
    cout << "There is no RED." << endl;
  }
  cout << endl;

  // Test #2
  // Insert new (key, value) pairs.
  um["RED"] = 100;
  um["ORANGE"] = 200;
  um["YELLOW"] = 300;
  um["GREEN"] = 400;
  um["BLUE"] = 500;
  um["INDIGO"] = 600;
  um["VIOLET"] = 700;
  for (auto it = um.Begin(); it != um.End(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
  cout << endl << endl;

  // Test #3
  // update the value of "INDIGO" and delete ("YELLOW", 300).
  um["INDIGO"] = 1600;
  um.Erase(um.Find("YELLOW"));
  for (auto it = um.Begin(); it != um.End(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
  cout << "Current size: " << um.Size() << endl;
  return 0;
}
