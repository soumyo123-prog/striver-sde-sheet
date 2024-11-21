#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int m = matrix.size(), n = matrix[0].size(), fs = m * n;

  int s = 0, e = fs - 1;

  while (s <= e) {
    int mid = s + (e - s) / 2;
    int row = mid / n, col = row == 0 ? mid : mid % n;
    int num = matrix[row][col];
    if (num == target) {
      return true;
    } else if (num < target) {
      s = mid + 1;
    } else {
      e = mid - 1;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}