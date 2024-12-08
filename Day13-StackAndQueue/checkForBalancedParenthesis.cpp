#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  stack<char> st;
  st.push(s[0]);

  map<char, char> mp;
  mp[')'] = '(';
  mp['}'] = '{';
  mp[']'] = '[';

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
    } else {
      if (st.empty()) return false;
      if (st.top() != mp[s[i]]) return false;
      st.pop();
    }
  }

  if (!st.empty()) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}