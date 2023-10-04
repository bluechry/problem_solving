// Problem Statement
//  Test if x is a power of 2, i.e., evaluates to true for x = 1, 2, 4, 8, ...,
//  false for all other values.
//  Assume that x is 64bit unsigned integer.

#include <iostream>
#include <limits>

using namespace std;

// Solution
//  'x'가 2^n (n >= 0)이라면, 단 하나의 set bit을 가져야한다.
//  'x'의 right-most set bit을 unset한 후 0과 같은지 확인하면 2^n인지
//  확인할 수 있다.
//
//  'x'의 right-most set bit을 unset하는 방법은 다음과 같다.
//   x = x & (x - 1)
bool CheckPowerOfTwo(uint64_t x) {
  return (x & (x - 1)) ? false : true;
}

int main() {
  // 1부터 int32_t 타입의 최대값까지의 영역에서 2^n을 찾는다.
  uint64_t max = numeric_limits<int32_t>::max();
  for (uint64_t x = 1; x < max; ++x) {
    if (CheckPowerOfTwo(x)) {
      printf("%ld is a power of 2.\n", x);
    }
  }
  return 0;
}
