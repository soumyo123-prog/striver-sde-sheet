#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
  int p, q, r, s, n = matrix.size();

  for (int i = 0; i < n / 2; i++) {
    for (int j = i; j < n - i - 1; j++) {
      p = matrix[i][j], q = matrix[j][n - i - 1],
      r = matrix[n - i - 1][n - j - 1], s = matrix[n - j - 1][i];
      matrix[i][j] = s;
      matrix[j][n - i - 1] = p;
      matrix[n - i - 1][n - j - 1] = q;
      matrix[n - j - 1][i] = r;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}