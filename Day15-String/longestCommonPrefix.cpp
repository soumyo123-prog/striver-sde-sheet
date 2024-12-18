#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  string ans = "";

  for (int i = 0; i < strs[0].size(); i++) {
    char c = strs[0][i];

    for (int j = 0; j < strs.size(); j++) {
      if (i >= strs[j].size()) {
        return ans;
      }
      if (strs[j][i] != c) {
        return ans;
      }
    }

    ans += c;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}