#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int>& a) {
  int n = a.size();

  vector<int> nse(n, -1);

  stack<int> st;
  st.push(n - 1);

  for (int i = n - 2; i >= 0; i--) {
    while (!st.empty() && a[st.top()] > a[i]) {
      a[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  return nse;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}