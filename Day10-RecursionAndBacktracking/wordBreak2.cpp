#include <bits/stdc++.h>
using namespace std;

void helper(int i, string &s, string sent, vector<string> &sents,
            unordered_set<string> &dict) {
  if (i == s.size()) {
    sents.push_back(sent.substr(1));
    return;
  }

  string str = "";
  for (int j = i; j < s.size(); j++) {
    str += s[j];
    if (dict.find(str) != dict.end()) {
      sent += " " + str;
      helper(j + 1, s, sent, sents, dict);
      sent = sent.substr(0, sent.size() - str.size() - 1);
    }
  }
}

vector<string> wordBreak(string &s, vector<string> &dict) {
  unordered_set<string> dictSet;
  for (string str : dict) {
    dictSet.insert(str);
  }

  string sent = "";
  vector<string> sents;

  helper(0, s, sent, sents, dictSet);

  return sents;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}