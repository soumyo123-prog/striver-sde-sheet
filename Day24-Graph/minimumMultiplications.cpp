#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000;

int minimumMultiplications(vector<int>& arr, int start, int end) {
  int n = arr.size();

  vector<int> distance(MOD + 1, INT_MAX);
  distance[start] = 0;

  queue<pair<int, int>> q;
  q.push({start, 0});

  while (!q.empty()) {
    int u = q.front().first, d = q.front().second;
    q.pop();

    for (int i = 0; i < n; i++) {
      int res = ((u % MOD) * (arr[i] % MOD)) % MOD;
      if (distance[res] > d + 1) {
        q.push({res, d + 1});
        distance[res] = d + 1;
      }
    }
  }

  if (distance[end] == INT_MAX) {
    return -1;
  }

  return distance[end];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}