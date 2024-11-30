#include <bits/stdc++.h>
using namespace std;

vector<int> rc = {-1, 0, 1, 0};
vector<int> cc = {0, 1, 0, -1};
vector<char> pc = {'U', 'R', 'D', 'L'};

void helper(int row, int col, vector<vector<int>> &mat, string path,
            vector<string> &paths) {
  if (row == mat.size() - 1 && col == mat.size() - 1) {
    paths.push_back(path);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int x = row + rc[i], y = col + cc[i];
    if (x < mat.size() && y < mat.size() && mat[x][y] != 0) {
      mat[x][y] = 0;
      path.push_back(pc[i]);

      helper(x, y, mat, path, paths);

      path.pop_back();
      mat[x][y] = 1;
    }
  }
}

vector<string> findPath(vector<vector<int>> &mat) {
  mat[0][0] = 0;

  string path = "";
  vector<string> paths;

  helper(0, 0, mat, path, paths);

  return paths;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}