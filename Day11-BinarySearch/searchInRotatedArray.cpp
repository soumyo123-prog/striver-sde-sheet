#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
  int n = nums.size();

  bool rotated = nums[n - 1] < nums[0];
  int pivot = -1;

  int s, e;

  if (rotated) {
    s = 1, e = n - 1;
    while (s <= e) {
      int mid = s + (e - s) / 2;
      if (nums[mid] < nums[0]) {
        pivot = mid;
        e = mid - 1;
      } else {
        s = mid + 1;
      }
    }
  }

  if (pivot == -1) {
    s = 0;
    e = n - 1;
  } else {
    if (target < nums[0]) {
      s = pivot;
      e = n - 1;
    } else {
      s = 0;
      e = pivot - 1;
    }
  }

  while (s <= e) {
    int mid = s + (e - s) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }

  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}