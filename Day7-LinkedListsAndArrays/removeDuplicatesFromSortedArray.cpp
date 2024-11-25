#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  int n = nums.size();

  int i = 1, j = 1;
  while (i < n && j < n) {
    while (i < n && nums[i] == nums[i - 1]) {
      i++;
    }
    if (i < n && j < n) {
      nums[j] = nums[i];
      j++;
      i++;
    }
  }

  return j;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}
