// Write a program which takes as input an array of characters, and removes
// each 'b' and replaces 'a' by two 'd's. Specifically, along with the array,
// you are provided an integer-valued size. Size denotes the number of entries
// of the array that the operation is to be applied to. You do not have to worry
// preserving about subsequent entries.
// For example, if the array is <a, b, a, c, _> and the size is 4, then you can
// return <d, d, d, d, c> and 5. You can assume there is enough space in the
// array to hold the final result.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   결과 문자열을 저장할 수 있는 공간이 있다면 한 번의 scan으로 끝낼 수 있다.
//   본 문제의 의도는 in-place algorithm을 작성하라는 것이므로 추가 공간없이
//   주어진 문자열을 덮어쓰는 것으로 한다.
//
//   알고리즘을 two pass로 디자인한다.
//   1. 첫번째 pass에서는 'b'를 제거하고 'a'의 개수를 count한다.
//   2. 두번째 pass에서는 'a'의 개수를 가지고 결과 문자열의 길이를 구하고,
//      결과 문자열의 끝에서부터 원래 문자열을 역순으로 대입한다.
//      대입하는 과정에서 'a'를 'dd'로 치환한다.
//
// Time Complexity: O(N)
//
// Space Complexity: O(1)

int ReplaceAndRemove(char s[], int size) {
  // 1st pass: remove 'b' and count 'a'.
  int write_idx = 0, num_a = 0;
  for (int i = 0; i < size; ++i) {
    if (s[i] != 'b') {
      s[write_idx++] = s[i];
    }
    if (s[i] == 'a') {
      ++num_a;
    }
  }

  // 2nd pass: replace 'a' with 'dd'.
  size = write_idx;
  int final_size = size + num_a;
  write_idx = final_size - 1;
  for (int i = size - 1; i >= 0; --i) {
    if (s[i] == 'a') {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    } else {
      s[write_idx--] = s[i];
    }
  }
  return final_size;
}

// Another implementation
// This one is easier to code faster.

int ReplaceAndRemove2(char s[], int size) {
  // 1st pass: count 'a' and 'b'.
  int num_a = 0, num_b = 0;
  for (int i = 0; i < size; ++i) {
    if (s[i] == 'a') {
      ++num_a;
    } else if (s[i] == 'b') {
      ++num_b;
    }
  }

  // 2nd pass: remove 'b' and replace 'a' with 'dd'.
  int final_size = size + num_a - num_b;
  int write_idx = final_size - 1;
  for (int i = size - 1; i >= 0; --i) {
    if (s[i] == 'a') {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    } else if (s[i] != 'b') {
      s[write_idx--] = s[i];
    }
  }
  return final_size;
}

int main() {
{
  // Test #1.
  // s[] = {a, b, a, c, _, _, ..., _}, size = 4
  // return value: s[] = {d, d, d, c, _, _, ..., _}, size = 5
  char s[1024] = {'a', 'b', 'a', 'c', };
  int size = ReplaceAndRemove(s, 4);
  for (int i = 0; i < size; ++i) {
    cout << s[i];
  }
  cout << endl;

  char s2[1024] = {'a', 'b', 'a', 'c', };
  int size2 = ReplaceAndRemove2(s2, 4);
  for (int i = 0; i < size2; ++i) {
    cout << s2[i];
  }
  cout << endl;
}
{
  // Test #2.
  // s[] = {b, b, b, b, b, _, _, _, ..., _}, size = 5
  // return value: s[] = {}, size = 0
  char s[1024] = {'b', 'b', 'b', 'b', 'b'};
  int size = ReplaceAndRemove(s, 0);
  for (int i = 0; i < size; ++i) {
    cout << s[i];
  }
  cout << endl;

  char s2[1024] = {'b', 'b', 'b', 'b', 'b'};
  int size2 = ReplaceAndRemove(s2, 0);
  for (int i = 0; i < size2; ++i) {
    cout << s2[i];
  }
  cout << endl;
}
{
  // Test #3.
  // s[] = {a, a, a, a, _, _, ..., _}, size = 4
  // return value: s[] = {d, d, d, d, d, d, d, d}, size = 8
  char s[1024] = {'a', 'a', 'a', 'a', };
  int size = ReplaceAndRemove(s, 4);
  for (int i = 0; i < size; ++i) {
    cout << s[i];
  }
  cout << endl;

  char s2[1024] = {'a', 'a', 'a', 'a', };
  int size2 = ReplaceAndRemove(s2, 4);
  for (int i = 0; i < size2; ++i) {
    cout << s2[i];
  }
  cout << endl;
}
  return 0;
}
