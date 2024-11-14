#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int>::iterator first, vector<int>::iterator last) {
  for (vector<int>::iterator it = first; it != last; ++it) {
    cout << *it << ' ';
  }
  cout << endl;
}

void nextPermutation(vector<int>& nums) {
  int bp = -1, n = nums.size();

  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] < nums[i + 1]) {
      bp = i;
      break;
    }
  }

  if (bp == -1) {
    reverse(nums.begin(), nums.end());
    return;
  }

  for (int i = n - 1; i > bp; i--) {
    if (nums[i] > nums[bp]) {
      swap(nums[i], nums[bp]);
      break;
    }
  }

  reverse(nums.begin() + bp + 1, nums.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> arr = {1, 2, 3, 4, 5};

  do {
    print_array(arr.begin(), arr.end());
  } while (next_permutation(arr.begin(), arr.end()));

  return 0;
}