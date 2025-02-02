#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();

  int dp[n][m];

  dp[0][0] = grid[0][0];

  for (int i = 1; i < m; i++) {
    dp[0][i] = grid[0][i] + dp[0][i - 1];
  }

  for (int i = 1; i < n; i++) {
    dp[i][0] = grid[i][0] + dp[i - 1][0];
    for (int j = 1; j < m; j++) {
      dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
    }
  }

  return dp[n - 1][m - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}