// Problem ID: JOSEPHUS
//
// 문제 설명
//

#include <iostream>
#include <list>
#include <queue>

using namespace std;

// 풀이 방법 #1
//
// 시간 복잡도
//   O(NK)
//
// 공간 복잡도
//   O(N) : 입력을 저장하기 위한 공간
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
//   O(N) : 입력을 저장하기 위한 공간
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

// 풀이 방법 #3
//
// 시간 복잡도
//   O(N^2)
//
// 공간 복잡도
//
void Josephus3(queue<int>& people, int stride) {
  while (people.size() > 2) {
    people.pop();
    int num_move = (stride - 1) % people.size();
    for (int i = 0; i < num_move; ++i) {
      people.push(people.front());
      people.pop();
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

#if 0
    // Josephus1,2에 사용
    list<int> people;
    for (int i = 1; i <= N; ++i)
      people.push_back(i);
    Josephus2(people, K);
    cout << people.front() << " " << people.back() << endl;
#else
    // Josephus3에 사용
    queue<int> people;
    for (int i = 1; i <= N; ++i)
      people.push(i);
    Josephus3(people, K);
    if (people.front() < people.back())
      cout << people.front() << " " << people.back() << endl;
    else
      cout << people.back() << " " << people.front() << endl;
#endif
  }
  return 0;
}
