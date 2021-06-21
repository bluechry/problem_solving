// A string is a sequence of characters. A string may encode an integer,
// e.g., "123" encodes 123. In this problem, you are to implement methods that
// take a string representing an integer and return the corresponding integer,
// and vice versa. Your code should handle negative integers.
// You cannot use library functions like stoi in C++ and parseInt in Java.

#include <algorithm>
#include <chrono>
#include <cmath>
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
//   1. is_negative = s[0] == '-'
//   2. result = 0
//   3. 문자열을 앞에서부터 읽으면서 result * 10 + 문자 - '0'을 반복한다.
//   4. return (is_negative) ? -result : result
//
// Time Complexity: O(N), N is the length of a string.
//
// Space Complexity: O(1)

int StringToInt(const string& s) {
  bool is_negative = s[0] == '-';
  int result = 0;
  for (int i = is_negative ? 1 : 0; i < s.size(); ++i) {
    result = result * 10 + s[i] - '0';
  }
  return is_negative ? -result : result;
}

// Solution
//   1. is_negative = n < 0;
//   2. unsigned int abs_n = (is_negative) ? -n : n;
//      절대값을 'unsigned int' 타입에 저장함에 유의한다.
//      왜냐면 int 타입에 저장하면 INT_MIN * -1 = INT_MIN이 되어버린다.
//   3. abs_n의 각 자리수를 구하여 result string에 삽입
//   4. is_negative == true 이면 result_string.push_back('-')
//   5. reverse result string.
//
// Time Complexity: O(N), N is # of digits of an integer.
//
// Space Complexity: O(N), N is # of digits of an integer.

string IntToString(int n) {
  bool is_negative = n < 0;
  unsigned int abs_n = (is_negative) ? -n : n;
  string result;
  // 아래의 코드를 사용하면 result의 크기를 n의 자리수만큼 미리 확보할 수 있다.
  // 하지만 string의 기본 길이는 16이고 INT_MAX는 10자리이므로 이 과정을
  // 생략한다.
  // if (abs_n != 0) {
  //  result.reserve(ceil(log10(abs_n)));
  // }

  // do~while()로 처리해야 n = 0 이어도 처리할 수 있다.
  do {
    result.push_back(abs_n % 10 + '0');
    abs_n /= 10;
  } while (abs_n);
  if (is_negative) {
    result.push_back('-');
  }
  reverse(result.begin(), result.end());
  return result;
}

int main() {
{
  // Test #1.
  // s = "1234", n = 1234
  string s = "1234";
  int n = 1234;
  cout << StringToInt(s) << endl;
  cout << IntToString(n) << endl;
}
{
  // Test #2.
  // s = "-1234", n = -1234
  string s = "-1234";
  int n = -1234;
  cout << StringToInt(s) << endl;
  cout << IntToString(n) << endl;
}
{
  // Test #3.
  // s = "0", n = 0
  string s = "0";
  int n = 0;
  cout << StringToInt(s) << endl;
  cout << IntToString(n) << endl;
}
  return 0;
}
