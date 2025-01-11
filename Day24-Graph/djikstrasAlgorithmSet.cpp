#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
  int n = adj.size();

  vector<int> distance(n, INT_MAX);
  distance[src] = 0;

  set<pair<int, int>> st;
  st.insert({0, src});

  while (!st.empty()) {
    pair<int, int> begin = *st.begin();
    int d = begin.first, u = begin.second;
    st.erase(begin);

    for (auto i : adj[u]) {
      if (distance[i.first] > d + i.second) {
        if (distance[i.first] != INT_MAX) {
          st.erase({distance[i.first], i.first});
        }
        distance[i.first] = d + i.second;
        st.insert({d + i.second, i.first});
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