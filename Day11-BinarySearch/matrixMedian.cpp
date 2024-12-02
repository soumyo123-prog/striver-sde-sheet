#include <bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &mat) {
  int n = mat.size(), m = mat[0].size();

  if (n == 1) {
    return mat[0][m / 2];
  }

  int s = INT_MAX, e = INT_MIN;
  for (int i = 0; i < n; i++) {
    s = min(s, mat[i][0]);
    e = max(e, mat[i][m - 1]);
  }

  while (s <= e) {
    int mid = s + (e - s) / 2;

    int left = 0;
    for (int i = 0; i < n; i++) {
      left += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
    }

    if (left <= n * m / 2) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }

  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> mat(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    }
  }

  cout << median(mat) << endl;

  return 0;
}