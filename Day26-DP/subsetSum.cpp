#include <bits/stdc++.h>
using namespace std;

bool f(int idx, vector<int>& nums, int remSum, vector<vector<int>>& dp) {
  if (remSum == 0) {
    return true;
  }

  if (idx == nums.size()) {
    return false;
  }

  if (nums[idx] > remSum) {
    return dp[idx][remSum] = f(idx + 1, nums, remSum, dp);
  }

  return dp[idx][remSum] = f(idx + 1, nums, remSum - nums[idx], dp) ||
                           f(idx + 1, nums, remSum, dp);
}

bool canPartition(vector<int>& nums) {
  int sum = 0;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    sum += nums[i];
  }

  if (sum % 2 != 0) return false;

  vector<bool> dp(sum / 2 + 1, false);
  dp[0] = true;

  for (int i = n - 1; i >= 0; i--) {
    for (int j = sum / 2; j >= nums[i]; j--) {
      dp[j] = dp[j] || dp[j - nums[i]];
    }
  }

  return dp[sum / 2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}