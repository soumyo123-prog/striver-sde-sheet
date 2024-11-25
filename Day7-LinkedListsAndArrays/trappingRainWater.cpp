#include <bits/stdc++.h>
using namespace std;

vector<int> getLge(vector<int> &a) {
  int n = a.size();

  vector<int> lge(n, -1);

  int maxEl = a[0];

  for (int i = 1; i < n; i++) {
    lge[i] = maxEl;
    maxEl = max(maxEl, a[i]);
  }

  return lge;
}

vector<int> getRge(vector<int> &a) {
  int n = a.size();

  vector<int> rge(n, -1);

  int maxEl = a[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    rge[i] = maxEl;
    maxEl = max(maxEl, a[i]);
  }

  return rge;
}

int trap(vector<int> &height) {
  int n = height.size();

  vector<int> lge = getLge(height);
  vector<int> rge = getRge(height);

  int ans = 0;

  for (int i = 1; i < n - 1; i++) {
    int left = lge[i], right = rge[i];
    if (min(left, right) > height[i]) {
      ans += min(left, right) - height[i];
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