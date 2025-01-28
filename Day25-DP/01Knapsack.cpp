#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  vector<int> dp(w + 1, 0);

  for (int i = 0; i < n; i++) {
    for (int j = w; j >= 1; j--) {
      if (j - weights[i] >= 0) {
        dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
      }
    }
  }

  return dp[w];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}