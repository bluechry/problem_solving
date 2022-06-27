// Problem ID: FESTIVAL
//
// 문제 설명
//   주어진 N개의 정수들에 대하여, 길이가 L 이상인 연속한 정수들 중,
//   그들의 평균값이 가장 작은 값을 구하여라.
//
// Description
//   For a given number of integers, find consecutive integers whose length
//   is not less than L and whose mean is smallest and return the average of
//   them as a result.

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// 풀이방법 #1
//   길이가 L 이상인 모든 연속한 정수들에 대하여 평균값을 구하고, 그 중에
//   가장 작은 값을 반환한다.
//
// 시간 복잡도
//   Loop 반복 횟수 < (N - L + 1) * (N - L) * N < N^3
//   따라서, O(N^3).
//
// 공간 복잡도
//   입력 데이터를 저장하기 위한 공간 외에 몇 개의 변수들만 필요한다.
//   따라서, O(1).
//
double FindMinAvg_1(int L, const vector<int>& costs) {
  int N = costs.size();
  double min_avg = std::numeric_limits<double>::max();
  for (int i = 0; i <= N - L; ++i) {
    for (int j = i + L - 1; j <= N - 1; ++j) {
      int sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += costs[k];
      }
      double avg = (double)sum / (j - i + 1);
      min_avg = std::min(min_avg, avg);
    }
  }
  return min_avg;
}

// 풀이 방법 #2
//   풀이 방법 #1에서, [i, j] 구간의 정수들을 더하는 작업이 여러 번 반복된다.
//   각 정수들이 한 번만 더해지도록 해보자.
//
//   임시 배열 temp[]를 두고, temp[i]에 [0, i] 구간의 합을 저장한다.
//   그러면, [i, j] 구간의 합은 temp[j] - temp[i - 1]로 구할 수 있다.
//
// 시간 복잡도
//   임시 배열 구축 시간: O(N)
//   Loop 반복 횟수 < (N - L + 1) * (N - L)
//   따라서, O(N^2).
//
// 공간 복잡도
//   임시 배열을 위한 공간이 필요하다.
//   따라서, O(N).
//
double FindMinAvg_2(int L, const vector<int>& costs) {
  vector<int> temp(costs);
  int N = temp.size();
  for (int i = 0; i < N; ++i) {
    temp[i] += temp[i - 1];
  }

  double min_avg = std::numeric_limits<double>::max();
  for (int i = 0; i <= N - L; ++i) {
    for (int j = i + L - 1; j <= N - 1; ++j) {
      int sum = (i >= 1) ? (temp[j] - temp[i - 1]) : temp[j];
      double avg = (double)sum / (j - i + 1);
      min_avg = std::min(min_avg, avg);
    }
  }
  return min_avg;
}

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

    double result = FindMinAvg_2(L, costs);
    printf("%.11lf\n", result);
  }
  return 0;
}
