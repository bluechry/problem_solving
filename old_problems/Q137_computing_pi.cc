// Write a program that computes the value of Pi with a precision of two decimal
// digits.

//{{{
#include <math.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//}}}

// Solution
//  반지름이 1인 원의 내부를 n개의 이등변 삼각형으로 쪼갠 후, 이등변 삼각형의
//  넓이를 모두 더하여 PI 값을 근사한다.
//
//  * 반지름이 1인 원의 넓이 = PI
//  * n개의 이등변 삼각형의 넓이, A = 0.5 * sin(M_PI * 2 / n) * n
//  * n을 적당히 큰 값부터 시작하여 점점 증가시켜가면서 A를 구한다.
//
//  문제는 삼각형의 넓이를 구하는데 M_PI를 사용한다는 점이다.
//  M_PI를 사용하지 않는 방법을 구상해보자.
//
//  theta를 30도부터 시작하여 15도, 7.5도, 3.25도, ... 로 절반씩 줄이면서
//  (즉, n을 12, 24, 48, 96, ... 로 두 배씩 증가시키면서) A를 구한다.
//
//  theta 값이 절반으로 줄어들 때마다 sin(theta) 값을 구하는 방법은 아래와 같다.
//
//    sin(2*theta) = 2 * cos(theta) * sin(theta)
//    sin(2*theta) = 2 * sqrt(1 - sin(theta) * sin(theta)) * sin(theta)
//    ...
//    ...
//    sin(theta) = sqrt((1 - sqrt(1 - sin(2*theta)* sin(2*theta))) / 2.0)
//
//  위 식을 사용하여 theta 값이 절반으로 줄어들 때마다 sin값을 구하고,
//  넓이 A를 구하면 된다.
//
// Time Complexity: O(1), the constant can be smaller than 10.
//
// Space Complexity: O(1)

double ComputePI() {
  int num_slices = 12;
  double sin_theta = 0.5;
  double prev_pi = 0.0;
  double pi = 0.5 * sin_theta * num_slices;

  // Repeat until the sixth digit after the decimal point is the same.
  while (fabs(pi - prev_pi) >= 1e-6) {
    num_slices *= 2;
    sin_theta = sqrt((1 - sqrt(1 - sin_theta * sin_theta)) / 2.0);
    prev_pi = pi;
    pi = 0.5 * sin_theta * num_slices;
  }
  return pi;
}

// Solution
//  Monte Carlo method를 사용하여 가로 x 세로가 1 x 1인 정사각형 안에 꽉차는
//  원의 넓이를 구한 후 PI 값을 근사한다.
//
//  [0, 1] x [0, 1]의 정사각형에 포함되는 점들을 랜덤하게 생성한 후,
//  정사각형의 중심과의 거리가 1이하인 점들의 개수를 세어 원의 넓이를 근사한다.
//  이 원의 넓이를 반지름의 제곱으로 나누면 PI 값을 근사할 수 있다.
//
// Time Complexity: O(1), but the constant is very high!
//
// Space Complexity: O(1)

double ComputePI2() {
  int num_points = 1e5;
  int num_points_in_circle = 0;

  for (int i = 0; i < num_points; ++i) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;
    double dist_x = fabs(0.5 - x);
    double dist_y = fabs(0.5 - y);
    if (dist_x * dist_x + dist_y * dist_y <= 0.25) {
      ++num_points_in_circle;
    }
  }
  return ((double)num_points_in_circle / num_points) / (0.5 * 0.5);
}

//{{{
int main() {
  double pi = ComputePI();
  printf("Estimated PI value: %.2lf, %.7lf\n", pi, pi);

  pi = ComputePI2();
  printf("Estimated PI value: %.2lf, %.7lf\n", pi, pi);
  return 0;
}
//}}
