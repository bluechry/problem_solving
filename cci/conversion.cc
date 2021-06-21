// Write a function to determine the number of bits you would need to flip to
// convert integer A to integer B.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
// * A xor B를 하여 서로 다른 bit를 갖는 위치가 1로,
//   같은 bit를 갖는 위치는 0으로 하는 bit sequence를 얻는다.
// * 위에서 얻은 bit sequence가 0이 될 때까지 right-most set bit을 지우면서
//   지운 회수를 count한다.
//
// Time Complexity: O(N), N is # of diffent bits between A and B.
//
// Space Complexity: O(1)
int Conversion(long a, long b) {
  int count = 0;
  for (int c = a ^ b; c != 0; c &= (c - 1)) {
    ++count;
  }
  return count;
}

int main() {
  long A = 29;  // 11101
  long B = 15;  // 01111
  cout << Conversion(A, B) << endl;
  return 0;
}
