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

  // 각 component의 크기(component에 속하는 object들의 개수)
  vector<int> size_;

  // Component들의 개수
  int n_comps_;
};

UnionFind::UnionFind(int n): id_(n), size_(n), n_comps_(n) {
  // 각 object가 속한 component의 ID는 각 object의 ID와 동일하다.
  // 각 component의 크기를 1으로 초기화한다.
  for (int i = 0; i < n; ++i) {
    id_[i] = i;
    size_[i] = 1;
  }
}

// Solution
// * WeightedQuickUnion과 동일하지만 runtime cost가 다르다.
// * Worst case의 runtime cost는,
//   '# of id_[] array access = 2 * cost of Find() + 3 = ~ 2lg*(N)'
void UnionFind::Union(int p, int q) {
  int pid = Find(p);
  int qid = Find(q);

  // p, q의 component ID가 동일한지 확인하지 않으면,
  // component의 size가 2배로 증가하는 버그가 발생하게 된다.
  if (pid == qid)
    return;
  if (size_[pid] < size_[qid]) {
    id_[pid] = qid;
    size_[qid] += size_[pid];
  } else {
    id_[qid] = pid;
    size_[pid] += size_[qid];
  }

  // Union이 한 번 일어날 때마다 component의 개수는 하나씩 줄어든다.
  --n_comps_;
}

// Solution
//  * WeightedQuickUnion과 유사하지만, p에서부터 root까지 path를 따라가면서
//    각 object의 parent를 grand parent로 바꾼다.
//  * Worst case의 runtime cost는,
//    '# of id_[] array access = ~lg*(N)', lg*(N) = # of times log() to get 1.
//    Hopcroft-Ullman에 의해서 증명을 참고.
//    Fredman-Saks에 의해서 linear algorithm이 없음이 증명.
int UnionFind::Find(int p) {
  while (id_[p] != p) {
    id_[p] = id_[id_[p]];
    p = id_[p];
  }
  return p;
}

// Solution
//  * Object p와 q의 component ID들을 비교한다.
//  * Worst case의 cost는,
//    '# of id_[] array access = 2 * cost of Find() = ~2lg*(N)'
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
