#include <bits/stdc++.h>
using namespace std;

int rc[4] = {-1, 0, 1, 0};
int cc[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int n, int m) {
  return x < n && y < m && x >= 0 && y >= 0;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                 pair<int, int> destination) {
  vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

  queue<vector<int>> q;
  q.push({source.first, source.second, 0});

  while (!q.empty()) {
    vector<int> vec = q.front();
    q.pop();

    int x = vec[0], y = vec[1], d = vec[2];

    if (x == destination.first && y == destination.second) {
      return d;
    }

    for (int i = 0; i < 4; i++) {
      int row = x + rc[i], col = y + cc[i];
      if (isValid(row, col, grid.size(), grid[0].size()) && !vis[row][col] &&
          grid[row][col] == 1) {
        vis[row][col] = true;
        q.push({row, col, d + 1});
      }
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