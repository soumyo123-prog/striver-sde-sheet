#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;

  for (int i = 0; i < k; i++) {
    pq.push({kArrays[i][0], {i, 0}});
  }

  vector<int> sol;
  while (!pq.empty()) {
    pair<int, pair<int, int>> curr = pq.top();
    pq.pop();

    sol.push_back(curr.first);

    if (curr.second.second + 1 < kArrays[curr.second.first].size()) {
      pq.push({kArrays[curr.second.first][curr.second.second + 1],
               {curr.second.first, curr.second.second + 1}});
    }
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;

    vector<vector<int>> kArrays;
    for (int i = 0; i < k; i++) {
      int n;
      cin >> n;
      vector<int> arr(n);
      for (int j = 0; j < n; j++) {
        cin >> arr[j];
      }
      kArrays.push_back(arr);
    }

    vector<int> sol = mergeKSortedArrays(kArrays, k);
    for (int i : sol) cout << i << ' ';
    cout << endl;
  }

  return 0;
}