#include <bits/stdc++.h>
using namespace std;

void helper(vector<int>& cands, int i, int t, vector<int> els,
            vector<vector<int>>& res) {
  if (t == 0) {
    res.push_back(els);
    return;
  }

  if (t < 0 || i == cands.size()) {
    return;
  }

  for (int j = i; j < cands.size(); j++) {
    if (j > i && cands[j] == cands[j - 1]) continue;
    if (cands[j] > t) break;
    els.push_back(cands[j]);
    helper(cands, j + 1, t - cands[j], els, res);
    els.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());

  vector<int> els;
  vector<vector<int>> res;

  helper(candidates, 0, target, els, res);

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}