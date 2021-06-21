// A 64-bit integer can be viewed as an array of 64 bits,
// with the bit at index 0 corresponding to LSB,
// and the bit at index 63 corresponding to MSB.
// Implement code that takes as input a 64-bit integer and
// swaps the bits at indices i and j.

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// Solution
//   * i번째 bit와 j번째 bit가 다를 때 bit를 swap한다.
//     Bit들의 swap은 각 bit를 toggle하는 것으로 구현할 수 있다.
//   * i번째 bit를 toggle하는 방법은 다음과 같다.
//     'x = x ^ (0x1 << i)'
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)
//
long SwapBits(long num, int i, int j) {
  if (((num >> i) & 1) != ((num >> j) & 1)) {
    unsigned long bit_mask = (1UL << i) | (1UL << j);
    num ^= bit_mask;
  }
  return num;
}

int main() {
  // Test #1. 64bit 1L의 63번째 bit와 1번째 bit을 swap한다.
  // Swap 전후의 값이 동일해야한다.
  long num = 1L;
  if (SwapBits(num, 63, 1) != num)
    cout << "wrong answer." << endl;

  // Test #2. 64bit 1L의 63번째 bit와 0번째 bit를 바꾼다.
  // Swap 후의 값이 1000...0000 과 같아야한다.
  if (SwapBits(num, 63, 0) != numeric_limits<long>::min())
    cout << "wrong answer." << endl;
  return 0;
}
