#include <bits/stdc++.h>
using namespace std;

int rc[] = {0, 1, 0, -1};
int cc[] = {1, 0, -1, 0};

int orangesRotting(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();

  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  queue<pair<int, int>> q;

  int fresh = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        vis[i][j] = 1;
        q.push({i, j});
      } else if (grid[i][j] == 1) {
        fresh++;
      }
    }
  }

  if (fresh == 0) {
    return 0;
  }

  int minutes = 0;

  while (!q.empty()) {
    int s = q.size();
    while (s > 0) {
      pair<int, int> node = q.front();
      q.pop();
      s--;

      for (int i = 0; i < 4; i++) {
        int x = node.first + rc[i], y = node.second + cc[i];
        if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] &&
            grid[x][y] == 1) {
          q.push({x, y});
          vis[x][y] = true;
          fresh--;
        }
      }
    }
    minutes++;
    if (fresh == 0) {
      return minutes;
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}