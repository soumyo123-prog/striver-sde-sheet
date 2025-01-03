#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int par) {
  vis[u] = true;

  for (int i : adj[u]) {
    if (!vis[i]) {
      if (dfs(i, adj, vis, u)) {
        return true;
      }
    } else if (par != i) {
      return true;
    }
  }

  return false;
}

bool isCycle(vector<vector<int>>& adj) {
  // vector<bool> vis(adj.size(), false);

  // for (int j = 0; j < adj.size(); j++) {
  //   if (!vis[j]) {
  //     vis[j] = true;
  //     queue<pair<int, int>> q;
  //     q.push({j, -1});

  //     while (!q.empty()) {
  //       int u = q.front().first, par = q.front().second;
  //       q.pop();

  //       for (int i : adj[u]) {
  //         if (!vis[i]) {
  //           vis[i] = true;
  //           q.push({i, u});
  //         } else if (par != i) {
  //           return true;
  //         }
  //       }
  //     }
  //   }
  // }

  // return false;

  vector<bool> vis(adj.size(), false);

  for (int i = 0; i < adj.size(); i++) {
    if (!vis[i]) {
      if (dfs(i, adj, vis, -1)) {
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