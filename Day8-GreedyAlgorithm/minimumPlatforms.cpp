#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
  int n = arr.size();

  vector<pair<int, char>> vp;

  for (int i = 0; i < n; i++) {
    vp.push_back({arr[i], 'a'});
  }
  for (int i = 0; i < n; i++) {
    vp.push_back({dep[i], 'd'});
  }

  sort(vp.begin(), vp.end());

  int totPlat = 0, emptyPlat = 0;

  for (int i = 0; i < 2 * n; i++) {
    if (vp[i].second == 'a') {
      if (emptyPlat > 0) {
        emptyPlat--;
      } else {
        totPlat++;
      }
    } else {
      emptyPlat++;
    }
  }

  return totPlat;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}