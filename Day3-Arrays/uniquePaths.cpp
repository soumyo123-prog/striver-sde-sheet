#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
  long long dp[m][n];
  dp[m - 1][n - 1] = 1;

  for (int i = n - 2; i >= 0; i--) {
    dp[m - 1][i] = 1;
  }
  for (int i = m - 2; i >= 0; i--) {
    dp[i][n - 1] = 1;
  }

  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    }
  }

  return (int)dp[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}