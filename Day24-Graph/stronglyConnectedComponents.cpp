#include <bits/stdc++.h>
using namespace std;

void topoUtil(int u, vector<bool> &vis, vector<vector<int>> &adj,
              stack<int> &st) {
  vis[u] = true;

  for (int i : adj[u]) {
    if (!vis[i]) {
      topoUtil(i, vis, adj, st);
    }
  }

  st.push(u);
}

int kosaraju(vector<vector<int>> &adj) {
  int n = adj.size();

  vector<bool> vis(n, false);

  stack<int> st, tmp;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      topoUtil(i, vis, adj, st);
    }
  }

  vector<vector<int>> graph(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      graph[adj[i][j]].push_back(i);
    }
  }

  vis = vector<bool>(n, false);

  int res = 0;

  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (!vis[u]) {
      res++;
      topoUtil(u, vis, graph, tmp);
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