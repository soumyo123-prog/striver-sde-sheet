#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;

void shortestDistance(vector<vector<int>>& mat) {
  int n = mat.size();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == -1) {
        mat[i][j] = INF;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == INF) {
        mat[i][j] = -1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}