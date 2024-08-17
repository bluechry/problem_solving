// Write a program that takes as input a set of words and returns groups of
// anagrams for those words. Each group must contain at least two words.
//
// For example, if the input is "debitcard", "elvis", "silent", "badcredit",
// "lives", "freedom", "listen", "levis", "money", then there are three groups
// of anagrams: (1)"debitcard", "badcredit"; (2)"elvis", "lives", "levis";
// (3)"silent", "listen". Note that "money" does not appear in any group,
// since it has no anagrams in the set.

#include <algorithm>
#include <chrono>
#include <iostream>
#include <unordered_map>
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
//   1. 주어진 단어들을 anagram 끼리 하나의 hash table entry에 저장되도록
//      hashing한다. Hash key로 단어를 정렬한 문자열을 사용하면 된다.
//   2. Hashing이 완료된 후, hash table entry를 scan하여 두 개 이상의 단어가
//      저장된 entry들을 모아서 결과로 반환한다.
//
// Time Complexity
//   * Hashing cost: O(N * MlogM), N = # of words,
//                                 M = the length of the longest word.
//   * Insertion cost: O(N * M)
//   * Retrieval cost: O(N * M)
//
// Space Complexity
//   * Hash table size: O(N * M)
//   * Result array size: O(N * M)

vector<vector<string>> FindAnagrams(const vector<string>& words) {
  // Make hash table of words.
  unordered_map<string, vector<string>> sorted_str_to_anagrams;
  for (const string& w: words) {
    string sorted_str = w;
    sort(sorted_str.begin(), sorted_str.end());
    sorted_str_to_anagrams[sorted_str].emplace_back(w);
  }

  // Make groups of anagrams.
  vector<vector<string>> anagram_groups;
  for (const auto& p: sorted_str_to_anagrams) {
    if (p.second.size() > 1) {
      anagram_groups.emplace_back(p.second);
    }
  }
  return anagram_groups;
}

int main() {
{
  // Test #1
  // strings: {"debitcard", "elvis", "silent", "badcredit", "lives", "freedom",
  //           "listen", "levis", "money"};
  // return value: {{"debitcard", "badcredit"}, {"elvis", "lives", "levis"},
  //                {"silent", "listen"}}
  vector<string> words = {"debitcard", "elvis", "silent", "badcredit", "lives",
                          "freedom", "listen", "levis", "money"};
  vector<vector<string>> anagrams = FindAnagrams(words);
  cout << "Test #1" << endl;
  for (const auto& a: anagrams) {
    cout << '{';
    for (const string& w: a) {
      cout << w << ' ';
    }
    cout << '}';
    cout << endl;
  }
  cout << endl;
}
{
  // Test #2
  // strings: {"debitcard", "elvis", "silent", "freedom", "money"};
  // return value: {}
  vector<string> words = {"debitcard", "elvis", "silent", "freedom", "money"};
  vector<vector<string>> anagrams = FindAnagrams(words);
  cout << "Test #2" << endl;
  for (const auto& a: anagrams) {
    cout << '{';
    for (const string& w: a) {
      cout << w << ' ';
    }
    cout << '}';
    cout << endl;
  }
  cout << endl;
}
{
  // Test #3
  // strings: {}
  // return value: {}
  vector<string> words;
  vector<vector<string>> anagrams = FindAnagrams(words);
  cout << "Test #3" << endl;
  for (const auto& a: anagrams) {
    cout << '{';
    for (const string& w: a) {
      cout << w << ' ';
    }
    cout << '}';
    cout << endl;
  }
  cout << endl;
}
  return 0;
}
