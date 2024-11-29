#include <bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
  vector<int> facs(10, 1);
  for (int i = 2; i <= 9; i++) {
    facs[i] = i * facs[i - 1];
  }

  string perm(n, '0');

  if (k == facs[n]) {
    for (int i = n; i > 0; i--) {
      perm[n - (i - 1) - 1] = i + '0';
    }
    return perm;
  }

  set<int> nums;
  for (int i = 1; i <= n; i++) {
    nums.insert(i);
  }

  int rank = 0;
  for (int i = 0; i < n; i++) {
    int idx = 1, num = *nums.begin();
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      num = *it;
      if (rank + idx * facs[n - i - 1] > k) {
        break;
      }
      idx++;
    }
    rank += (idx - 1) * facs[n - i - 1];
    perm[i] = num + '0';
    nums.erase(num);
  }

  prev_permutation(perm.begin(), perm.end());

  return perm;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}