
#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
  int n = nums.size();

  int maxPos = 0;
  int minNeg = 0;

  int res = INT_MIN;
  int maxNum = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (nums[i] > 0) {
      if (maxPos == 0) {
        maxPos = nums[i];
      } else {
        maxPos *= nums[i];
      }

      if (minNeg != 0) {
        minNeg *= nums[i];
      }
    } else if (nums[i] < 0) {
      int oldMaxPos = maxPos;
      maxPos = minNeg * nums[i];
      if (oldMaxPos > 0) {
        minNeg = oldMaxPos * nums[i];
      } else {
        minNeg = nums[i];
      }
    } else {
      maxPos = 0;
      minNeg = 0;
    }

    maxNum = max(maxNum, nums[i]);
    res = max(res, maxPos);
  }

  if (maxNum < 0 && n == 1) {
    return maxNum;
  }

  return max(res, maxNum);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}