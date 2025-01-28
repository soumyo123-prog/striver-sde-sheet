#include <bits/stdc++.h>
using namespace std;

int f(int idx1, int idx2, string text1, string text2, vector<vector<int>> &dp) {
  if (idx1 == text1.size() || idx2 == text2.size()) {
    return 0;
  }

  if (dp[idx1][idx2] != -1) {
    return dp[idx1][idx2];
  }

  if (text1[idx1] == text2[idx2]) {
    return dp[idx1][idx2] = 1 + f(idx1 + 1, idx2 + 1, text1, text2, dp);
  }

  return dp[idx1][idx2] = max(f(idx1 + 1, idx2, text1, text2, dp),
                              f(idx1, idx2 + 1, text1, text2, dp));
}

int longestCommonSubsequence(string s1, string s2) {
  int n = s1.size();
  int m = s2.size();

  int dp[2][m + 1];

  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
    dp[1][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[1][j] = 1 + dp[0][j - 1];
      } else {
        dp[1][j] = max(dp[0][j], dp[1][j - 1]);
      }
    }

    for (int j = 1; j <= m; j++) {
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }

  return dp[0][m];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}