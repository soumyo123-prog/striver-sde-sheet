#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

vector<int> bottomView(Node* root) {
  vector<int> bv;
  if (root == nullptr) {
    return bv;
  }

  queue<pair<Node*, int>> q;
  q.push({root, 0});

  unordered_map<int, int> mp;

  int minLft = 0, maxRgt = 0;

  while (!q.empty()) {
    for (int i = 0; i < q.size(); i++) {
      pair<Node*, int> u = q.front();
      q.pop();
      mp[u.second] = u.first->data;
      if (u.first->left != nullptr) {
        q.push({u.first->left, u.second - 1});
        minLft = min(minLft, u.second - 1);
      }
      if (u.first->right != nullptr) {
        q.push({u.first->right, u.second + 1});
        maxRgt = max(maxRgt, u.second + 1);
      }
    }
  }

  for (int i = minLft; i <= maxRgt; i++) {
    if (mp.find(i) != mp.end()) {
      bv.push_back(mp[i]);
    }
  }

  return bv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}