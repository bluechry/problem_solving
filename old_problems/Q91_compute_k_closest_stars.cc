// Consider a coordinate system for the Milky Way, in which Earth is at
// (0, 0, 0). Model stars as points, and assume distances are in light years.
// The Milky Way consists of approximately 10^12 stars, and their coordinates
// are stored in a file. How would you compute the k stars which are closest to
// Earth?

#include <algorithm>
#include <chrono>
#include <cmath>
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
//   N 개의 별들 중에 가장 가까운 k개의 별들을 남기고 가장 큰 N-k 개의 별들을
//   제거하자.
//   모든 별들을 저장하려면 10^12 * sizeof(Star)의 메모리가 필요한데,
//   크기가 k인 heap을 사용하여 k개의 가장 가까운 별들만 저장할 수 있도록 하자.
//
//   Max heap에 N 개의 별들을 순차적으로 삽입하는데, heap의 크기가 k + 1이 되면
//   max value를 pop하여 현재 입력된 별들 중에 가장 가까운 k개의 별들만 남긴다.
//   모든 별들을 heap에 넣고나면 max heap에 k개의 가장 가까운 별들만 남는다.
//
//   Max heap이 빌 때까지 원소들을 pop하여 result vector에 저장한다.
//   Result vector에는 거리에 대한 내림차순으로 저장된 상태이므로
//   reverse하여 반환한다.
//
// Time Complexity: O(Nlogk)
//
// Space Complexity: O(k)

struct Star {
  bool operator<(const Star& s) const {
    return GetDistance() < s.GetDistance();
  }

  double GetDistance() const {
    return sqrt(x * x + y * y + z * z);
  }

  double x, y, z;
};


vector<Star> FindKClosestStar(const vector<Star>& stars, int k) {
  priority_queue<Star> max_heap;

  // Push all stars to max heap and get nearest k stars.
  for (const Star& s: stars) {
    max_heap.emplace(Star{s.x, s.y, s.z});
    if (max_heap.size() > k) {
      max_heap.pop();
    }
  }

  // Extract all nearest stars.
  vector<Star> result;
  while (!max_heap.empty()) {
    result.emplace_back(max_heap.top());
    max_heap.pop();
  }

  // Reverse results.
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  vector<Star> stars = {
      {0.0, 0.0, 1.1}, {1.1, 1.2, 0.5}, {1.3, 5.4, 2.1},
      {0.2, 0.1, 0.9}, {1.2, 3.2, 0.9}, {3.2, 1.1, 0.8},
      {1.1, 0.0, 0.0}, {0.1, 0.2, 0.3}, {0.1, 0.0, 0.3}
  };
  vector<Star> result = FindKClosestStar(stars, 5);
  for (auto s: result) {
    printf("(%.2lf, %.2lf, %.2lf) - %.2lf\n",
           s.x, s.y, s.z, sqrt(s.x * s.x + s.y * s.y + s.z * s.z));
  }
  return 0;
}
