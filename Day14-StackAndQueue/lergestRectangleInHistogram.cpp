#include <bits/stdc++.h>
using namespace std;

vector<int> rightSmNum(vector<int>& a) {
  vector<int> sol(a.size(), a.size());

  stack<int> st;
  st.push(0);

  for (int i = 1; i < a.size(); i++) {
    while (!st.empty() && a[i] < a[st.top()]) {
      sol[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  return a;
}

vector<int> leftSmNum(vector<int>& a) {
  vector<int> sol(a.size(), -1);

  stack<int> st;
  st.push(a.size() - 1);

  for (int i = a.size() - 2; i >= 0; i--) {
    while (!st.empty() && a[i] < a[st.top()]) {
      sol[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }

  return a;
}

int largestRectangleArea(vector<int>& heights) {
  vector<int> left = leftSmNum(heights), right = rightSmNum(heights);

  int n = heights.size();

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int li = left[i], ri = left[i];
    ans = max(ans, heights[i] * (ri - li - 1));
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}