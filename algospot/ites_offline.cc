// Problem ID: ITES
//
// 문제 설명
//

//{{{
#include <iostream>
#include <vector>

using namespace std;
//}}}

struct RNG {
  RNG(): seed(1983) {}

  int Next() {
    int next = seed % 10000 + 1;
    seed = seed * 214013u + 2531011u;
    return next;
  }

  unsigned int seed;
};

// 풀이 방법 #1
//
// 시간 복잡도
//   O(N^2)
//
// 공간 복잡도
//   O(N)
//
int CountRanges1(const vector<int>& signals, int K) {
  int count = 0;
  for (int head = 0; head < signals.size(); ++head) {
    int sum = 0;
    for (int tail = head; tail < signals.size(); ++tail) {
      sum += signals[tail];
      if (sum == K) ++count;
      if (sum >= K) break;
    }
  }
  return count;
}

// 풀이 방법 #2
//
// 시작 복잡도
//   O(N)
//
// 공간 복잡도
//   O(N)
//
int CountRanges2(const vector<int>& signals, int K) {
  int count = 0, tail = 0, sum = signals[0];
  for (int head = 0; head < signals.size(); ++head) {
    while (sum < K and tail < signals.size() - 1)
      sum += signals[++tail];
    if (sum == K) ++count;
    sum -= signals[head];
  }
  return count;
}

//{{{
int main() {
  int C;
  cin >> C;
  while (C-- != 0) {
    int K, N;
    cin >> K >> N;

    RNG rng;
    vector<int> signals;
    for (int i = 0; i < N; ++i) {
      signals.push_back(rng.Next());
    }

    int result = CountRanges2(signals, K);
    cout << result << endl;
  }
  return 0;
}
//}}}
