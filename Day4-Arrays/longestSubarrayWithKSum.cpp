#include <bits/stdc++.h>
using namespace std;

int lenOfLongestSubarr(vector<int>& arr, int k) {
  int n = arr.size();

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  vector<long long> prefSum(n);
  unordered_map<long long, long long> mp;

  long long ps1 = 0, ps2 = 0;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    ps1 += arr[i];
    ps2 += arr[n - i - 1];

    prefSum[i] = ps1;
    if (mp.find(ps2) == mp.end()) {
      mp[ps2] = n - i - 1;
    }

    if (ps1 == k) {
      ans = max(ans, i + 1);
    }

    int j = n - i - 1;
    if (ps2 == k) {
      ans = max(ans, n - j);
    }
  }

  for (int i = 0; i < n; i++) {
    long long ps = prefSum[i], req = sum - k - ps;
    if (mp.find(req) != mp.end() && mp[req] > i) {
      ans = max(ans, (int)mp[req] - i - 1);
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