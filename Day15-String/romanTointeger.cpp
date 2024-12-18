#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
  unordered_map<char, int> mp;
  mp['I'] = 1;
  mp['V'] = 5;
  mp['X'] = 10;
  mp['L'] = 50;
  mp['C'] = 100;
  mp['D'] = 500;
  mp['M'] = 1000;

  int n = s.size(), ans = 0, i;

  for (i = n - 1; i > 0; i--) {
    if (mp[s[i]] <= mp[s[i - 1]]) {
      ans += mp[s[i]];
    } else {
      ans += mp[s[i]] - mp[s[i - 1]];
      i--;
    }
  }

  if (i == 0) {
    ans += mp[s[i]];
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}