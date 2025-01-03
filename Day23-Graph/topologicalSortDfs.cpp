#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& topo, vector<int>& ind) {
  for (int i : adj[u]) {
    ind[i]--;
    if (ind[i] == 0) {
      topo.push_back(i);
      dfs(i, adj, topo, ind);
    }
  }
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
  int n = adj.size();

  vector<int> ind(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      ind[adj[i][j]]++;
    }
  }

  vector<int> topo, dfsVec;
  for (int i = 0; i < n; i++) {
    if (ind[i] == 0) {
      topo.push_back(i);
      dfsVec.push_back(i);
    }
  }

  for (int i : dfsVec) {
    dfs(i, adj, topo, ind);
  }

  return topo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}