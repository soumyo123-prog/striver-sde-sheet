#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj) {
  int n = adj.size();

  vector<int> ind(n, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      ind[adj[i][j]]++;
    }
  }

  vector<int> topo;
  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (ind[i] == 0) {
      topo.push_back(i);
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i : adj[u]) {
      ind[i]--;
      if (ind[i] == 0) {
        q.push(i);
        topo.push_back(i);
      }
    }
  }

  return topo;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}