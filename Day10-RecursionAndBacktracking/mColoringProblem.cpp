#include <bits/stdc++.h>
using namespace std;

bool helper(int u, int v, int m, vector<vector<int>> &adj,
            vector<int> &colors) {
  if (u == v) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    bool valid = true;
    for (int j : adj[u]) {
      if (colors[j] == i) {
        valid = false;
        break;
      }
    }

    if (valid) {
      colors[u] = i;
      if (helper(u + 1, v, m, adj, colors)) {
        return true;
      }
      colors[u] = 0;
    }
  }

  return false;
}

bool graphColoring(int v, vector<pair<int, int>> &edges, int m) {
  vector<vector<int>> adj(v + 1);
  for (pair<int, int> edge : edges) {
    adj[edge.first].push_back(edge.second);
    adj[edge.second].push_back(edge.first);
  }

  vector<int> colors(v, 0);

  return helper(0, v, m, adj, colors);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}