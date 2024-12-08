#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  int m = nums1.size(), n = nums2.size();

  unordered_map<int, int> mp;
  vector<int> nge(n, -1);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    mp[nums2[i]] = i;

    while (!st.empty() && nums2[i] > nums2[st.top()]) {
      nge[st.top()] = i;
      st.pop();
    }

    st.push(i);
  }

  for (int i = 0; i < m; i++) {
    if (nge[mp[nums1[i]]] == -1) {
      nums1[i] = -1;
    } else {
      nums1[i] = nums2[nge[mp[nums1[i]]]];
    }
  }

  return nums1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}