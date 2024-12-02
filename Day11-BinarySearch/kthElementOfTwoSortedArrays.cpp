#include <bits/stdc++.h>
using namespace std;

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
  if (arr1.size() > arr2.size()) {
    swap(arr1, arr2);
  }

  int n = arr1.size(), m = arr2.size();

  int s = max(0, k - m), e = min(k, n);
  while (s <= e) {
    int mid = s + (e - s) / 2;

    int l1 = mid <= n ? arr1[mid - 1] : INT_MIN;
    int l2 = k - mid <= m ? arr2[k - mid - 1] : INT_MIN;
    int r1 = mid + 1 <= n ? arr1[mid] : INT_MAX;
    int r2 = k - mid + 1 <= m ? arr2[k - mid] : INT_MAX;

    if (max(l1, l2) <= min(r1, r2)) {
      return max(l1, l2);
    }

    if (l1 > r2) {
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

  int k;
  cin >> k;

  int n, m;
  cin >> n >> m;

  vector<int> arr1, arr2;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr1.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    arr2.push_back(x);
  }

  cout << kthElement(k, arr1, arr2) << endl;

  return 0;
}