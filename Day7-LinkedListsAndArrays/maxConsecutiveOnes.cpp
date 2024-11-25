#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
  int i = 0, n = nums.size(), maxCount = 0, currCount = 0;
  while (i < n) {
    if (nums[i] == 0) {
      maxCount = max(maxCount, currCount);
      currCount = 0;
    } else {
      currCount++;
    }
    i++;
  }

  maxCount = max(maxCount, currCount);
  return maxCount;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}