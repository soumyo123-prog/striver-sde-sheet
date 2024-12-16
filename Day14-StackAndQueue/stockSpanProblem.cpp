#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
 public:
  stack<pair<int, int>> st;
  int idx;

  StockSpanner() {
    st = stack<pair<int, int>>();
    st.push({INT_MAX, 0});
    idx = 0;
  }

  int next(int price) {
    idx++;
    while (!st.empty() && st.top().first <= price) {
      st.pop();
    }

    int ans = idx - st.top().second;
    st.push({price, idx});

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}