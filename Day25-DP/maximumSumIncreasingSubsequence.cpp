#include <bits/stdc++.h>
using namespace std;

int f(int idx, vector<int>& arr, int prev) {
  if (idx == arr.size()) {
    return 0;
  }

  if (arr[idx] <= prev) {
    return f(idx + 1, arr, prev);
  }

  return max(arr[idx] + f(idx + 1, arr, arr[idx]), f(idx + 1, arr, prev));
}

int maxSumIS(vector<int>& arr) {
  int n = arr.size();

  int dp[n];
  dp[n - 1] = arr[n - 1];

  int res = arr[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    dp[i] = arr[i];
    for (int j = i + 1; j < n; j++) {
      if (arr[i] < arr[j]) {
        dp[i] = max(dp[i], arr[i] + dp[j]);
      }
    }
    res = max(res, dp[i]);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}