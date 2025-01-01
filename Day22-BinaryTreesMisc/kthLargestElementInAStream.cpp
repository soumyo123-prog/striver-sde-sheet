#include <bits/stdc++.h>
using namespace std;

class KthLargest {
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int pos;

 public:
  KthLargest(int k, vector<int>& nums) {
    pos = nums.size() + 1 - k;
    for (int i = 0; i < nums.size(); i++) {
      minHeap.push(nums[i]);
      if (minHeap.size() > pos) {
        minHeap.pop();
      }
    }
  }

  int add(int val) {
    int top = minHeap.top();
    if (val >= top) {
      return top;
    }

    minHeap.pop();
    minHeap.push(val);

    return minHeap.top();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}