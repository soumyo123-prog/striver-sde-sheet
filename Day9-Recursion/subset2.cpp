#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &nums, vector<int> currSubset,
       vector<vector<int>> &allSubsets, int i) {
  if (i == nums.size()) {
    allSubsets.push_back(currSubset);
    return;
  }

  currSubset.push_back(nums[i]);
  f(nums, currSubset, allSubsets, i + 1);

  currSubset.pop_back();

  i++;
  while (i < nums.size() && nums[i] == nums[i - 1]) {
    i++;
  }

  f(nums, currSubset, allSubsets, i);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  vector<vector<int>> allSubsets;
  vector<int> currSubset;

  f(nums, currSubset, allSubsets, 0);

  return allSubsets;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}