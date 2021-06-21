// Write a program which takes as input a sorted array and updates it so that
// all duplicates have been removed and the remaining elements have been shifted
// left to fill the emptied indices. Return the number of valid elements. There
// are no requirements as to the values stored beyond the last valid element.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems[]의 0번 원소는 그대로 두고, 1번 원소부터 끝까지 scan하면서,
//   처음보는 원소가 나오면 1번 위치에서부터 차례대로 저장해나간다.
//   i번 원소가 처음보는 원소인지 알기위해서는 마지막에 저장한 원소와
//   비교해 보면 된다.
//
// Time Complexity: O(N), N is the length of elems[].
//
// Space Complexity: O(1)
size_t DeleteDuplicates(vector<int>* elems_ptr) {
  auto& elems = *elems_ptr;
  if (elems.empty()) {
    return 0;
  }

  size_t write_idx = 1;
  for (size_t i = 1; i < elems.size(); ++i) {
    if (elems[write_idx - 1] != elems[i]) {
      elems[write_idx++] = elems[i];
    }
  }
  return write_idx;
}

int main() {
{
  // Test #1.
  // elems[] = {}
  // result[] = {}, return_value = 0
  vector<int> elems;
  size_t size = DeleteDuplicates(&elems);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i] << " ";
  }
  cout << endl;
}
{
  // Test #2.
  // elems[] = {1, 1, 1, 1, 1, 1, 1, 1}
  // result[] = {1}, return_value = 1
  vector<int> elems(8, 1);
  size_t size = DeleteDuplicates(&elems);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i] << " ";
  }
  cout << endl;
}
{
  // Test #3.
  // elems[] = {1, 1, 2, 2, 3, 3, 4, 4}
  // result[] = {1, 2, 3, 4}, return_value = 4
  vector<int> elems = {1, 1, 2, 2, 3, 3, 4, 4};
  size_t size = DeleteDuplicates(&elems);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i] << " ";
  }
  cout << endl;
}
  return 0;
}
