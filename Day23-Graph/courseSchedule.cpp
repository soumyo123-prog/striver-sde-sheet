#include <bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>>& edges) {
  vector<int> adj[n];
  vector<int> ind(n, 0);

  for (int i = 0; i < edges.size(); i++) {
    ind[edges[i][0]]++;
    adj[edges[i][1]].push_back(edges[i][0]);
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
        topo.push_back(i);
        q.push(i);
      }
    }
  }

  return topo.size() == n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}