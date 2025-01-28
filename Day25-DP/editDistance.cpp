#include <bits/stdc++.h>
using namespace std;

int n, m;

int f(int i1, int i2, string &word1, string &word2, vector<vector<int>> &dp) {
  if (i1 == n && i2 == m) {
    return 0;
  }

  if (dp[i1][i2] != -1) {
    return dp[i1][i2];
  }

  if (i1 == n) {
    return dp[n][i2] = 1 + f(i1, i2 + 1, word1, word2, dp);
  }

  if (i2 == m) {
    return dp[i1][m] = 1 + f(i1 + 1, i2, word1, word2, dp);
  }

  if (word1[i1] == word2[i2]) {
    return dp[i1][i2] = f(i1 + 1, i2 + 1, word1, word2, dp);
  }

  int a1 = 1 + f(i1 + 1, i2, word1, word2, dp);
  int a2 = 1 + f(i1, i2 + 1, word1, word2, dp);
  int a3 = 1 + f(i1 + 1, i2 + 1, word1, word2, dp);

  return dp[i1][i2] = min(a1, min(a2, a3));
}

int minDistance(string word1, string word2) {
  n = word1.size();
  m = word2.size();

  int dp[n + 1][m + 1];
  dp[n][m] = 0;
  for (int i = n - 1; i >= 0; i--) {
    dp[i][m] = i;
  }
  for (int i = m - 1; i >= 0; i--) {
    dp[n][i] = i;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (word1[i] == word2[j]) {
        dp[i][j] = dp[i + 1][j + 1];
      } else {
        dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1]));
      }
    }
  }

  return dp[0][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}