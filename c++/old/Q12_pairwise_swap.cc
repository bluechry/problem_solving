// Write a program to swap odd and even bits in an integer
// with as few instruction as possible.
// (e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on).

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solutions
//   i-th bit와 i+1-th bit를 일일이 swap하는 것은 너무 번거롭다.
//   홀수 번째 bit들을 right shift하고, 짝수 번째 bit들을 left shift하여
//   swap한 것과 동일한 효과를 만들자.
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)
//
long PairwiseSwap(long num) {
  unsigned long odd_mask = 0xaaaaaaaaaaaaaaaa;
  unsigned long even_mask = 0x5555555555555555;
  return ((num & odd_mask) >> 1) | ((num & even_mask) << 1);
}

int main() {
  long odd_bits = 0xaaaaaaaaaaaaaaaa;
  long even_bits = 0x5555555555555555;

  // Test #1. 0xaaaaaaaaaaaaaaaa를 pairwise swap한다.
  // 0x5555555555555555가 나와야 한다.
  cout << PairwiseSwap(odd_bits) << " " << even_bits << endl;

  // Test #2. 0x5555555555555555를 pairwise swap한다.
  // 0xaaaaaaaaaaaaaaaa가 나와야 한다.
  cout << PairwiseSwap(even_bits) << " " << odd_bits << endl;
  return 0;
}
