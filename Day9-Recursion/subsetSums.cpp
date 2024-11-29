#include <bits/stdc++.h>
using namespace std;

void subsetSumHelper(vector<int> &arr, int i, int sum, vector<int> &sums) {
  if (i == arr.size()) {
    sums.push_back(sum);
    return;
  }

  subsetSumHelper(arr, i + 1, sum + arr[i], sums);
  subsetSumHelper(arr, i + 1, sum, sums);
}

vector<int> subsetSums(vector<int> &arr) {
  vector<int> sum;

  subsetSumHelper(arr, 0, 0, sum);

  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}