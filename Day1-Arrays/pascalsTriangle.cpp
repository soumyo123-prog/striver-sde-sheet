#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> soln(numRows, vector<int>(numRows, 0));

  soln[0][0] = 1;

  for (int i = 2; i <= numRows; i++) {
    soln[i - 1][0] = 1;
    for (int j = 2; j <= i; j++) {
      soln[i - 1][j - 1] = soln[i - 2][j - 1] + soln[i - 2][j - 2];
    }
  }

  for (int i = 0; i < numRows; i++) {
    for (int j = numRows - 1; j >= 0; j--) {
      if (soln[i][j] == 0) {
        soln[i].pop_back();
      }
    }
  }

  return soln;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}