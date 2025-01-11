#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int v, int e, vector<vector<int>>& edges) {
  vector<pair<int, int>> adj[v];

  for (int i = 0; i < e; i++) {
    int x = edges[i][0], y = edges[i][1], wt = edges[i][2];
    adj[x].push_back({y, wt});
  }

  vector<int> dist(v, INT_MAX);

  queue<pair<int, int>> q;
  q.push({0, 0});

  while (!q.empty()) {
    int u = q.front().first, dst = q.front().second;
    q.pop();

    if (dst < dist[u]) {
      dist[u] = dst;
    }

    for (auto i : adj[u]) {
      if (dst + i.second < dist[i.first]) {
        q.push({i.first, dst + i.second});
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (dist[i] == INT_MAX) {
      dist[i] = -1;
    }
  }

  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}