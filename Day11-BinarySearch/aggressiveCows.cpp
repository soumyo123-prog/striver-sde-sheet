#include <bits/stdc++.h>
using namespace std;

pair<bool, int> check(vector<int> &a, int n, int c, int dist) {
  int prev = a[0], req = c - 1, currDist = INT_MAX;

  for (int i = 1; i < n; i++) {
    if (a[i] - prev >= dist) {
      req--;
      currDist = min(currDist, a[i] - prev);
      prev = a[i];
      if (req == 0) {
        return {true, currDist};
      }
    }
  }

  return {false, 0};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    int s = 1, e = 1e9 + 1, ans = 0;
    while (s <= e) {
      int mid = (s + e) / 2;

      pair<bool, int> checkRes = check(a, n, c, mid);
      if (checkRes.first) {
        ans = checkRes.second;
        s = mid + 1;
      } else {
        e = mid - 1;
      }
    }

    cout << ans << endl;
  }

  return 0;
}