#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  int m = matrix.size(), n = matrix[0].size();

  bool f1 = false, f2 = false;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
        if (i == 0) {
          f1 = true;
        }
        if (j == 0) {
          f2 = true;
        }
      }
    }
  }

  for (int i = 1; i < m; i++) {
    if (matrix[i][0] == 0) {
      for (int j = 1; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int j = 1; j < n; j++) {
    if (matrix[0][j] == 0) {
      for (int i = 1; i < m; i++) {
        matrix[i][j] = 0;
      }
    }
  }

  if (f1) {
    for (int j = 0; j < n; j++) {
      matrix[0][j] = 0;
    }
  }

  if (f2) {
    for (int i = 0; i < m; i++) {
      matrix[i][0] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}