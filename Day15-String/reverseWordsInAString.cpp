#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
  stack<string> q;

  string str = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != ' ') {
      str.push_back(s[i]);
    } else if (str.size() > 0) {
      q.push(str);
      str = "";
    }
  }

  if (str.size() > 0) {
    q.push(str);
  }

  string res = "";
  while (!q.empty()) {
    res += q.top() + " ";
    // cout << res.size() << ' ' << q.top().size() << endl;
    q.pop();
  }
  if (res.size() > 0) {
    res.pop_back();
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}