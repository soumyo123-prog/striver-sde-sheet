#include <bits/stdc++.h>
using namespace std;

pair<bool, int> check(vector<int> &a, int b, int maxPages) {
  int numStudents = 1, currSum = 0, sol = 0;
  for (int i = 0; i < a.size(); i++) {
    if (currSum + a[i] > maxPages) {
      numStudents++;
      sol = max(sol, currSum);
      currSum = a[i];
    } else {
      currSum += a[i];
    }
  }

  sol = max(sol, currSum);

  if (numStudents <= b) return {true, sol};
  return {false, 0};
}

int books(vector<int> &a, int b) {
  if (b > a.size()) {
    return -1;
  }

  int s = a[0], e = a[0];
  for (int i = 1; i < a.size(); i++) {
    s = min(s, a[i]);
    e += a[i];
  }

  int sol = e;

  while (s <= e) {
    int mid = s + (e - s) / 2;

    pair<bool, int> checkRes = check(a, b, mid);

    if (checkRes.first) {
      sol = checkRes.second;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}