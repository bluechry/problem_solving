// This problem is concerned with rectangles whose sides are parallel to the
// X-axis and Y-axis. A rectangle is defined by bottom-left point (x1, y1) and
// top-right point (x2, y2), (x and y are integers).
//
// Write a program tests if two rectangles have a nonempty intersection.
// If the intersection is nonempty, return the rectangle formed by their
// intersection, if not, return an invalid rectangle defined by (0,0) and
// (-1, -1).

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

// Solution
// * Overlap 여부를 확인하는 방법
//   Overlap 되는 경우는 너무 많기 때문에 case-by-case로 조건을 나열하기 힘들다.
//   따라서, overlap 되지않는 경우의 조건을 구하고 not을 취한다.
//
//   두 rectangle R1, R2가 overlap되지 않는 경우의 조건:
//   * R1.x1 > R2.x2 or R1.x2 < R2, x1 or
//   * R1.y1 > R2.y2 or R1.y2 < R2.y1
//
// * Intersection을 구하는 방법
//   겹치는 rectangle = {max(R1.x1, R2,x1), max(R1.y1, R2.y1),
//                       min(R1.x2, R2.x2), min(R1.y2, R2.y2)}
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

struct Rectangle {
  int x1, y1, x2, y2;
};

bool IsIntersect(const Rectangle& r1, const Rectangle& r2) {
  return (r1.x2 >= r2.x1 && r1.x1 <= r2.x2 &&
          r1.y2 >= r2.y1 && r1.y1 <= r2.y2);
}

Rectangle FindIntersection(const Rectangle& r1, const Rectangle& r2) {
  if (IsIntersect(r1, r2)) {
    return Rectangle({max(r1.x1, r2.x1), max(r1.y1, r2.y1),
                      min(r1.x2, r2.x2), min(r1.y2, r2.y2)});
  } else {
    return Rectangle({0, 0, -1, -1});
  }
}

int main() {
{
  // Test #1
  // R1 = {0, 0, 1, 1}, R2 = {2, 2, 3, 3}
  // return value = {0, 0, -1, -1};
  Rectangle result = FindIntersection(Rectangle({0, 0, 1, 1}),
                                      Rectangle({2, 2, 3, 3}));
  printf("{%d, %d, %d, %d}\n", result.x1, result.y1, result.x2, result.y2);
}
{
  // Test #2
  // R1 = {0, 0, 1, 1}, R2 = {1, 1, 3, 3}
  // return value = {1, 1, 1, 1};
  Rectangle result = FindIntersection(Rectangle({0, 0, 1, 1}),
                                      Rectangle({1, 1, 3, 3}));
  printf("{%d, %d, %d, %d}\n", result.x1, result.y1, result.x2, result.y2);
}
{
  // Test #3
  // R1 = {0, 0, 4, 4}, R2 = {1, 1, 8, 8}
  // return value = {1, 1, 4, 4};
  Rectangle result = FindIntersection(Rectangle({0, 0, 4, 4}),
                                      Rectangle({1, 1, 8, 8}));
  printf("{%d, %d, %d, %d}\n", result.x1, result.y1, result.x2, result.y2);
}
{
  // Test #4
  // R1 = {0, 0, 4, 4}, R2 = {1, 1, 3, 3}
  // return value = {1, 1, 3, 3};
  Rectangle result = FindIntersection(Rectangle({0, 0, 4, 4}),
                                      Rectangle({1, 1, 3, 3}));
  printf("{%d, %d, %d, %d}\n", result.x1, result.y1, result.x2, result.y2);
}
  return 0;
}
