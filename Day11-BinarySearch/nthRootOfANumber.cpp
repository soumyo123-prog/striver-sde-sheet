#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
  int s = 1, e = m;

  while (s <= e) {
    int mid = s + (e - s) / 2;

    long long res = 1;
    int cnt = 0;
    while (res < m && cnt < n) {
      res *= mid;
      cnt++;
    }

    if (res == m) {
      if (cnt == n) {
        return mid;
      } else if (cnt < n) {
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    } else if (res < m) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}