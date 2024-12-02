#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if (nums2.size() < nums1.size()) {
    swap(nums1, nums2);
  }

  int m = nums1.size(), n = nums2.size();

  int s = 0, e = min(m, (m + n) / 2);
  while (s <= e) {
    int mid = s + (e - s) / 2;

    int l1 = mid - 1 >= 0 ? nums1[mid - 1] : INT_MIN;
    int l2 =
        (m + n) / 2 - mid - 1 >= 0 ? nums2[(m + n) / 2 - mid - 1] : INT_MIN;
    int r1 = mid < m ? nums1[mid] : INT_MAX;
    int r2 = (m + n) / 2 - mid < n ? nums2[(m + n) / 2 - mid] : INT_MAX;

    if (max(l1, l2) <= min(r1, r2)) {
      double ans = (double)(max(l1, l2) + min(r1, r2)) / 2;
      if ((m + n) & 1) {
        ans = min(r1, r2);
      }
      return ans;
    } else if (l1 > r2) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}