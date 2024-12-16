#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  int n = nums.size();

  if (k == 1) {
    return nums;
  }

  vector<int> sol;

  deque<pair<int, int>> dq;
  dq.push_back({nums[0], 0});
  for (int i = 1; i < k; i++) {
    while (!dq.empty() && dq.back().first <= nums[i]) {
      dq.pop_back();
    }
    dq.push_back({nums[i], i});
  }

  sol.push_back(dq.front().first);

  for (int i = k; i < n; i++) {
    while (!dq.empty() && i - dq.front().second + 1 > k) {
      dq.pop_front();
    }
    while (!dq.empty() && dq.back().first <= nums[i]) {
      dq.pop_back();
    }
    dq.push_back({nums[i], i});
    sol.push_back(dq.front().first);
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}