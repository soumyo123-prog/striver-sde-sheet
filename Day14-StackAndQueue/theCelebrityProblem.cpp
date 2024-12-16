#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& mat) {
  int n = mat.size();

  bool flag, f1;

  for (int i = 0; i < n; i++) {
    flag = true;

    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 1) {
        flag = false;
        break;
      }
    }

    if (flag) {
      f1 = true;
      for (int j = 0; j < n; j++) {
        if (j == i) {
          continue;
        }
        if (mat[j][i] == 0) {
          f1 = false;
          break;
        }
      }

      if (f1) {
        return i;
      }
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}