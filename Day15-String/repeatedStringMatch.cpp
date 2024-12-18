#include <bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b) {
  if (a == b) {
    return 1;
  }

  int numReps = 1;
  while (a.size() < b.size()) {
    a += a;
    numReps++;
  }

  if (a.find(b) != string::npos) {
    return numReps;
  }

  a += a;
  numReps++;

  if (a.find(b) != string::npos) {
    return numReps;
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}