// Design an algorithm that takes as input an array and a number, and
// determines if there are three entries in the array (not necessarily distinct)
// which add up to the specified number.
//
// For example, if the array is {11, 2, 5, 7, 3} then there are three entries
// in the array which add up to 21 (3, 7, 11 and 5, 5, 11).
// Note that we can use 5 twice, since the problem statement said we can use the
// same entry more than once.) However, no three entries add up to 22.
// You may assume that the array has distinct elements.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution #1
//   모든 triplet (i, j, k), i <= j <= k에 대하여,
//   elems[i] + elems[j] + elems[k] == target 인지 확인한다.
//
// Time Complexity: O(N^3)
//
// Space Complexity: O(1)

bool CheckThreeSum(const vector<int>& elems, int target) {
  for (int i = 0; i < elems.size(); ++i) {
    for (int j = i; j < elems.size(); ++j) {
      for (int k = j; k < elems.size(); ++k) {
        if (elems[i] + elems[j] + elems[k] == target) {
          return true;
        }
      }
    }
  }
  return false;
}

// Solution #2
//   모든 pair (i, j), i <= j에 대하여, target - elems[i] - elems[j]를
//   binary search를 사용하여 찾는다.
//
// Time Complexity: O(NlogN) +  O(N^2logN)
//   * Sorting elements: O(NlogN)
//   * Binary search for all (i, j): O(N^2logN)
//
// Space Complexity: O(1)

bool CheckThreeSum2(vector<int> elems, int target) {
  // First, sort elements.
  sort(elems.begin(), elems.end());

  // Second, search target - elems[i] - elems[j].
  for (int i = 0; i < elems.size(); ++i) {
    for (int j = i; j < elems.size(); ++j) {
      int key = target - elems[i] - elems[j];
      auto pos = lower_bound(elems.begin(), elems.end(), key);
      if (pos != elems.end() && *pos == key) {
        return true;
      }
    }
  }
  return false;
}

// Solution #3
//   모든 element들을 unordered map에 저장한 후, target - elems[i] - elems[j]를
//   unordered map에서 찾는다.
//
// Time Complexity: O(N) + O(N^2)
//   * Constructing unordered map: O(N)
//   * Finding key in unordered map for all (i, j): O(N^2)
//
// Space Complexity: O(N)

bool CheckThreeSum3(const vector<int>& elems, int target) {
  // First, construct unordered map.
  unordered_map<int, int> map;
  for (int i = 0; i < elems.size(); ++i) {
    map[elems[i]] = i;
  }

  // Second, find target - elems[i] - elems[j] for all (i, j).
  for (int i = 0; i < elems.size(); ++i) {
    for (int j = i; j < elems.size(); ++j) {
      if (map.find(target - elems[i] - elems[j]) != map.end()) {
        return true;
      }
    }
  }
  return false;
}

// Solution #4
//   모든 i에 대하여 elems[j] + elems[k] == target - elems[i] 인 (j, k)를
//   O(N)에 찾는다. 이를 위해서 elems[]는 정렬되어야 한다.
//   (j, k)를 O(N)에 찾는 방법은 다음과 같다.
//
//   * lo = 0, hi = elems.size() - 1
//   * lo <= hi 인 동안 다음 과정을 진행한다.
//     * elems[lo] + elems[hi] == target 이면 true를 return.
//     * elems[lo] + elems[hi] < target 이면 ++lo.
//     * elems[lo] + elems[hi] > target 이면 --hi.
//
// Time Complexity: O(N^2)
//
// Space Complexity: O(1)

bool CheckTwoSum(const vector<int>& elems, int target) {
  int lo = 0, hi = elems.size() - 1;
  while (lo <= hi) {
    if (elems[lo] + elems[hi] < target) {
      ++lo;
    } else if (elems[lo] + elems[hi] > target) {
      --hi;
    } else {
      return true;
    }
  }
  return false;
}

bool CheckThreeSum4(vector<int> elems, int target) {
  // First, sort elems.
  sort(elems.begin(), elems.end());

  // Second, for all i, check two sum.
  for (auto i: elems) {
    if (CheckTwoSum(elems, target - i)) {
      return true;
    }
  }
  return false;
}

int main() {
{
  // Test #1
  // elems[] = {11, 2, 5 , 7, 3}, target = 21
  vector<int> elems = {11, 2, 5, 7, 3};
  int target = 21;
  cout << (CheckThreeSum(elems, target) ? "true" : "false") << endl;
  cout << (CheckThreeSum2(elems, target) ? "true" : "false") << endl;
  cout << (CheckThreeSum3(elems, target) ? "true" : "false") << endl;
  cout << (CheckThreeSum4(elems, target) ? "true" : "false") << endl;
  cout << endl;
}
{
  // Test #2
  // elems[] = {11, 2, 5 , 7, 3}, target = 22
  vector<int> elems = {11, 2, 5, 7, 3};
  int target = 22;
  cout << (CheckThreeSum(elems, target) ? "true" : "false") << endl;
  cout << (CheckThreeSum2(elems, target) ? "true" : "false") << endl;
  cout << (CheckThreeSum3(elems, target) ? "true" : "false") << endl;
  cout << (CheckThreeSum4(elems, target) ? "true" : "false") << endl;
  cout << endl;
}

  return 0;
}
