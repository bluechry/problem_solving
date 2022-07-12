// Problem ID: FESTIVAL
//
// Problem Definition
//   주어진 N개의 정수들에 대하여, 길이가 L 이상인 연속한 정수들 중,
//   그들의 평균값이 가장 작은 값을 구하여라.
//
// Description
//   For a given number of integers, find consecutive integers whose length
//   is not less than L and whose mean is smallest and return the average of
//   them as a result.

//{{{
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;
//}}}

// 풀이방법 #1
//   길이가 L 이상인 모든 연속한 정수들에 대하여 평균값을 구하고, 그 중에
//   가장 작은 값을 반환한다.
//
// 시간 복잡도
//   Loop 반복 횟수 < (N - L + 1) * (N - L + 1) * N < N^3
//   따라서, O(N^3).
//
// 공간 복잡도
//   입력 데이터를 저장하기 위한 공간 외에 몇 개의 변수들만 필요하다.
//   따라서, O(1).
//
double FindMinAvg1(int L, const vector<int>& costs) {
  int N = costs.size();
  double min_avg = numeric_limits<double>::max();
  for (int i = 0; i <= N - L; ++i) {
    for (int j = i + L - 1; j <= N - 1; ++j) {
      int sum = accumulate(&costs[i], &costs[j + 1], 0);
      min_avg = min(min_avg, (double)sum / (j - i + 1));
    }
  }
  return min_avg;
}

// 풀이 방법 #2
//   풀이 방법 #1에서, [i, j] 구간의 평균을 구하는데 O(N)의 시간이 드는데,
//   이를 O(1)으로 줄여보자.
//
//   임시 배열 temp[]를 두고, temp[i]에 [0, i] 구간의 합을 저장한다.
//   그러면, [i, j] 구간의 합은 temp[j] - temp[i - 1]로 구할 수 있다.
//   이 구간합을 (j - i + 1)로 나누면 O(1)에 평균을 구할 수 있다.
//
// 시간 복잡도
//   임시 배열 구축 시간: O(N)
//   Loop 반복 횟수 < (N - L + 1) * (N - L + 1) < N^2
//   따라서, O(N^2).
//
// 공간 복잡도
//   임시 배열을 위한 공간이 필요하다.
//   따라서, O(N).
//
double FindMinAvg2(int L, const vector<int>& costs) {
  vector<int> temp(costs);
  int N = temp.size();
  for (int i = 0; i < N; ++i) {
    temp[i] += temp[i - 1];
  }

  double min_avg = numeric_limits<double>::max();
  for (int i = 0; i <= N - L; ++i) {
    for (int j = i + L - 1; j <= N - 1; ++j) {
      // 풀이 방법 1의 accumulate(&costs[i], &costs[j + 1], 0)를
      // 아래 문장으로 대체
      int sum = (i == 0) ? temp[j] : (temp[j] - temp[i - 1]);
      min_avg = min(min_avg, (double)sum / (j - i + 1));
    }
  }
  return min_avg;
}

// 풀이 방법 #3
//   [i, j] 구간의 합을 나타내는 변수 sum을 두고, 구간이 확장됨에 따라 구간의
//   합을 갱신하고, 이 값을 구간의 길이로 나누어서 평균을 구한다.
//
// 시간 복잡도
//   # of Loops < (N - L + 1) * (N - L + 1) < N^2
//   따라서, O(N^2).
//
// 공간 복잡도
//   입력 데이터를 저장하기 위한 공간 외에 몇 개의 변수들만 필요하다.
//   따라서, O(1).
//
double FindMinAvg3(int L, const vector<int>& costs) {
  int N = costs.size();
  double min_avg = numeric_limits<double>::max();
  for (int i = 0; i <= N - L; ++i) {
    int sum = accumulate(&costs[i], &costs[i + L - 1], 0);
    for (int j = i + L - 1; j <= N - 1; ++j) {
      sum += costs[j];
      min_avg = min(min_avg, (double)sum / (j - i + 1));
    }
  }
  return min_avg;
}

//{{{
int main() {
  int C;
  cin >> C;
  while (C-- != 0) {
    int N, L;
    cin >> N >> L;

    vector<int> costs(N);
    for (int i = 0; i < N; ++i) {
      cin >> costs[i];
    }

    double result = FindMinAvg3(L, costs);
    printf("%.11lf\n", result);
  }
  return 0;
}
//}}}
