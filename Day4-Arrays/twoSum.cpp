#include <bits/stdc++.h>
using namespace std;

int getIdx(vector<pair<int, int>>& a, int s, int e, int key) {
  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (a[mid].first == key) {
      return mid;
    } else if (a[mid].first < key) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }
  return a.size();
}

vector<int> twoSum(vector<int>& nums, int target) {
  int n = nums.size();

  vector<pair<int, int>> nn;
  for (int i = 0; i < n; i++) {
    nn.push_back({nums[i], i});
  }
  sort(nn.begin(), nn.end());

  vector<int> ans;

  for (int i = 0; i < n - 1; i++) {
    int req = target - nn[i].first;
    int idx = getIdx(nn, i + 1, n - 1, req);
    if (idx < n && nn[idx].first == req) {
      ans = {nn[i].second, nn[idx].second};
      break;
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