#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
  long long n1 = abs(n);

  double ans = 1;
  while (n1 > 0) {
    if (n1 & 1 != 0) {
      ans = ans * x;
      n1--;
    }
    x = x * x;
    n1 /= 2;
  }

  if (n < 0) {
    return 1 / ans;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}