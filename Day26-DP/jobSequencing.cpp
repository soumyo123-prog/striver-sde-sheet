#include <bits/stdc++.h>
using namespace std;

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                          vector<int> &profit) {
  int n = id.size();

  vector<pair<int, int>> pd(n);
  for (int i = 0; i < n; i++) {
    pd[i] = {profit[i], deadline[i]};
  }

  sort(pd.begin(), pd.end(), greater<pair<int, int>>());

  vector<int> res = {0, 0};

  set<int> times;
  for (int i = 1; i <= n; i++) {
    times.insert(i);
  }

  for (int i = 0; i < n; i++) {
    if (times.empty()) {
      break;
    }

    int p = pd[i].first;
    int d = pd[i].second;

    auto itr = times.upper_bound(d);

    if (itr == times.begin()) {
      continue;
    }

    res[0]++;
    res[1] += p;

    times.erase(prev(itr));
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}