#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  if (m == 0) {
    int k = 0;
    for (int i = 0; i < n; i++) {
      nums1[k++] = nums2[i];
    }
    return;
  }

  if (n == 0) {
    return;
  }

  if (nums1[m - 1] <= nums2[0]) {
    int x = m, y = 0;
    while (y < n) {
      nums1[x++] = nums2[y++];
    }
    return;
  }

  int i = m - 1, j = n - 1, k = m + n - 1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] < nums2[j]) {
      nums1[k] = nums2[j];
      k--;
      j--;
    } else {
      nums1[k] = nums1[i];
      k--;
      i--;
    }
  }

  while (i >= 0) {
    nums1[k--] = nums1[i--];
  }

  while (j >= 0) {
    nums1[k--] = nums2[j--];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}