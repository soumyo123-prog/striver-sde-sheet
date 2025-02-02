#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<int>& cuts) {
  int m = cuts.size();

  sort(cuts.begin(), cuts.end());

  int dp[m + 2][m + 2];

  for (int i = 0; i <= m + 1; i++) {
    dp[i][i] = 0;
    if (i < m + 1) {
      dp[i][i + 1] = 0;
    }
  }

  for (int len = 2; len <= m + 1; len++) {
    for (int i = 0; i + len <= m + 1; i++) {
      dp[i][i + len] = INT_MAX;
      for (int j = i + 1; j < i + len; j++) {
        int leftLength = i == 0 ? cuts[j - 1] : cuts[j - 1] - cuts[i - 1];
        int rightLength = i + len == m + 1 ? n - cuts[j - 1]
                                           : cuts[i + len - 1] - cuts[j - 1];
        dp[i][i + len] = min(dp[i][i + len], dp[i][j] + dp[j][i + len] +
                                                 leftLength + rightLength);
      }
    }
  }

  return dp[0][m + 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}