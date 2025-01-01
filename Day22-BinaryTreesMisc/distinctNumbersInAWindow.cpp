#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &a, int b) {
  int n = a.size();

  vector<int> res;
  if (b > n) {
    return res;
  }

  unordered_map<int, int> mp;

  int dis = 0;
  for (int i = 0; i < b; i++) {
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]] = 1;
      dis++;
    } else {
      mp[a[i]]++;
    }
  }

  res.push_back(dis);

  int x = 0, y = b - 1;
  while (y < n) {
    y++;

    if (y >= n) {
      break;
    }

    if (mp.find(a[y]) == mp.end()) {
      dis++;
      mp[a[y]] = 1;
    } else {
      mp[a[y]]++;
    }

    if (mp[a[x]] >= 2) {
      mp[a[x]]--;
    } else {
      dis--;
      mp.erase(a[x]);
    }
    x++;

    res.push_back(dis);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}