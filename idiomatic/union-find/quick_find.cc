// Implement quick find version of Union-Find algorithm.

//{{{
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

using Time = chrono::time_point<chrono::steady_clock>;

inline Time GetTime() {
  // Returning auto type is defined in c++-14.
  return chrono::steady_clock::now();
}

inline uint64_t GetElapsedTime(Time start, Time end) {
  // Returning auto type is defined in c++-14.
  return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}
//}}}

// Solution
// * Find the ID of the connected component that object p belongs to in constant
//   time.
// * When union two connected components pid and qid, set the component ID of
//   each object in component pid to qid.
// * When find the component ID of object p, just return the component ID that
//   corresponds to p.
//
// Time Complexity
// * Union(): O(N), N is # of objects.
// * Find(): O(1)
//
// Space Complexity: O(N)

class UnionFind {
 public:
  UnionFind(int n):
    comp_id_(n),
    num_comps_(n) {
    for (int i = 0; i < comp_id_.size(); ++i) {
      comp_id_[i] = i;
    }
  }

  void Union(int p, int q) {
    int pid = Find(p);
    int qid = Find(q);
    if (pid == qid) {
      return;
    }
    for (int i = 0; i < comp_id_.size(); ++i) {
      if (comp_id_[i] == pid) {
        comp_id_[i] = qid;
      }
    }
    --num_comps_;
  }

  int Find(int p) const {
    return comp_id_[p];
  }

  bool IsConnected(int p, int q) const {
    return (Find(p) == Find(q));
  }

  int Count() const {
    return num_comps_;
  }

  int Size() const {
    return comp_id_.size();
  }

  void Dump() const {
    for (auto id: comp_id_)
      printf("%d ", id);
    printf("\n");
  }

 private:
  vector<int> comp_id_;
  int num_comps_;
};

//{{{
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
      printf("# of components = %d\n", uf.Count());
    } else {
      printf("%d and %d are already connected.\n", p.first, p.second);
    }
  }
  printf("\nDump UF data structure.\n");
  uf.Dump();
  return 0;
}
//}}}
