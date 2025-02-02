#include <bits/stdc++.h>
using namespace std;

bool f(string s, unordered_set<string> &wordDict, vector<int> &dp) {
  if (s.size() == 0) {
    return true;
  }

  if (dp[s.size()] != -1) {
    return dp[s.size()];
  }

  for (int i = 0; i < s.size(); i++) {
    if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
      if (f(s.substr(i + 1), wordDict, dp)) {
        return dp[s.size()] = true;
      }
    }
  }

  return dp[s.size()] = false;
}

bool wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> wd;
  for (string s : wordDict) {
    wd.insert(s);
  }

  int n = s.size();

  vector<bool> dp(n + 1, false);

  dp[n] = true;

  for (int i = n - 1; i >= 0; i--) {
    string str = "";
    for (int j = i; j < n; j++) {
      str.push_back(s[j]);
      if (wd.find(str) != wd.end() && (dp[j + 1] == true)) {
        dp[i] = dp[j + 1];
        break;
      }
    }
  }

  return dp[0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}