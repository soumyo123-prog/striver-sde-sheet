#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    int num = abs(nums[i]);
    if (nums[num] < 0) {
      return num;
    }
    nums[num] = -nums[num];
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}