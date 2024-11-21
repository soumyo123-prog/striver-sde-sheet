#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
  int n = nums.size();

  unordered_set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(nums[i]);
  }

  int ans = 0;

  for (auto i = st.begin(); i != st.end(); ++i) {
    int cn = *i;
    if (st.find(cn - 1) == st.end()) {
      int len = 1;
      cn++;
      while (st.find(cn) != st.end()) {
        cn++;
        len++;
      }
      ans = max(ans, len);
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}