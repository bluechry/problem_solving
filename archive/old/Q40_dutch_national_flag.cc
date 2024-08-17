// Given an array of n buckets, each containing a red, white, or blue pebble,
// sort them by color. The allowed operations are:
//   * swap(i, j): swap the pebble in bucket i with the pebble in bucket j.
//   * color(i): determine the color of the pebble in bucket i.
//
// The performance requirements are as follows:
//   * At most n calls to color().
//   * At most n calls to swap().
//   * Constant extra space.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   Dijkstra의 three-way partitioning을 사용한다.
//   Pivot 값은 WHITE로 한다.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

typedef enum {RED, WHITE, BLUE} Color;

void DutchFlag(vector<Color>* elems_ptr) {
  auto& elems = *elems_ptr;
  int lt = 0, gt = elems.size() - 1;
  int i = 0;
  while (i <= gt) {
    if (elems[i] < WHITE) {
      swap(elems[i++], elems[lt++]);
    } else if (elems[i] > WHITE) {
      swap(elems[i], elems[gt--]);
    } else {
      ++i;
    }
  }
}

int main() {
{
  // Test #1
  // elems[] = {BLUE, BLUE, BLUE, WHITE, WHITE, WHITE, RED, RED, RED}
  vector<Color> elems = {BLUE, BLUE, BLUE, WHITE, WHITE, WHITE, RED, RED, RED};
  DutchFlag(&elems);
  for (auto i: elems) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #2
  // elems[] = {BLUE, BLUE, BLUE}
  vector<Color> elems = {BLUE, BLUE, BLUE};
  DutchFlag(&elems);
  for (auto i: elems) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #3
  // elems[] = {BLUE, BLUE, BLUE, RED, RED, RED, WHITE, WHITE, WHITE}
  vector<Color> elems = {BLUE, BLUE, BLUE, RED, RED, RED, WHITE, WHITE, WHITE};
  DutchFlag(&elems);
  for (auto i: elems) {
    cout << i << " ";
  }
  cout << endl;
}
{
  // Test #4
  // elems[] = {}
  vector<Color> elems;
  DutchFlag(&elems);
  for (auto i: elems) {
    cout << i << " ";
  }
  cout << endl;
}
  return 0;
}
