// Given a string, print in alphabetical order each character that appears in
// the string, and the number of times that it appears.
// For example, if the string is "bcdacebe",
// output "(a, 1), (b, 2), (c, 2), (d, 1), (e, 2)".

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//   주어진 문자열은 빈 문자열이 아니라고 가정한다.
//   1. 주어진 문자열 s를 정렬한다.
//   2. freq = 1
//   3. s[1]부터 scan하면서
//      * s[i - 1] == s[i]이면 freq를 증가시킨다.
//      * s[i - 1] != s[i]이면 (s[i - 1], freq)를 출력하고, freq = 1로 설정한다.
//
// Time Complexity: O(NlogN), N = |elems|
//
// Space Complexit: O(1)

void CountCharFrequency(string s) {
  sort(s.begin(), s.end());

  int freq = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i - 1] == s[i]) {
      ++freq;
    } else {
      printf("(%c, %d), ", s[i - 1], freq);
      freq = 1;
    }
  }
  printf("(%c, %d)\n", s.back(), freq);
}

// Solution
//   문자열의 문자는 [a-z]로 구성된다고 가정한다.
//   1. 각 문자의 값을 index로 하는 배열을 정의하고 각 원소를 0으로 초기화한다.
//   2. 문자열을 scan하면서 해당 문자를 index로 하는 원소의 값을 1씩 증가시킨다.
//   3. 배열을 scan하면서 원소의 값이 0이 아닌 경우 index에 대응되는 문자와
//      원소의 값을 출력한다.
//
// Time Complexity: O(N), N = length of the string
//
// Space Complexity: O(1), an array of sizeof(int) * 26 bytes.

void CountCharFrequency2(string s) {
  vector<int> freq(26, 0);
  for (char c: s) {
    ++freq[c - 'a'];
  }

  bool is_first = true;
  for (int i = 0; i < freq.size(); ++i) {
    if (freq[i]) {
      if (is_first) {
        printf("(%c, %d)", 'a' + i, freq[i]);
        is_first = false;
      } else {
        printf(", (%c, %d)", 'a' + i, freq[i]);
      }
    }
  }
  cout << endl;
}

int main() {
  string s = "bcdacebe";
  CountCharFrequency(s);
  CountCharFrequency2(s);
  return 0;
}
