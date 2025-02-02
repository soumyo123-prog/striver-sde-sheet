#include <bits/stdc++.h>
using namespace std;

int f(int idx, vector<int>& coins, int rem, vector<vector<int>>& dp) {
  if (rem == 0) {
    return 0;
  }

  if (idx == coins.size()) {
    return -1;
  }

  if (dp[idx][rem] != -2) {
    return dp[idx][rem];
  }

  if (coins[idx] > rem) {
    return dp[idx][rem] = f(idx + 1, coins, rem, dp);
  }

  int a1 = f(idx, coins, rem - coins[idx], dp);
  if (a1 == -1) {
    a1 = INT_MAX;
  } else {
    a1++;
  }

  int a2 = f(idx + 1, coins, rem, dp);
  if (a2 == -1) {
    a2 = INT_MAX;
  }

  return dp[idx][rem] = (min(a1, a2) == INT_MAX ? -1 : min(a1, a2));
}

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();

  vector<int> dp(amount + 1);

  dp[0] = 0;

  for (int j = 1; j <= amount; j++) {
    if (j % coins[n - 1] == 0) {
      dp[j] = j / coins[n - 1];
    } else {
      dp[j] = INT_MAX;
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = 1; j <= amount; j++) {
      if (j >= coins[i] && dp[j - coins[i]] < INT_MAX) {
        dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
      }
    }
  }

  return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}