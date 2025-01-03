#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<bool> &vis, vector<bool> &dfsVis,
         vector<vector<int>> &adj) {
  vis[u] = true;
  dfsVis[u] = true;

  for (int i : adj[u]) {
    if (!vis[i]) {
      if (dfs(i, vis, dfsVis, adj)) {
        return true;
      }
    } else if (dfsVis[i]) {
      return true;
    }
  }

  dfsVis[u] = false;

  return false;
}

bool isCyclic(int v, vector<vector<int>> adj) {
  vector<bool> vis(v, false);
  vector<bool> dfsVis(v, false);

  for (int i = 0; i < v; i++) {
    if (!vis[i]) {
      if (dfs(i, vis, dfsVis, adj)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}