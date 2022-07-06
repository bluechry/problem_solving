// Implement weight quick union version of Union-Find algorithm.

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
// * Avoid the skewed pattern when union two connected components p and q.
// * When union two connected components, set the component ID of the smaller
//   component to the component ID of the larger one.
// * When find the component ID of object p, track the component ID of p
//   iteratively until the component ID and the object ID are equal.
//
// Time Complexity
// * Union(): O(LogN), N is # of objects.
// * Find(): O(LogN)
//
// Space Complexity: O(N)

class UnionFind {
 public:
  UnionFind(int n):
    comp_id_(n),
    comp_size_(n, 1),
    num_comps_(n) {
    for (int i = 0; i < n; ++i) {
      comp_id_[i] = i;
    }
  }

  void Union(int p, int q) {
    int pid = Find(p);
    int qid = Find(q);
    if (pid == qid) {
      return;
    }
    if (comp_size_[pid] < comp_size_[qid]) {
      comp_id_[pid] = qid;
      comp_size_[qid] += comp_size_[pid];
    } else {
      comp_id_[qid] = pid;
      comp_size_[pid] += comp_size_[qid];
    }
    --num_comps_;
  }

  int Find(int p) const {
    while (comp_id_[p] != p) {
      p = comp_id_[p];
    }
    return p;
  }

  bool IsConnected(int p, int q) const {
    return (Find(p) == Find(q));
  }

  int Size() const {
    return comp_id_.size();
  }

  int Count() const {
    return num_comps_;
  }

  void Dump() const {
		for (auto id: comp_id_)
			printf("%d ", id);
		printf("\n");
  }

 private:
  vector<int> comp_id_;
  vector<int> comp_size_;
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
