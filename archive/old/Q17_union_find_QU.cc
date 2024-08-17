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
//  * Object p와 q의 component ID들을 구하고 각각 pid와 qid라고 하자.
//    Object pid의 component ID를 qid로 설정한다.
//    그 결과, Object간에 connection이 tree를 형성하게 되고
//    각 tree의 root object의 ID가 component ID가 된다.
//  * Worst case는 object들의 connection이 skewed tree를 형성하는 경우이다.
//    Worst case의 cost는,
//    '# of id_[] array access = cost of Find() * 2 + 1 ~ 2N'
void UnionFind::Union(int p, int q) {
  int pid = Find(p);
  int qid = Find(q);
  id_[pid] = qid;

  // Union이 한 번 일어날 때마다 component의 개수는 하나씩 줄어든다.
  --n_comps_;
}

// Solution
//  * Object p에 대하여, p 값과 id_[p] 값이 동일할 때까지
//    id_[...[id_[p]...]를 반복한다.
//  * Worst case는 object들의 connection이 skewed tree를 형성하는 경우이다.
//    Worst case의 cost는,
//    '# of id_[] array access = N-1 ~N'
int UnionFind::Find(int p) {
  while (id_[p] != p)
    p = id_[p];
  return p;
}

// Solution
//  * Object p와 q의 component ID들을 비교한다.
//  * Worst case는 object들의 connection이 skewed tree를 형성하는 경우이다.
//    Worst case의 cost는,
//    '# of id_[] array access = 2 * cost of Find() ~2N'
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
