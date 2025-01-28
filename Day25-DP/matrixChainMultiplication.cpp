#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr) {
  int n = arr.size();

  int dp[n][n];

  for (int i = 1; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int i = 1; i < n - 1; i++) {
    dp[i][i + 1] = arr[i - 1] * arr[i] * arr[i + 1];
  }

  for (int len = 3; len < n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
      dp[i][i + len - 1] = INT_MAX;
      for (int j = i; j < i + len - 1; j++) {
        int ops = dp[i][j] + dp[j + 1][i + len - 1] +
                  arr[i - 1] * arr[j] * arr[i + len - 1];
        if (ops < dp[i][i + len - 1]) {
          dp[i][i + len - 1] = ops;
        }
      }
    }
  }

  return dp[1][n - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}