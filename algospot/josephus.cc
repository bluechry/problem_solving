// Problem ID: JOSEPHUS
//
// 문제 설명
//   N개의 정수들이 주어졌을 때, 마지막으로 두 개의 정수들이 남을 때까지
//   매 K번 원소들(every Kth element)을 삭제하고, 마지막 남은 두 개의 원소들을
//   오름차순으로 출력하라.

#include <iostream>
#include <list>
#include <queue>

using namespace std;

// 풀이 방법 #1
//   1. std::list에 정수들을 저장한다.
//   2. 커서로 첫 번째 원소를 가리킨다.
//   3. 첫 번째 원소를 지운 후 커서를 K - 1번 앞으로 이동한다.
//   4. list에 원소가 두 개가 남을 때까지 2 ~ 3을 반복한다.
//
// 시간 복잡도
//   list에서 원소를 하나 지울 때마다 K - 1번 커서를 움직여야 하므로,
//   # of loops < N * (K - 1)
//   따라서, T(N) = O(N * K)
//
// 공간 복잡도
//   입력을 저장하기 위한 공간이 필요하므로,
//   S(N) = O(N)
//
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
//   K >> N 일 때 유리한 방법이다.
//   풀이 방법 #1에서 K-1 번 커서를 옮기는 것을, (K-1) % list.size() 번
//   옮기도록 수정한다.
//
// 시간 복잡도
//   list에서 원소를 하나 지운 후,
//   # of loops <= (N - 2) + (N - 3) + ... + 2  < N * (N - 1) / 2
//   따라서, T(N) = O(N^2)
//
// 공간 복잡도
//   입력을 저장하기 위한 공간이 필요하므로,
//   S(N) = O(N)
//
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
//   풀이 방법 #1,#2에서는 커서를 옮겼는데, 커서를 옮기는 대신 데이터 자체를
//   옮겨보자.
//
//   1. std::list가 아닌 std::queue에 원소들을 삽입한다.
//   2. queue의 첫 번째 원소를 pop한다.
//   3. 그 다음, K-1 개의 원소를 pop한 후 다시 push한다.
//   4. queue에 2개의 원소만 남을 때까지 2 ~ 3을 반복한다.
//
// 시간 복잡도
//   원소를 하나 pop() 할 때마다 K-1번 pop()과 push()를 반복하므로,
//   # of loops <= N * (K - 1)
//   따라서, T(N) = O(N * K)
//
// 공간 복잡도
//   입력을 저장하기 위한 공간이 필요하므로,
//   S(N) = O(N)
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
