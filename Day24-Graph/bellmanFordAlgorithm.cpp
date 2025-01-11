#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
  vector<int> dist(v, INF);
  dist[src] = 0;

  for (int i = 0; i < v - 1; i++) {
    for (auto j : edges) {
      int u = j[0], v = j[1], wt = j[2];
      if (dist[u] != INF && dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
    if (dist[u] != INF && dist[v] > dist[u] + wt) {
      return {-1};
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