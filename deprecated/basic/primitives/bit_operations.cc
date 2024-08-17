// Write the following bit operations:
//  GetBit()        // Get i-th bit.
//  SetBit()        // Set i-th bit.
//  ClearBit()      // Clear i-th bit.
//  ToggleBit()     // Toggle i-th bit.
//  UpdateBit()     // Update i-th bit to the given bit.
//  CountSetBits()  // Count the number of set bits.

//{{{
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
//  Assume that 0 <= i < 64.
//
//  GetBit(num, i): return num & (1 << i)
//  SetBit(num, i): return num | (1 << i)
//  ClearBit(num, i): return num & (~(1 << i))
//  ToggleBit(num, i): return num ^ (1 << i)
//  UpdateBit(num, i, val): return val ? SetBit(num, i) : ClearBit(num, i)
//
// Time Complexity: O(1)
//
// Space Complexity: O(1)

bool GetBit(int64_t num, int i) {
  return num & (1UL << i);
}

int64_t SetBit(int64_t num, int i) {
  return num | (1UL << i);
}

int64_t ClearBit(int64_t num, int i) {
  return num & ~(1UL << i);
}

int64_t ToggleBit(int64_t num, int i) {
  return num ^ (1UL << i);
}

int64_t UpdateBit(int64_t num, int i, bool set) {
  uint64_t mask = 1UL << i;
  return set ? (num | mask) : (num & ~mask);
}

// Solution
// * Set a counter zero.
// * While a given number is not zero, increase the counter and delete the right
//   most set bit of the number.
//
// Time Complexity: O(s), s is the number of set bits.
//
// Space Complexity: O(1)
int CountSetBits(int64_t num) {
  int count = 0;
  while (num) {
    ++count;
    num &= (num - 1);
  }
  return count;
}

//{{{
int main() {
  int64_t x = 0xf8;
  printf("x: 0xf8 (11111000)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("\n");

  x = 0x00;
  printf("x: 0x00 (00000000)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("\n");

  x = 0x1UL << 63;
  printf("x: 0x80...00 (10...00)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  printf("\n");

  x = ~0;
  printf("x: 0xff...ff (ff...ff)\n");
  printf("# of set bits: %d\n", CountSetBits(x));
  return 0;
}
//}}}
