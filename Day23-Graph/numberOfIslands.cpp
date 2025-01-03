#include <bits/stdc++.h>
using namespace std;

bool vis[302][302];
int rc[4] = {-1, 0, 1, 0};
int cc[4] = {0, 1, 0, -1};
int n, m;

void dfs(int i, int j, vector<vector<char>>& grid) {
  vis[i][j] = true;

  for (int k = 0; k < 4; k++) {
    int x = i + rc[k], y = j + cc[k];
    if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && grid[x][y] == '1') {
      dfs(x, y, grid);
    }
  }
}

int numIslands(vector<vector<char>>& grid) {
  n = grid.size();
  m = grid[0].size();

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '1' && !vis[i][j]) {
        res++;
        dfs(i, j, grid);
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