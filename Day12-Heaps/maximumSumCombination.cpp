#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a, vector<int> &b, int c) {
  int n = a.size();

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  priority_queue<pair<int, pair<int, int>>> pq;
  set<pair<int, int>> st;

  pq.push({a[n - 1] + b[n - 1], {n - 1, n - 1}});
  st.insert({n - 1, n - 1});

  vector<int> sol;

  int tmp = c;
  while (tmp > 0) {
    int i = pq.top().second.first;
    int j = pq.top().second.second;
    sol.push_back(pq.top().first);
    pq.pop();

    if (i - 1 >= 0 && st.find({i - 1, j}) == st.end()) {
      pq.push({a[i - 1] + b[j], {i - 1, j}});
      st.insert({i - 1, j});
    }

    if (j - 1 >= 0 && st.find({i, j - 1}) == st.end()) {
      pq.push({a[i] + b[j - 1], {i, j - 1}});
      st.insert({i, j - 1});
    }

    tmp--;
  }

  while (!pq.empty() && sol.size() < c) {
    sol.push_back(pq.top().first);
    pq.pop();
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}