#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int sum) {
  int n = coins.size();

  vector<int> dp(sum + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i <= sum; i++) {
    for (int j = 0; j < n; j++) {
      if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }

  int numCoins = dp[sum];
  if (numCoins == INT_MAX) return -1;
  return numCoins;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}