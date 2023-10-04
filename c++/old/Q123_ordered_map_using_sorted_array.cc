// Implement an ordered map using a sorted array. You may implement resizable
// map and lazy deletion for Erase(). You don't need to consider the
// invalidation.
/*
template<typename K, typename V>
class Map {
 public:
  using ValueType = pair<K, V>;
  using Iterator = typename vector<ValueType>::iterator;

  // You don't need to implement constructors and assignment operators.
  Map() = default;
  Map(const Map&) = delete;
  Map(Map&&) = delete;
  Map& operator=(const Map&) = delete;
  Map& operator=(Map&&) = delete;

  V& operator[](const K& key);
  void Erase(const K& key);
  void Erase(const Iterator& iter);
  bool Empty() const;
  size_t Size() const;
  Iterator Begin();
  Iterator End();
  Iterator Find(const K& key);
  Iterator LowerBound(const K& key);  // return an iterator to the first element not less than key.
  Iterator UpperBound(const K& key);  // return an iterator to the first element greater than key.
};
*/

#include <algorithm>
#include <chrono>
#include <iostream>
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

template<typename K, typename V>
class Map {
 public:
  using ValueType = pair<K, V>;
  using Iterator = typename vector<ValueType>::iterator;

  // You don't need to implement constructors and assignment operators.
  Map() = default;
  Map(const Map&) = delete;
  Map(Map&&) = delete;
  Map& operator=(const Map&) = delete;
  Map& operator=(Map&&) = delete;

  V& operator[](const K& key) {
    Iterator it = LowerBound(key);
    if (it != elems_.end() && it->first == key) {
      return it->second;
    } else {
      return elems_.emplace(it, key, V())->second;
    }
  }

  void Erase(const K& key) {
    Iterator it = Find(key);
    if (it != elems_.end()) {
      elems_.erase(it);
    }
  }

  void Erase(const Iterator& it) {
    if (it != elems_.end()) {
      elems_.erase(it);
    }
  }

  Iterator Begin() {
    return elems_.begin();
  }

  Iterator End() {
    return elems_.end();
  }

  bool Empty() const {
    return elems_.empty();
  }

  size_t Size() const {
    return elems_.size();
  }

  Iterator Find(const K& key) {
    Iterator it = LowerBound(key);
    if (it != elems_.end() && it->first == key) {
      return it;
    } else {
      return elems_.end();
    }
  }

  Iterator LowerBound(const K& key) {
    int lo = 0, hi = elems_.size() - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (elems_[mid].first < key) {
        lo = mid + 1;
      } else if (elems_[mid].first > key) {
        hi = mid - 1;
      } else {
        return elems_.begin() + mid;
      }
    }
    return elems_.begin() + lo;
  }

  Iterator UpperBound(const K& key) {
    Iterator it = LowerBound(key);
    if (it != elems_.end() && it->first == key) {
      return ++it;
    } else {
      return it;
    }
  }

 private:
  vector<ValueType> elems_;
};

int main() {
  // Test #1
  // Search a nonexistent key, 100.
  // return value: ""
  Map<int, string> m;
  if (m.Find(100) == m.End()) {
    cout << "There is no 100." << endl;
  }
  if (m.LowerBound(100) == m.End()) {
    cout << "There is no lower bound of 100" << endl;
  }
  if (m.UpperBound(100) == m.End()) {
    cout << "There is no upper bound of 100" << endl;
  }
  cout << endl;

  // Test #2
  // Insert new (key, value) pairs.
  m[100] = "RED";
  m[200] = "ORANGE";
  m[300] = "YELLOW";
  m[400] = "GREEN";
  m[500] = "BLUE";
  m[600] = "INDIGO";
  m[700] = "VIOLET";
  for (auto it = m.Begin(); it != m.End(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
  cout << endl;

  // Test #3
  // Test Find(), LowerBound(), UpperBound() of a key.
  auto it = m.Find(200);
  cout << it->first << ": " << it->second << endl;

  it = m.LowerBound(500);
  cout << it->first << ": " << it->second << endl;

  it = m.UpperBound(500);
  cout << it->first << ": " << it->second << endl;

  it = m.LowerBound(450);
  cout << it->first << ": " << it->second << endl;

  it = m.UpperBound(450);
  cout << it->first << ": " << it->second << endl;

  it = m.LowerBound(800);
  if (it == m.End()) {
    cout << "There is no lower bound of 800" << endl;
  }

  it = m.UpperBound(800);
  if (it == m.End()) {
    cout << "There is no upper bound of 800" << endl;
  }

  it = m.LowerBound(0);
  cout << it->first << ": " << it->second << endl;

  it = m.UpperBound(0);
  cout << it->first << ": " << it->second << endl;
  cout << endl;

  // Test #4
  // update the value of 700 and delete (300, "YELLOW").
  m[700] = "BLACK";
  m.Erase(300);
  for (auto it = m.Begin(); it != m.End(); ++it) {
    cout << it->first << ": " << it->second << endl;
  }
  cout << "Current size: " << m.Size() << endl;
  return 0;
}
