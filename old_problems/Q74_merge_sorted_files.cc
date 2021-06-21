// Write a program that takes as input a set of sorted sequences and computes
// the union of these sequences as a sorted sequence.
// For example, if the input is <3, 5, 7>, <0, 6>, <0, 6, 28>, then
// the output is <0, 0, 3, 5, 6, 6, 7, 28>.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   k 개의 sorted file을, 크기가 k인 min heap을 사용하여 정렬한다.
//   1. 각 sorted file의 첫번째 원소를 min heap에 삽입한다.
//   2. min heap에서 최소값을 꺼낸다.
//   3. 최소값이 속한 sorted file에서 다음 최소값을 min heap에 삽입한다.
//   4. min heap이 빌 때까지 2~3 과정을 반복한다.
//
// Time Complexity: O(Nlogk)
//   * 모든 N개의 원소들은 한 번씩 min heap에 들어갔다 나온다.
//   * 원소 삽입, 삭제시 O(logk)의 비용이 발생한다.
//    따라서 total time complexity는 O(Nlogk)이다.
//
// Space Complexity: O(N), space for min heap.

struct Item {
  int value_;
  int file_no_;
  int offset_;

  // priority_queue에서 사용되는 std::less<T>()를 override한다.
  // min heap을 구현해야하므로 std::greater<T>()를 override해야하는데,
  // 편의상 std::less<T>()를 std::greater<T>()로 구현해 버린다.
  bool operator<(const Item& item) const {
    return value_ > item.value_;
  }
};

vector<int> MergeSortedFiles(const vector<vector<int>>& sorted_files) {
  priority_queue<Item> pq;

  // Create min heap.
  for (int i = 0; i < sorted_files.size(); ++i) {
    if (!sorted_files[i].empty()) {
      // Note
      // 'emplace(sorted_files[i][0], i, 1)' 로 쓰고 싶다면,
      // Item(int value, int file_no, int offset) ctor가 필요하다.
      pq.emplace(Item{sorted_files[i][0], i, 1});
    }
  }

  // Merge sorted files.
  vector<int> result;
  while (!pq.empty()) {
    Item min_item = pq.top();
    pq.pop();
    result.emplace_back(min_item.value_);

    const vector<int>& min_file = sorted_files[min_item.file_no_];
    if (min_item.offset_ < min_file.size()) {
      // struct는 '{ }'로 초기화할 수 있다.
      // Item new_item = { ... } 또는 Item new_item{ ... }
      Item new_item =
          {min_file[min_item.offset_], min_item.file_no_, ++min_item.offset_};
      pq.emplace(new_item);
    }
  }
  return result;
}

// Another version of same solution using the iterator.
// It is more simpler than the previous version.

struct Item2 {
  vector<int>::const_iterator cur_;
  vector<int>::const_iterator end_;

  bool operator<(const Item2& item) const {
    return *cur_ > *(item.cur_);
  }
};

vector<int> MergeSortedFiles2(const vector<vector<int>>& sorted_files) {
  priority_queue<Item2> pq;

  // Create min heap.
  for (const vector<int>& s: sorted_files) {
    if (!s.empty()) {
      pq.emplace(Item2{s.begin(), s.end()});
    }
  }

  // Merge sorted files.
  vector<int> result;
  while (!pq.empty()) {
    Item2 min_item = pq.top();
    pq.pop();
    result.emplace_back(*min_item.cur_);

    if (++min_item.cur_ != min_item.end_) {
      pq.emplace(Item2{min_item.cur_, min_item.end_});
    }
  }
  return result;
}

int main() {
  vector<vector<int>> sorted_files;
  sorted_files.emplace_back(vector<int>({3, 5, 7}));
  sorted_files.emplace_back(vector<int>({0, 6}));
  sorted_files.emplace_back(vector<int>({0, 6, 28}));

  vector<int> result = MergeSortedFiles(sorted_files);
  for (int i: result) {
    cout << i << " ";
  }
  cout << endl;
  vector<int> result2 = MergeSortedFiles2(sorted_files);
  for (int i: result2) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
