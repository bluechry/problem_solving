// Problem ID: JOSEPHUS
//
// 문제 설명
//

#include <iostream>
#include <list>

using namespace std;

// 풀이 방법 #1
//
// 시간 복잡도
//   O(NK)
//
// 공간 복잡도
//   O(1)
void Josephus(list<int>& people, int stride) {
  auto pos = people.begin();
  while (people.size() > 2) {
    pos = people.erase(pos);
    if (pos == people.end())
      pos = people.begin();

    for (int i = 0; i < stride - 1; ++i) {
      ++pos;
      if (pos == people.end())
        pos = people.begin();
    }
  }
  return;
}

// 풀이 방법 #2
//
// 시간 복잡도
//   O(N^2)
//
// 공간 복잡도
//   O(1)
void Josephus2(list<int>& people, int stride) {
  auto pos = people.begin();
  while (people.size() > 2) {
    pos = people.erase(pos);
    if (pos == people.end())
      pos = people.begin();

    int num_move = (stride - 1) % people.size();
    for (int i = 0; i < num_move; ++i) {
      ++pos;
      if (pos == people.end())
        pos = people.begin();
    }
  }
  return;
}

int main() {
  int C;
  cin >> C;
  while (C-- != 0) {
    int N, K;
    cin >> N >> K;

    list<int> people;
    for (int i = 1; i <= N; ++i)
      people.push_back(i);
    Josephus2(people, K);

    cout << people.front() << " " << people.back() << endl;
  }
  return 0;
}
