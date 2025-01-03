#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
  vector<bool> vis(adj.size(), false);
  vis[0] = true;

  queue<int> q;
  q.push(0);

  vector<int> res;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    res.push_back(u);

    for (int i : adj[u]) {
      if (!vis[i]) {
        vis[i] = true;
        q.push(i);
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