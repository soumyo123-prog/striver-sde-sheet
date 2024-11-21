#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
  vector<int> sol;

  int c1 = 0, c2 = 0, e1 = INT_MIN, e2 = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    if (c1 == 0 && nums[i] != e2) {
      c1 = 1, e1 = nums[i];
    } else if (c2 == 0 && nums[i] != e1) {
      c2 = 1, e2 = nums[i];
    } else if (e1 == nums[i]) {
      c1++;
    } else if (e2 == nums[i]) {
      c2++;
    } else {
      c1--;
      c2--;
    }
  }

  if (c1 > 0 && 3 * count(nums.begin(), nums.end(), e1) > nums.size()) {
    sol.push_back(e1);
  }
  if (c2 > 0 && 3 * count(nums.begin(), nums.end(), e2) > nums.size()) {
    sol.push_back(e2);
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}