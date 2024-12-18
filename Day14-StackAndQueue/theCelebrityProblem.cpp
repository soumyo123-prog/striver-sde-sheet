#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat) {
  int n = mat.size();

  int x = 0, y = n - 1;
  while (y > x) {
    if (mat[x][y] == 0 && mat[y][x] == 0) {
      x++;
      y--;
      continue;
    }

    if (mat[x][y] == 1 && mat[y][x] == 1) {
      x++;
      y--;
      continue;
    }

    if (mat[x][y] == 1) {
      x++;
      continue;
    }

    y--;
  }

  if (x != y) {
    return -1;
  }

  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (mat[x][i] == 1) {
      flag = false;
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    if (i == x) {
      continue;
    }
    if (mat[i][x] == 0) {
      flag = false;
      break;
    }
  }

  if (flag) {
    return x;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> m1 = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
  cout << celebrity(m1) << endl;

  vector<vector<int>> m2 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << celebrity(m2) << endl;

  vector<vector<int>> m3 = {{0, 1}, {1, 0}};
  cout << celebrity(m3) << endl;

  return 0;
}