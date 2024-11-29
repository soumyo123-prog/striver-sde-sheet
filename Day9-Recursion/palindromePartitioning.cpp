#include <bits/stdc++.h>
using namespace std;

void helper(string &s, int i, vector<string> els, vector<vector<string>> &res,
            vector<vector<bool>> &isPal) {
  if (i == s.size()) {
    res.push_back(els);
    return;
  }

  string x = "";
  for (int j = i; j < s.size(); j++) {
    x += s[j];
    if (!isPal[i][j]) {
      continue;
    }
    els.push_back(x);
    helper(s, j + 1, els, res, isPal);
    els.pop_back();
  }
}

vector<vector<string>> partition(string s) {
  vector<string> els;
  vector<vector<string>> res;

  vector<vector<bool>> isPal(s.size(), vector<bool>(s.size(), false));

  for (int i = 0; i < s.size(); i++) {
    isPal[i][i] = true;

    int x = i - 1, y = i + 1;
    while (x >= 0 && y < s.size() && s[x] == s[y]) {
      isPal[x][y] = true;
      x--;
      y++;
    }

    x = i - 1, y = i;
    while (x >= 0 && y < s.size() && s[x] == s[y]) {
      isPal[x][y] = true;
      x--;
      y++;
    }
  }

  helper(s, 0, els, res, isPal);

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}