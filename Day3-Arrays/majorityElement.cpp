#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
  int el, cnt = 0, n = nums.size();

  for (int i = 0; i < n; i++) {
    if (cnt == 0) {
      el = nums[i];
      cnt++;
    } else {
      if (nums[i] == el) {
        cnt++;
      } else {
        cnt--;
      }
    }
  }

  if (cnt != 0) {
    return el;
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}