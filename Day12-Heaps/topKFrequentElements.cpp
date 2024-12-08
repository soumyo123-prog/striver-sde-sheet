#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  int n = nums.size();

  unordered_map<int, int> freq;

  for (int i = 0; i < n; i++) {
    freq[nums[i]]++;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  for (unordered_map<int, int>::iterator itr = freq.begin(); itr != freq.end();
       itr++) {
    pq.push({itr->second, itr->first});
    if (pq.size() > k) {
      pq.pop();
    }
  }

  if (pq.size() > k) {
    pq.pop();
  }

  vector<int> sol;
  while (!pq.empty()) {
    sol.push_back(pq.top().second);
    pq.pop();
  }

  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}