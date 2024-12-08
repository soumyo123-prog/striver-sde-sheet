#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
 public:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  MedianFinder() {
    maxHeap = priority_queue<int>();
    minHeap = priority_queue<int, vector<int>, greater<int>>();
  }

  void addNum(int num) {
    if (maxHeap.empty()) {
      maxHeap.push(num);
      return;
    }

    if (minHeap.empty() && maxHeap.top() <= num) {
      minHeap.push(num);
      return;
    }

    if (minHeap.empty() && num < maxHeap.top()) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
      maxHeap.push(num);
      return;
    }

    if (num >= maxHeap.top()) {
      minHeap.push(num);
    } else {
      maxHeap.push(num);
    }

    if (minHeap.size() > maxHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
      return;
    }

    if (maxHeap.size() == 2 + minHeap.size()) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
  }

  double findMedian() {
    if ((maxHeap.size() + minHeap.size()) & 1) {
      return maxHeap.top();
    }

    return (maxHeap.top() + minHeap.top()) / 2.0;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}