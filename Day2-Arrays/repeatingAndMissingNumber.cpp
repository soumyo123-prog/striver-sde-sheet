#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &a) {
  int n = a.size();

  long long t1, s1 = 0, t2, s2 = 0;

  t1 = (1LL * n * 1LL * (n + 1)) / 2;
  t2 = (1LL * n * 1LL * (n + 1) * 1LL * (2 * n + 1)) / 6;

  for (int i = 0; i < n; i++) {
    s1 += a[i];
    s2 += 1LL * a[i] * a[i];
  }

  long long x = t1 - s1, y = t2 - s2;

  long long B = ((x * x + y) / x) / 2;
  long long A = B - x;

  return {(int)A, (int)B};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}