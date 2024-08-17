// Implement a function which takes as input an array and a key, and updates
// the array so that all occurrences of the input key have been removed and
// the remaining elements have been shifted left to fill the emptied indices.
// Return the number of remaining elements. There are no requirements as to the
// values stored beyond the last valid element.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Solution
//   elems[]을 scan하면서 key와 다른 값이 나오면 elems[]의 앞에서부터
//   차례대로 저장해나간다.
//
// Time Complexity
//   Cost model = '# of array accesses'
//   T(N) = O(N), N is the length of elems[].
//
// Space Complexity: O(1)
size_t DeleteKey(vector<int>* elems_ptr, int key) {
  auto& elems = *elems_ptr;
  size_t write_idx = 0;
  for (size_t i = 0; i < elems.size(); ++i) {
    if (elems[i] != key) {
      elems[write_idx++] = elems[i];
    }
  }
  return write_idx;
}

int main() {
{
  // Test #1.
  // elems[]  = {0, 1, 0, 1, 0, 1, 0, 1}, key = 1
  // result[] = {0, 0, 0, 0, 0, 1, 0, 1}, return_value = 4
  vector<int> elems = {0, 1, 0, 1, 0, 1, 0, 1};
  size_t size = DeleteKey(&elems, 1);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i];
  }
  cout << endl;
}
{
  // Test #2.
  // elems[]  = {0, 0, 0, 0, 0, 0, 0, 0}, key = 0
  // result[] = {0, 0, 0, 0, 0, 0, 0, 0}, return_value = 0
  vector<int> elems = {0, 0, 0, 0, 0, 0, 0, 0};
  size_t size = DeleteKey(&elems, 0);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i];
  }
  cout << endl;
}
{
  // Test #3.
  // elems[]  = {0, 0, 0, 0, 0, 0, 0, 0}, key = 1
  // result[] = {0, 0, 0, 0, 0, 0, 0, 0}, return_value = 8
  vector<int> elems = {0, 0, 0, 0, 0, 0, 0, 0};
  size_t size = DeleteKey(&elems, 1);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i];
  }
  cout << endl;
}
{
  // Test #4.
  // elems[] = {}, key = 0
  // result[] = {}, return_value = 0
  vector<int> elems;
  size_t size = DeleteKey(&elems, 0);
  for (size_t i = 0; i < size; ++i) {
    cout << elems[i];
  }
  cout << endl;
}
  return 0;
}
