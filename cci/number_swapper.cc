// Number Swapper: Write a function to swap a number in place (that is, without
// temporary variables).

#include <iostream>

using namespace std;

// Solution #1
//  임시 변수가 없는 상태에서 두 수를 swap하는 것은 불가능하다.
//  Swap하기보다는 두 수의 차이를 구한 후, 큰 수에서 차이를 빼고
//  작은 수에 차이를 더하여 두 수의 값을 바꾸어보자.
//  단, 임시 변수가 없으므로 두 수의 차이를 한 변수에 저장해야한다.
//
//  Assume that lhs is bigger than rhs.
//  1. lhs = lhs - rhs, lhs = diff of lhs and rhs.
//  2. rhs = rhs + lhs, rhs = original lhs.
//  3. lhs = rhs - lhs, lhs = original rhs.
void Swap(int* lhs, int* rhs) {
  *lhs = *lhs - *rhs;
  *rhs = *rhs + *lhs;
  *lhs = *rhs - *lhs;
}

// Solution #2
//  두 수의 '값의 차이'를 구하는 대신 'bit의 차이'를 구하는 방법을 쓰자.
//  xor 연산자를 사용하면 두 수의 차이를 구할 수 있고,
//  이 차이를 어느 한 수에 xor 하면 다른 한 수로 바뀌게 된다.
//
//  1. lhs = lhs ^ rhs, lhs = diff bits of lhs and rhs.
//  2. rhs = lhs ^ rhs, rhs = original lhs.
//  3. lhs = lhs ^ rhs, lhs = original rhs.
void SwapXor(int* lhs, int* rhs) {
  *lhs = *lhs ^ *rhs;
  *rhs = *lhs ^ *rhs;
  *lhs = *lhs ^ *rhs;
}

void Test1() {
  int lhs = 100, rhs = 50;
  printf("(%d, %d) -> ", lhs, rhs);
  Swap(&lhs, &rhs);
  printf("(%d, %d)\n", lhs, rhs);
}

void Test2() {
  int lhs = 50, rhs = 100;
  printf("(%d, %d) -> ", lhs, rhs);
  Swap(&lhs, &rhs);
  printf("(%d, %d)\n", lhs, rhs);
}

int main() {
  Test1();
  Test2();
  return 0;
}
