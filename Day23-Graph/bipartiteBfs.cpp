#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& adj) {
  int n = adj.size();

  vector<int> col(n, -1);
  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (col[i] == -1) {
      col[i] = 0;
      q.push(i);

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int j : adj[u]) {
          if (col[j] == -1) {
            col[j] = !col[u];
            q.push(j);
          } else if (col[j] == col[u]) {
            return false;
          }
        }
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