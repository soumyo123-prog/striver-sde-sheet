#include <bits/stdc++.h>
using namespace std;

class DSU {
  vector<int> size;
  vector<int> parent;

 public:
  DSU(int v) {
    for (int i = 0; i < v; i++) {
      size.push_back(1);
      parent.push_back(i);
    }
  }

  int find(int u) {
    if (u == parent[u]) {
      return u;
    }
    return parent[u] = find(parent[u]);
  }

  void unionBySize(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) {
      return;
    }

    if (size[pa] > size[pb]) {
      size[pa] += size[pb];
      parent[pb] = pa;
    } else {
      size[pb] += size[pa];
      parent[pa] = pb;
    }
  }
};

int spanningTree(int v, vector<vector<int>> adj[]) {
  vector<pair<int, pair<int, int>>> edges;

  for (int i = 0; i < v; i++) {
    for (auto j : adj[i]) {
      edges.push_back({j[1], {i, j[0]}});
    }
  }

  sort(edges.begin(), edges.end());

  int sum = 0;

  DSU dsu(v);

  for (int i = 0; i < edges.size(); i++) {
    int wt = edges[i].first, u = edges[i].second.first,
        v = edges[i].second.second;

    if (dsu.find(u) != dsu.find(v)) {
      sum += wt;
      dsu.unionBySize(u, v);
    }
  }

  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}