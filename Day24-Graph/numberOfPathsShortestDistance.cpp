#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
  int e = roads.size();

  vector<pair<int, int>> adj[n];
  for (int i = 0; i < e; i++) {
    int u = roads[i][0], v = roads[i][1], t = roads[i][2];
    adj[u].push_back({v, t});
    adj[v].push_back({u, t});
  }

  vector<int> dist(n, INT_MAX);
  dist[0] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 0});

  vector<int> counts(n, 0);
  counts[0] = 1;

  while (!pq.empty()) {
    pair<int, int> top = pq.top();
    pq.pop();

    int d = top.first, u = top.second;

    if (dist[u] < d) {
      continue;
    }

    for (auto i : adj[u]) {
      int v = i.first, wt = i.second;

      if (dist[v] > d + wt) {
        dist[v] = d + wt;
        counts[v] = counts[u];
        pq.push({d + wt, v});
      } else if (dist[v] == d + wt) {
        counts[v] += counts[u];
      }
    }
  }

  return counts[n - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}