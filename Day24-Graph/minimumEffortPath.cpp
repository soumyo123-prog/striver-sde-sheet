#include <bits/stdc++.h>
using namespace std;

int n, m;
int rc[4] = {-1, 0, 1, 0};
int cc[4] = {0, 1, 0, -1};

bool isValid(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }

int minimumEffortPath(vector<vector<int>>& heights) {
  n = heights.size();
  m = heights[0].size();

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      minHeap;
  minHeap.push({0, {0, 0}});

  vector<vector<int>> eff(n, vector<int>(m, INT_MAX));
  eff[0][0] = 0;

  while (!minHeap.empty()) {
    pair<int, pair<int, int>> top = minHeap.top();
    minHeap.pop();

    int d = top.first, x = top.second.first, y = top.second.second;

    if (d > eff[x][y]) {
      continue;
    }

    if (x == n - 1 && y == m - 1) {
      return d;
    }

    for (int i = 0; i < 4; i++) {
      int row = x + rc[i], col = y + cc[i];

      if (isValid(row, col)) {
        int wt = max(d, abs(heights[x][y] - heights[row][col]));

        if (wt < eff[row][col]) {
          eff[row][col] = wt;
          minHeap.push({wt, {row, col}});
        }
      }
    }
  }

  return eff[n - 1][m - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}