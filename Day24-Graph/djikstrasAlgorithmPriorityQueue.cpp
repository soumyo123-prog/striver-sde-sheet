#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
  int n = adj.size();

  vector<int> distance(n, INT_MAX);
  distance[src] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      minHeap;
  minHeap.push({0, src});

  while (!minHeap.empty()) {
    int d = minHeap.top().first, u = minHeap.top().second;
    minHeap.pop();

    for (auto i : adj[u]) {
      if (distance[i.first] > d + i.second) {
        distance[i.first] = d + i.second;
        minHeap.push({d + i.second, i.first});
      }
    }
  }

  return distance;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}