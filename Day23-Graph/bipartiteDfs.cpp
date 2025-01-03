#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<int>& col, int color) {
  if (color == -1) {
    col[u] = 0;
  } else {
    col[u] = !color;
  }

  for (int i : adj[u]) {
    if (col[i] == -1) {
      if (!dfs(i, adj, col, col[u])) {
        return false;
      }
    } else if (col[i] == col[u]) {
      return false;
    }
  }

  return true;
}

bool isBipartite(vector<vector<int>>& adj) {
  int n = adj.size();

  vector<int> col(n, -1);

  for (int i = 0; i < n; i++) {
    if (col[i] == -1) {
      if (!dfs(i, adj, col, -1)) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}