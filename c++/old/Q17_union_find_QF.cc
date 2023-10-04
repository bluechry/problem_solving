// Implement Union-Find data structure using QuickFind algorithm
// Assume that an object and a component are represented by ID of [0 ~ N) and
// ID is 32-bit signed integer.

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
 public:
  // UnionFind 자료구조를 초기화한다.
  UnionFind(int n);

  // Object p와 object q를 연결한다.
  void Union(int p, int q);

  // Object p가 속한 component의 ID를 반환한다.
  int Find(int p);

  // Object p와 object q가 연결되었는가?
  bool IsConnected(int p, int q);

  // Component의 개수를 반환한다.
  int CountComps();

  // UnionFind 자료구조를 dump한다.
  void DumpComps();

 private:
  // 각 object가 속한 component들의 ID들
  vector<int> id_;

  // Component들의 개수
  int n_comps_;
};

UnionFind::UnionFind(int n): id_(n), n_comps_(n) {
  // 각 object가 속한 component의 ID는 각 object의 ID와 동일하다.
  for (int i = 0; i < n; ++i)
    id_[i] = i;
}

// Solution
// * Object p와 동일한 component ID를 갖는 object들(p 포함)의 component ID를
//   object q의 component ID로 변경한다.
// * Component의 개수는 Union()이 한 번 수행될 때마다 1씩 줄어든다.
// * Cost model을 id_[]에 access하는 횟수로 정의하자.
//   Worst case는 N-1개의 object가 p와 동일한 component ID를 갖는 경우이다.
//   '# of array access = 2N + 2', time complexity는 '~2N' 이다.
void UnionFind::Union(int p, int q) {
  int pid = id_[p];
  int qid = id_[q];
  for (int i = 0; i < id_.size(); ++i) {
    if (id_[i] == pid)
      id_[i] = qid;
  }
  --n_comps_;
}

// Solution
// * 단순하게 p의 component ID를 반환하면 된다.
// * Time complexity는 ~1 이다.
int UnionFind::Find(int p) {
  return id_[p];
}

// Solution
// * p와 q의 component ID들을 비교한다.
// * Time complexity는 ~1 이다.
bool UnionFind::IsConnected(int p, int q) {
  return (Find(p) == Find(q));
}

int UnionFind::CountComps() {
  return n_comps_;
}

void UnionFind::DumpComps() {
  for (auto id: id_)
    printf("%d ", id);
  printf("\n");
}

int main() {
  UnionFind uf(10);
  vector<pair<int, int>> input = {pair<int, int>(4, 3),
                                  pair<int, int>(3, 8),
                                  pair<int, int>(6, 5),
                                  pair<int, int>(9, 4),
                                  pair<int, int>(2, 1),
                                  pair<int, int>(8, 9),
                                  pair<int, int>(5, 0),
                                  pair<int, int>(7, 2),
                                  pair<int, int>(6, 1),
                                  pair<int, int>(1, 0),
                                  pair<int, int>(6, 7),
                                  pair<int, int>(1, 8)};
  for (auto p: input) {
    if (!uf.IsConnected(p.first, p.second)) {
      uf.Union(p.first, p.second);
      printf("%d and %d are connected now.", p.first, p.second);
      printf("# of components = %d\n", uf.CountComps());
    } else {
      printf("%d and %d are already connected.\n", p.first, p.second);
    }
  }
  printf("\nDump UF data structure.\n");
  uf.DumpComps();
  return 0;
}
