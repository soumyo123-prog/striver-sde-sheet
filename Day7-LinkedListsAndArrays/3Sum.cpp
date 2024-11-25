#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  vector<vector<int>> ans;

  int i = 0, n = nums.size();
  while (i < n) {
    int j = i + 1, k = n - 1;
    while (j < n && k > j) {
      int sum = nums[i] + nums[j] + nums[k];
      while (k > j && sum > 0) {
        sum -= nums[k];
        k--;
        sum += nums[k];
      }
      if (k > j && sum == 0) {
        ans.push_back({nums[i], nums[j], nums[k]});
      }
      j++;
      while (j < n && nums[j] == nums[j - 1]) {
        j++;
      }
    }
    i++;
    while (i < n && nums[i] == nums[i - 1]) {
      i++;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}