#include <bits/stdc++.h>
using namespace std;

int f(int idx, int prev, int n, vector<int> &price) {
  if (idx == n) {
    return price[idx - prev - 1];
  }

  return max(f(idx + 1, idx, n, price) + price[idx - prev - 1],
             f(idx + 1, prev, n, price));
}

int cutRod(vector<int> &price, int n) {
  int dp[n + 1];
  dp[n] = 0;
  dp[n - 1] = price[0];

  for (int i = n - 2; i >= 0; i--) {
    dp[i] = price[n - i - 1];
    for (int j = i + 1; j < n; j++) {
      dp[i] = max(dp[i], price[j - i - 1] + dp[j]);
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