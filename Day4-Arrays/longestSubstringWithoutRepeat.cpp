#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
  int n = s.size();

  vector<int> curr(128, 0);
  int currLen = 0, maxLen = 0;

  int i = 0, j = 0;
  while (i < n && j < n) {
    if (curr[s[j]] == 0) {
      curr[s[j]]++;
      j++;
      currLen++;
      maxLen = max(maxLen, currLen);
    } else {
      while (curr[s[j]] == 1) {
        curr[s[i]]--;
        i++;
        currLen--;
      }
    }
  }

  maxLen = max(maxLen, currLen);

  return maxLen;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}