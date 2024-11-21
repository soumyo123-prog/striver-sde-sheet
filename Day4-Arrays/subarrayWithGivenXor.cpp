#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int b) {
  int n = a.size();

  unordered_map<int, int> mp;
  mp[0] = 1;

  int xr = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    xr ^= a[i];

    int key = xr ^ b;
    if (mp.find(key) != mp.end()) {
      ans += mp[key];
    }

    if (mp.find(xr) == mp.end()) {
      mp[xr] = 1;
    } else {
      mp[xr]++;
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