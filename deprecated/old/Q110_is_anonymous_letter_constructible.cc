// Write a program which takes text for an anonymous letter and text for a
// magazine and determines if it is possible to write the anonymous letter
// using the magazine. The anonymous letter can be written using the magazine
// if for each character in the anonymous letter, the number of times it
// appears in the anonymous letter is no more than the number of times it
// appears in the magazine.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline auto GetTime() {
  return chrono::steady_clock::now();
}

inline auto GetElapsedTime(Time start, Time end) {
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

// Solution
//
// Time Complexity
//
// Space Complexity

bool IsConstructibleLetter(const string& letter, const string& magazine) {
  // Make the frequency count table of the letter.
  unordered_map<char, int> letter_char_freq;
  for (char c: letter) {
    ++letter_char_freq[c];
  }

  // Discount the frequency of characters of the magazine.
  for (char c: magazine) {
    auto iter = letter_char_freq.find(c);
    if (iter == letter_char_freq.end()) {
      continue;
    }
    if (--letter_char_freq[c] == 0) {
      letter_char_freq.erase(c);
    }
    if (letter_char_freq.empty()) {
      return true;
    }
  }

  // 'return false' 해서는 안 된다.
  // 그럴 경우 letter와 magazine이 모두 empty일 때 true를 반환해야하는데
  // false를 반환하게 된다.
  return letter_char_freq.empty();
}

int main() {
{
  // Test #1.
  // letter: "this is a letter."
  // magazine: "this is a letter. that is a book."
  // return value: true
  string letter = "this is a letter.";
  string magazine = "this is a letter. that is a book.";
  cout << (IsConstructibleLetter(letter, magazine) ? "true" : "false") << endl;
}
{
  // Test #2.
  // letter: "this is a letter."
  // magazine: "this is a book."
  // return value: false
  string letter = "this is a letter.";
  string magazine = "that is a book.";
  cout << (IsConstructibleLetter(letter, magazine) ? "true" : "false") << endl;
}
{
  // Test #3.
  // letter: ""
  // magazine: ""
  // return value: true
  string letter = "";
  string magazine = "";
  cout << (IsConstructibleLetter(letter, magazine) ? "true" : "false") << endl;
}
{
  // Test #4.
  // letter: ""
  // magazine: "this is a book"
  // return value: true
  string letter = "";
  string magazine = "this is a book";
  cout << (IsConstructibleLetter(letter, magazine) ? "true" : "false") << endl;
}
{
  // Test #5.
  // letter: "this is a letter"
  // magazine: ""
  // return value: false
  string letter = "this is a letter";
  string magazine = "";
  cout << (IsConstructibleLetter(letter, magazine) ? "true" : "false") << endl;
}
  return 0;
}
