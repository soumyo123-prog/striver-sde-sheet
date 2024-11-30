#include <bits/stdc++.h>
using namespace std;

void helper(int colNum, int n, vector<string> curr, vector<bool> rowSafe,
            vector<bool> leftDiagSafe, vector<bool> rightDiagSafe,
            vector<vector<string>> &res) {
  if (colNum == n) {
    res.push_back(curr);
    return;
  }

  for (int i = 0; i < n; i++) {
    bool safePos = rowSafe[i] && leftDiagSafe[i - colNum + n - 1] &&
                   rightDiagSafe[i + colNum];
    if (safePos) {
      rowSafe[i] = false;
      leftDiagSafe[i - colNum + n - 1] = false;
      rightDiagSafe[i + colNum] = false;
      curr[i][colNum] = 'Q';

      helper(colNum + 1, n, curr, rowSafe, leftDiagSafe, rightDiagSafe, res);

      rowSafe[i] = true;
      leftDiagSafe[i - colNum + n - 1] = true;
      rightDiagSafe[i + colNum] = true;
      curr[i][colNum] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<bool> rowSafe(n, true);
  vector<bool> leftDiagSafe(2 * n - 1, true);
  vector<bool> rightDiagSafe(2 * n - 1, true);

  vector<vector<string>> res;
  vector<string> curr(n, string(n, '.'));

  helper(0, n, curr, rowSafe, leftDiagSafe, rightDiagSafe, res);

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}