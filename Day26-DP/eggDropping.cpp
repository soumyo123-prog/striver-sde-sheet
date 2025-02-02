#include <bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k) {
  vector<int> prev(k + 1);
  vector<int> curr(k + 1, INT_MAX);

  for (int i = 0; i <= k; i++) {
    prev[i] = i;
  }

  for (int numEggs = 2; numEggs <= n; numEggs++) {
    curr[0] = 0;
    for (int numFloor = 1; numFloor <= k; numFloor++) {
      for (int i = 1; i <= numFloor; i++) {
        curr[numFloor] =
            min(curr[numFloor], 1 + max(prev[i - 1], curr[numFloor - i]));
      }
    }
    prev = curr;
    curr = vector<int>(k + 1, INT_MAX);
  }

  return curr[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}