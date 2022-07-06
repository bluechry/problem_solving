// You are given two 32-bit numbers, N and M, and two bit positions, i and j.
// Write a method to insert M into N such that M starts at bit j and ends at
// bit i. You can assume that the bits j through i have enough space to fit
// all of M. That is, if M = 10011, you can assume that there are at least
// 5 bits between j and i. You would not, for example, have j = 3 and i = 2,
// because M could not fully fit between bit 3 and bit 2.
//
// EXAMPLE
// Input:  N = 10000000000, M = 10011, i = 2, j = 6
// Output: N = 10001001100

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   * N의 j부터 i까지의 bit를 0으로 unset한다.
//
//     bitmask = (-1 << (j + 1)) | ((1 << i) - 1);
//     N &= bitmask;
//
//   * M을 i번 left shift하여 위의 결과와 or한다.
//
//     N |= (M << i);
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)
long InsertBits(long N, long M, int i, int j) {
  unsigned long bit_mask = (-1 << (j + 1)) | ((1 << i) - 1);
  return (N & bit_mask) | (M << i);
}

int main() {
  // Test #1.
  // N = 10000000000(=1024), M = 10011(=19), i = 2, j = 6
  // return_value = 10001001100(=1100)
  cout << InsertBits(1024, 19, 2, 6) << endl;
  return 0;
}
