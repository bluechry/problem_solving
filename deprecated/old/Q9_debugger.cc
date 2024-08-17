// Explain what the following code does:
// '(n & (n - 1)) == 0'

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution:
//   * n과 (n - 1)간에는 같은 자리에 set bit이 존재하지 않는다.
//   * 'n - 1'은 n의 마지막 set bit을 0으로,
//     set bit의 다음 bit부터 LSB까지를 1로 설정한다.
//
//     e.g. n     = 11110000
//          n - 1 = 11101111
//
//   * 'n & (n - 1)'은 n의 마지막 set bit을 unset하는 식이다.
//
//     e.g. n & (n - 1) = 11100000
//
//   * '(n & (n - 1)) == 0' 을 만족하려면 n은 1개의 set bit을 가져야한다.
//
//   * 1개의 set bit을 가졌다는 것은 2의 제곱수(power of 2)를 의미한다.
//
//   따라서, '(n & (n - 1)) == 0'은 'n이 power of 2'임을 확인하는 식이다.
//
//  Note:
//    'n & (n - 1) == 0' 라고 쓰면 안 된다.
//    '&' 연산자가 '==' 연산자보다 우선순위가 낮아서
//    'n & ((n - 1) == 0)' 으로 계산해 버린다.
//
bool CheckPowerOfTwo(unsigned int num) {
  if (num < 2)
    return false;
  return (num & (num - 1)) ? false : true;
}

int main() {
  // [0, 200) 영역에서 2의 제곱수를 찾는다.
  for (int i = 0; i < 200; ++i) {
    if (CheckPowerOfTwo(i))
      cout << i << " is power of 2." << endl;
  }
  return 0;
}
