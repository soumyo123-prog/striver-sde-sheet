#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  return a.first * b.second > b.first * a.second;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
  int n = val.size();

  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = {val[i], wt[i]};
  }
  sort(arr.begin(), arr.end(), compare);

  double maxVal = 0;

  for (int i = 0; i < n; i++) {
    if (capacity == 0) {
      break;
    }

    int v = arr[i].first, w = arr[i].second;
    if (capacity >= w) {
      maxVal += v;
      capacity -= w;
    } else {
      double unitValue = (double)v / (double)w;
      maxVal += unitValue * capacity;
      capacity = 0;
    }
  }

  return maxVal;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}