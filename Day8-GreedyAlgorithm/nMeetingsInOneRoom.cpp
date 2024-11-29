#include <bits/stdc++.h>
using namespace std;

int ub(vector<pair<int, int>>& vp, int start, int end, int key) {
  int ans = vp.size();
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (vp[mid].first > key) {
      ans = mid;
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
  int n = start.size();

  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    vp.push_back({start[i], end[i]});
  }
  sort(vp.begin(), vp.end());

  vector<int> res(n + 1, 0);
  res[n - 1] = 1;

  for (int i = n - 2; i >= 0; i--) {
    int ep = vp[i].second, idx = ub(vp, i + 1, n - 1, ep);
    res[i] = max(res[i + 1], 1 + res[idx]);
  }

  return res[0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}