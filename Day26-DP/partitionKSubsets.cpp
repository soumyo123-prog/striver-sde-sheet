#include <bits/stdc++.h>
using namespace std;

bool f(int idx, vector<int>& nums, vector<int>& sums, int& numRemaining,
       int& sum) {
  if (idx == nums.size()) {
    return numRemaining == 0;
  }

  for (int i = 0; i < sums.size(); i++) {
    if (sums[i] == sum) continue;
    if (sums[i] + nums[idx] > sum) continue;

    sums[i] += nums[idx];

    if (sums[i] == sum) {
      numRemaining--;
    }

    if (f(idx + 1, nums, sums, numRemaining, sum)) {
      return true;
    }

    if (sums[i] == sum) {
      numRemaining++;
    }

    sums[i] -= nums[idx];
  }

  return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
  int n = nums.size();

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
  }

  if (sum % k != 0) return false;

  int t = sum / k;

  vector<int> dp((1 << n), -1);
  dp[0] = 0;

  for (int i = 0; i < (1 << n); i++) {
    if (dp[i] == -1) continue;

    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0 && (dp[i] + nums[j]) % t == 0) {
        dp[i | (1 << j)] = 0;
      }
    }
  }

  return dp[(1 << n) - 1] == 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}