#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
  string str = "";

  for (int i = 0; i < s.size(); i++) {
    int x = i - 1, y = i + 1;
    while (x >= 0 && y < s.size() && s[x] == s[y]) {
      x--;
      y++;
    }
    x++;
    y--;
    if (y - x + 1 > str.size()) {
      str = s.substr(x, y - x + 1);
    }

    x = i - 1, y = i;
    while (x >= 0 && y < s.size() && s[x] == s[y]) {
      x--;
      y++;
    }
    x++;
    y--;
    if (y - x + 1 > str.size()) {
      str = s.substr(x, y - x + 1);
    }
  }

  return str;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}