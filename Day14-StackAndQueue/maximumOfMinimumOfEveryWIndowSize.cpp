#include <bits/stdc++.h>
using namespace std;

/**
 * Observations:
 *
 * max of min of size 1 = max element
 * max of min of size n = min element
 *
 * rest nums: in between max and min element
 *
 * 1st thinking:
 * max element (first element will always be the max) a0
 * a0 (if there is atleast 1 window of size 2 where the min is a0) otherwise
 */

vector<int> nse(vector<int> &a, int n) {
  vector<int> sol(n, n);

  stack<int> st;
  st.push(0);

  for (int i = 1; i < n; i++) {
    while (!st.empty() && a[st.top()] > a[i]) {
      sol[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  return sol;
}

vector<int> pse(vector<int> &a, int n) {
  vector<int> sol(n, -1);

  stack<int> st;
  st.push(n - 1);

  for (int i = n - 2; i >= 0; i--) {
    while (!st.empty() && a[st.top()] > a[i]) {
      sol[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  return sol;
}

vector<int> maxMinWindow(vector<int> a, int n) {
  vector<int> ns = nse(a, n), ps = pse(a, n);

  int maxIdx = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[maxIdx]) {
      maxIdx = i;
    }
  }

  vector<int> sol(n, INT_MIN);

  for (int i = 0; i < n; i++) {
    sol[ns[i] - ps[i] - 2] = max(sol[ns[i] - ps[i] - 2], a[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    sol[i] = max(sol[i], sol[i + 1]);
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> a1 = maxMinWindow({1, 2, 3, 4}, 4);
  vector<int> a2 = maxMinWindow({45, -2, 42, 5, -11}, 5);
  vector<int> a3 = maxMinWindow({-2, 12, -1, 1, 20, 1}, 6);

  return 0;
}