#include <bits/stdc++.h>
using namespace std;

int get_max(vector<int>& a) {
  int maxNum = a[0];
  for (int i = 1; i < a.size(); i++) {
    maxNum = max(maxNum, a[i]);
  }
  return maxNum;
}

int maxSubArray(vector<int>& nums) {
  int maxNum = get_max(nums);
  if (maxNum < 0) {
    return maxNum;
  }

  int n = nums.size(), l = 0, r = 0, sum = 0, maxSum = 0;

  for (int i = 0; i < n; i++) {
    sum += nums[i];
    maxSum = max(maxSum, sum);
    if (sum < 0) {
      sum = 0;
    }
  }

  return maxSum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}