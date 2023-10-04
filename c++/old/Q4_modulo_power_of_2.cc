// Problem Statement
//  Compute x modulo a power of two, returns 13 for 77 mod 64.
//  Assume that x is a 64bit signed integer and the power is in [0, 64).

#include <iostream>
#include <vector>

using namespace std;

// Clue
//  'x'를 2^n으로 나눈다는 것은 x를 n번 right-shift하는 것과 동일하고,
//   x의 하위 n개의 bit들이 나머지가 된다.
//
// Solution
//   x % 2^n = x & ((1UL << n) - 1)
//
//  위 식은 'x'가 양수이거나 음수일 때 모두 성립한다.
//  양수에 적용되는 사칙연산, 나머지 연산들은 음수에도 동일하게 적용된다.
//  (ALU는 양수, 음수 가리지 않고 동일하게 동작한다.)
//
//  Boundary case로 n = 0 또는 n = 63인 경우를 확인하자.
//  n = 0이면, x % 1 = x & 0 = 0
//  n = 63이면, x % 2^63 = x & ((1UL << 63) - 1) = x
int64_t ModuloPowerOfTwo(int64_t x, int n) {
  return x & ((1UL << n) - 1);
}

int main() {
  vector<int64_t> x_vec = {-12345, -128, -1, 0, 1, 128, 12345};
  vector<int> n_vec = {0, 1, 2, 3, 63};

  for (auto x: x_vec) {
    printf("\n");
    for (auto n: n_vec) {
      int64_t ans = x % (1UL << n);
      int64_t my_ans = ModuloPowerOfTwo(x, n);
      printf("%ld modulo 2^%d = %ld(%ld)\n", x, n, my_ans, ans);
    }
  }
  return 0;
}
