#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &res) {
  vis[u] = true;
  res.push_back(u);

  for (int i = 0; i < adj[u].size(); i++) {
    if (!vis[adj[u][i]]) {
      dfs(adj[u][i], vis, adj, res);
    }
  }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj) {
  vector<int> res;

  vector<bool> vis(adj.size(), false);
  stack<int> s;

  for (int i = 0; i < adj.size(); i++) {
    if (vis[i]) {
      continue;
    }

    s.push(i);

    while (!s.empty()) {
      int u = s.top();
      s.pop();

      if (!vis[u]) {
        res.push_back(u);
        vis[u] = true;
      }

      for (int j = adj[u].size() - 1; j >= 0; j--) {
        if (!vis[adj[u][j]]) {
          s.push(adj[u][j]);
        }
      }
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}