#include <bits/stdc++.h>
using namespace std;

int palindromicPartition(string &s) {
  int n = s.size();

  bool isPal[n][n];
  for (int i = 0; i < n; i++) {
    isPal[i][i] = true;

    int x = i - 1;
    int y = i + 1;
    while (x >= 0 && y < n && s[x] == s[y]) {
      isPal[x][y] = true;
    }

    x = i - 1;
    y = i;
    while (x >= 0 && y < n && s[x] == s[y]) {
      isPal[x][y] = true;
    }
  }

  int dp[n];
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = n - i - 1;
  }

  for (int i = n - 2; i >= 0; i--) {
    dp[i] = 1 + dp[i + 1];
    for (int j = i + 2; j < n; j++) {
      if (isPal[i][j - 1]) {
        dp[i] = min(dp[i], 1 + dp[j]);
      }
    }
  }

  return dp[0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}