// Problem ID: ITES
//
// 문제 설명
//

//{{{
#include <iostream>
#include <queue>

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

// 풀이 방법 #3
//
// 시간 복잡도
//   O(N)
//
// 공간 복잡도
//   O(K)
//
int CountRanges(int K, int N) {
  RNG rng;
  queue<int> ranges;
  int sum = 0, count = 0;

  for (int i = 0; i < N; ++i) {
    int signal = rng.Next();
    ranges.push(signal);
    sum += signal;

    while (sum > K) {
      sum -= ranges.front();
      ranges.pop();
    }

    if (sum == K) ++count;
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

    int result = CountRanges(K, N);
    cout << result << endl;
  }
  return 0;
}
//}}}
