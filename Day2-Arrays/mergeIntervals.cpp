#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& a) {
  int n = a.size();

  sort(a.begin(), a.end());

  vector<vector<int>> soln;

  soln.push_back(a[0]);

  for (int i = 1; i < n; i++) {
    if (a[i][0] > (*soln.rbegin())[1]) {
      soln.push_back(a[i]);
    } else if (a[i][1] > (*soln.rbegin())[1]) {
      soln[soln.size() - 1][1] = a[i][1];
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