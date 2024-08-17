// Solve the following bit manipulation problems.
// Assume that LSB is the 0-th bit.
//  * Clear bits from MSB to i-th bit.
//  * Clear bits from i-th bit to 0-th bit.
//  * Clear bits from i-th bit to j-th bit (i < j).
//  * Update i-th bit to a give value, 0 or 1.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

void DumpBits(long num) {
  unsigned long mask = 1UL << 63;
  while (mask != 0x0) {
    cout << ((num & mask) ? 1 : 0);
    mask >>= 1;
  }
  cout << endl;
}

long ClearMSBToIthBit(long num, int i) {
  return num & ((1UL << i) - 1);
}

long ClearIthTo0thBit(long num, int i) {
  // Note
  // * num = '-1UL << 64'은 warning이 발생하지만 num = 0으로 설정된다.
  // * i = 63, num = '-1UL << (i + 1)' 은 warning이 발생하지 않으나
  //   num = -1UL 그대로 유지된다.
  unsigned long mask = (i == 63) ? 0 : (-1UL << (i + 1));
  return num & mask;
}

long ClearIthToJthBit(long num, int i, int j) {
  // Note
  // * num = '-1UL << 64'은 warning이 발생하지만 num = 0으로 설정된다.
  // * i = 63, num = '-1UL << (i + 1)' 은 warning이 발생하지 않으나
  //   num = -1UL 그대로 유지된다.
  unsigned long mask = ((i == 63) ? 0 : (-1UL << (i + 1))) | ((1UL << j) - 1);
  return num & mask;
}

long UpdateBit(long num, int i, bool on) {
#if 1
  // Note
  // 아래 방법과 비교하여 코드는 깔끔하고 속도차이는 없다.
  unsigned long mask = 1UL << i;
  return on ? (num | mask) : (num & ~mask);
#else
  unsigned long bit = on ? 1UL : 0UL;
  unsigned long mask = ~(1UL << i);
  return (num & mask) | (bit << i);
#endif
}

int main() {
{
  // Test #1. ClearMSBToIthBit()
  cout << "\nTest #1. ClearMSBToIthBit()" << endl;
  long num = -1;
  cout << "Clear MSB ~ 63: ";
  DumpBits(ClearMSBToIthBit(num, 63));
  cout << "Clear MSB ~ 62: ";
  DumpBits(ClearMSBToIthBit(num, 62));
  cout << "Clear MSB ~ 1: ";
  DumpBits(ClearMSBToIthBit(num, 1));
  cout << "Clear MSB ~ 0: ";
  DumpBits(ClearMSBToIthBit(num, 0));
}
{
  // Test #2. ClearIthTo0thBit()
  cout << "\nTest #2. ClearIthTo0thBit()" << endl;
  long num = -1;
  cout << "Clear 63 ~ 0: ";
  DumpBits(ClearIthTo0thBit(num, 63));
  cout << "Clear 62 ~ 0: ";
  DumpBits(ClearIthTo0thBit(num, 62));
  cout << "Clear 1 ~ 0: ";
  DumpBits(ClearIthTo0thBit(num, 1));
  cout << "Clear 0 ~ 0: ";
  DumpBits(ClearIthTo0thBit(num, 0));
}
{
  // Test #3. ClearIthToJthBit()
  cout << "\nTest #3. ClearIthToJthBit()" << endl;
  long num = -1;
  cout << "Clear 63 ~ 0: ";
  DumpBits(ClearIthToJthBit(num, 63, 0));
  cout << "Clear 62 ~ 0: ";
  DumpBits(ClearIthToJthBit(num, 62, 0));
  cout << "Clear 1 ~ 0: ";
  DumpBits(ClearIthToJthBit(num, 1, 0));
  cout << "Clear 0 ~ 0: ";
  DumpBits(ClearIthToJthBit(num, 0, 0));
}
{
  // Test #4. UpdateBit()
  cout << "\nTest #4. UpdateBit()" << endl;
  cout << "Update -1, 63, false: ";
  DumpBits(UpdateBit(-1, 63, false));
  cout << "Update -1, 62, false: ";
  DumpBits(UpdateBit(-1, 62, false));
  cout << "Update -1, 1, false: ";
  DumpBits(UpdateBit(-1, 1, false));
  cout << "Update -1, 0, false: ";
  DumpBits(UpdateBit(-1, 0, false));
  cout << "Update 0, 63, true: ";
  DumpBits(UpdateBit(0, 63, true));
}
  return 0;
}
