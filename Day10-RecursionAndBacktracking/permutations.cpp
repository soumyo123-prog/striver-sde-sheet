#include <bits/stdc++.h>
using namespace std;

void populate(int idx, vector<int> &nums, vector<int> perm,
              vector<vector<int>> &perms) {
  if (idx == nums.size()) {
    perms.push_back(perm);
    return;
  }

  for (int i = 0; i < perm.size(); i++) {
    if (perm[i] == -20) {
      perm[i] = nums[idx];
      populate(idx + 1, nums, perm, perms);
      perm[i] = -20;
    }
  }
}

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> perms;
  vector<int> perm(nums.size(), -20);

  populate(0, nums, perm, perms);

  return perms;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}