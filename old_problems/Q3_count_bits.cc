// Problem
//  Counting the number of set bits in an integer variable x.

#include <iostream>

using namespace std;

// Solution
//  모든 bit에 대해서 set bit인지 검사하면서 set bit의 개수를 센다.
//
//  while x > 0:
//    if (x & 0x1) ++count;
//    x >>= 1;
//  return count;
//
int CountSetBits(uint64_t num) {
  int count = 0;
  while (num) {
    count += (num & 0x1);
    num >>= 1;
  }
  return count;
}

// Solution
//  Rightmost set bit을 구한 후 unset 시키면서 set bit의 개수를 센다.
//
//  while x > 0:
//    ++count;
//    bit = x & ~(x - 1);
//    x ^= bit;
//  return count;
//
int CountSetBits2(uint64_t num) {
  int count = 0;
  while (num) {
    ++count;
    uint64_t bit = num & ~(num - 1);
    num ^= bit;
  }
  return count;
}

// Solution
//  Righmost set bit을 unset 시키면서 set bit의 개수를 센다.
//
//  while x > 0:
//    ++count;
//    x = x & (x - 1);
//  return count;
//
int CountSetBits3(uint64_t num) {
  int count = 0;
  while (num) {
    ++count;
    num &= (num - 1);
  }
  return count;
}

int main() {
  uint64_t x = 0xf8;
  printf("x: 0xf8 (11111000)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("# of set bits: %d\n", CountSetBits2(x));
  printf("# of set bits: %d\n", CountSetBits3(x));
  printf("\n");

  x = 0x00;
  printf("x: 0x00 (00000000)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("# of set bits: %d\n", CountSetBits2(x));
  printf("# of set bits: %d\n", CountSetBits3(x));
  printf("\n");

  x = 0x1UL << 63;
  printf("x: 0x80...00 (10...00)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("# of set bits: %d\n", CountSetBits2(x));
  printf("# of set bits: %d\n", CountSetBits3(x));
  printf("\n");

  x = ~0;
  printf("x: 0xff...ff (ff...ff)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("# of set bits: %d\n", CountSetBits2(x));
  printf("# of set bits: %d\n", CountSetBits3(x));
  return 0;
}
