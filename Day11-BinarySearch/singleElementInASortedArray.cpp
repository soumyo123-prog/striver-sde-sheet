#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
  int n = nums.size(), s = 0, e = n - 1;

  while (s <= e) {
    int mid = s + (e - s) / 2;

    if (mid > 0 && nums[mid - 1] == nums[mid] ||
        mid < n - 1 && nums[mid + 1] == nums[mid]) {
      int sidx = mid > 0 && nums[mid - 1] == nums[mid] ? mid - 1 : mid;
      if ((n - sidx) & 1) {
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    } else {
      return nums[mid];
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}