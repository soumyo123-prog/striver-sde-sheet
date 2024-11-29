#include <bits/stdc++.h>
using namespace std;

void csHelper(vector<int> &cand, int i, int sum, vector<int> els,
              vector<vector<int>> &combs) {
  if (sum == 0) {
    combs.push_back(els);
    return;
  }

  if (sum < 0 || i == cand.size()) {
    return;
  }

  if (sum >= cand[i]) {
    els.push_back(cand[i]);
    csHelper(cand, i, sum - cand[i], els, combs);
    els.pop_back();
  }
  csHelper(cand, i + 1, sum, els, combs);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<int> els;
  vector<vector<int>> combs;

  csHelper(candidates, 0, target, els, combs);

  return combs;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}