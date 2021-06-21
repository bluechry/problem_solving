// Problem Statement
//  Solve the following bit manipulation problems.
//    * Isolate the rightmost set bit. ex) 11001000 --> 00001000
//    * Turn off the rightmost set bit. ex) 11001000 --> 11000000
//    * Right propagate the rightmost set bit. ex) 11001000 --> 11001111
//    * Isolate the rightmost 0-bit. ex) 11001000 --> 00000001
//    * Turn on the rightmost 0-bit. ex) 11001000 --> 11001001

#include <iostream>

using namespace std;

// Isolate the rightmost set bit.
//
// Let       x = 11001000
//         x-1 = 11000111
//      ~(x-1) = 00111000
//  x & ~(x-1) = 00001000
uint64_t IsolateRightmostSetBit(uint64_t x) {
  return x & ~(x - 1);
}

// Turn off the rightmost set bit.
//
// Let       x = 11001000
//         x-1 = 11000111
//   x & (x-1) = 11000000
uint64_t TurnOffRightmostSetBit(uint64_t x) {
  return x & (x - 1);
}

// Right propagate the rightmost set bit.
//
// Let       x = 11001000
//         x-1 = 11000111
//   x | (x-1) = 11001111
uint64_t PropagateRightmostSetBit(uint64_t x) {
  return x | (x - 1);
}

// Isolate the rightmost 0-bit.
//
// Let       x = 11001000
//         x+1 = 11001001
//          ~x = 00110111
//  ~x & (x+1) = 00000001
uint64_t IsolateRightmostZeroBit(uint64_t x) {
  return ~x & (x + 1);
}

// Turn on the rightmost 0-bit.
//
// Let       x = 11001000
//         x+1 = 11001001
//   x | (x+1) = 11001001
uint64_t TurnOnRightmostZeroBit(uint64_t x) {
  return x | (x + 1);
}

int main() {
  uint64_t x = 0xc8;
  printf("Original x: 0xc8 (11001000)\n");
  printf("Isolate the rightmost set bit: %lx\n", IsolateRightmostSetBit(x));
  printf("Turn off the rightmost set bit: %lx\n", TurnOffRightmostSetBit(x));
  printf("Right propagate the rightmost set bit: %lx\n", PropagateRightmostSetBit(x));
  printf("Isolate the rightmost 0-bit: %lx\n", IsolateRightmostZeroBit(x));
  printf("Turn on the rightmost zero bit: %lx\n", TurnOnRightmostZeroBit(x));
  return 0;
}
