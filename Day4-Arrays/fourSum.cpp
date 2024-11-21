#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  int n = nums.size();
  sort(nums.begin(), nums.end());

  vector<vector<int>> ans;

  int i = 0, j, k, l;
  while (i < n) {
    j = i + 1;
    while (j < n) {
      k = j + 1, l = k + 1;
      while (k < n && l < n) {
        while (l < n &&
               1LL * nums[i] + 1LL * nums[j] + 1LL * nums[k] + 1LL * nums[l] <
                   target) {
          l++;
        }
        if (l < n &&
            1LL * nums[i] + 1LL * nums[j] + 1LL * nums[k] + 1LL * nums[l] ==
                target) {
          ans.push_back({nums[i], nums[j], nums[k], nums[l]});
        }
        k++;
        while (k < n && nums[k] == nums[k - 1]) {
          k++;
        }
        l = k + 1;
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