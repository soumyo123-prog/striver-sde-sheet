#include <bits/stdc++.h>
using namespace std;

void merge(long long *arr, int low, int mid, int high,
           long long &numInversions) {
  vector<long long> tmp;

  int i = low, j = mid + 1;
  while (i <= mid && j <= high) {
    if (*(arr + i) <= *(arr + j)) {
      tmp.push_back(*(arr + i));
      i++;
    } else {
      numInversions += (mid - i + 1);
      tmp.push_back(*(arr + j));
      j++;
    }
  }

  while (i <= mid) {
    tmp.push_back(*(arr + i));
    i++;
  }

  while (j <= high) {
    tmp.push_back(*(arr + j));
    j++;
  }

  int l = 0;
  for (int k = low; k <= high; k++, l++) {
    *(arr + k) = tmp[l];
  }
}

void mergeSort(long long *arr, int low, int high, long long &numInversions) {
  if (low >= high) {
    return;
  }

  int mid = low + (high - low) / 2;

  mergeSort(arr, low, mid, numInversions);
  mergeSort(arr, mid + 1, high, numInversions);
  merge(arr, low, mid, high, numInversions);
}

long long getInversions(long long *arr, int n) {
  long long numInversions = 0;

  mergeSort(arr, 0, n - 1, numInversions);

  return numInversions;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}