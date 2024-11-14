#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
  int n = prices.size(), profit = 0, maxEl = prices[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    profit = max(profit, maxEl - prices[i]);
    maxEl = max(maxEl, prices[i]);
  }

  return profit;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}