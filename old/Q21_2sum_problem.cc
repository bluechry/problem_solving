// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that
//   * Array has distinct integers.
//   * Each input would have exactly one solution.
// You may not use the same element twice.
//
// For example, {2, 7, 11, 15} and target number 9 are given, return [0, 1] as
// an answer.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution #1
//   elems[]에서 서로 다른 두 개의 원소의 pair (i, j), i != j 에 대하여
//   elems[i] + elems[j] == target 인지 확인한다.
//
// Time Complexity: O(N^2)
//
// Space Complexity: O(1)

vector<int> FindTwoSum(const vector<int>& elems, int target) {
  for (int i = 0; i < elems.size(); ++i) {
    for (int j = i + 1; j < elems.size(); ++j) {
      // i != j 이므로 j = i + 1 부터 시작한다.
      if (elems[i] + elems[j] == target) {
          return vector<int>({i, j});
      }
    }
  }
  return vector<int>({-1, -1});
}

// Solution #2
//   각 index i에 대하여 target - elems[i]를 구하고, 이 값을 갖는 index j를
//   binary search를 사용하여 찾는다.
//   Binary search를 사용하기 위해서 elems[]를 sorting 해야한다.
//
// Time Complexity: O(NlogN) + O(NlogN)
//   * Sorting elems[]: O(NlogN)
//   * Binary search for index i: O(logN)
//   따라서, total time complexity는 O(NlogN).
//
// Space Complexity: O(1)

vector<int> FindTwoSum2(vector<int> elems, int target) {
  // First, sort the given elements.
  sort(elems.begin(), elems.end());

  // Second, for each i, find j which has value of (target - elems[i]).
  for (int i = 0; i < elems.size(); ++i) {
    int key = target - elems[i];
    auto pos = lower_bound(elems.begin(), elems.end(), key);
    if (pos != elems.end() && *pos == key) {
      int j = static_cast<int>(pos - elems.begin());
      if (i != j) {
        return vector<int>({i, j});
      }
    }
  }
  return vector<int>({-1, -1});
}

// Solution #3
//   elems[]의 모든 원소들을 ordered map에 저장한 후, 각 index i에 대하여
//   target - elems[i] 값을 ordered map에서 찾는다.
//   Ordered map은 (elems[i], i) pair가 저장된다.
//
// Time Complexity: O(N) + O(N)
//   * Constructing ordered map: O(N)
//   * Hashing for index i: average time of O(1)
//   따라서, total time complexity는 O(N)
//
// Space Complexity: O(N), space of ordered map.

vector<int> FindTwoSum3(const vector<int>& elems, int target) {
  // First, construct an unordered map.
  unordered_map<int, int> map;
  for (int i = 0; i < elems.size(); ++i) {
    map[elems[i]] = i;
  }

  // Second, for each i, find j which has value of (target - elems[i]).
  for (int i = 0; i < elems.size(); ++i) {
    int key = target - elems[i];
    auto pos = map.find(key);
    if (pos != map.end()) {
      if (i != pos->second) {
        return vector<int>({i, pos->second});
      }
    }
  }
  return vector<int>({-1, -1});
}


// Solution #4
//   elems[]의 원소들을 정렬한 후 다음과 같은 rule에 따라 (i, j) pair를 찾는다.
//   * i = 0, j = elems.size() - 1
//   * i < j 일 때까지 다음을 반복한다.
//     * elems[i] + elems[j] == target 이면 (i, j)를 반환
//     * elems[i] + elems[j] > target 이면 j = j - 1
//     * elems[i] + elems[j] < target 이면 i = i + 1
//
// Time Complexity: O(NlogN) + O(N)
//   * Sorting elements: O(NlogN)
//   * Serching (i, j) pair: O(N)
//
// Space Complexity: O(1)

vector<int> FindTwoSum4(vector<int> elems, int target) {
  // First, sort elements.
  sort(elems.begin(), elems.end());

  // Second, find (i, j) pair which satisfies elems[i] + elems[j] == target.
  int i = 0, j = elems.size() - 1;
  while (i < j) {
    int sum = elems[i] + elems[j];
    if (sum > target) {
      --j;
    } else if (sum < target) {
      ++i;
    } else {
      return vector<int>({i, j});
    }
  }
  return vector<int>({-1, -1});
}

int main() {
{
  // Test #1
  // elems[] = {2, 7, 11, 15}, target = 9
  vector<int> elems = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = FindTwoSum(elems, target);
  cout << result[0] << " " << result[1] << endl;
  result = FindTwoSum2(elems, target);
  cout << result[0] << " " << result[1] << endl;
  result = FindTwoSum3(elems, target);
  cout << result[0] << " " << result[1] << endl;
  result = FindTwoSum4(elems, target);
  cout << result[0] << " " << result[1] << endl;
  cout << endl;
}
{
  // Test #2
  // elems[] = {2, 7, 11, 15}, target = 4
  vector<int> elems = {2, 7, 11, 15};
  int target = 4;
  vector<int> result = FindTwoSum(elems, target);
  cout << result[0] << " " << result[1] << endl;
  result = FindTwoSum2(elems, target);
  cout << result[0] << " " << result[1] << endl;
  result = FindTwoSum3(elems, target);
  cout << result[0] << " " << result[1] << endl;
  result = FindTwoSum4(elems, target);
  cout << result[0] << " " << result[1] << endl;
  cout << endl;
}
  return 0;
}
