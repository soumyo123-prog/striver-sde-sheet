#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

Node* cloneGraph(Node* node) {
  if (node == nullptr) {
    return node;
  }

  vector<int> adj[101];
  bool vis[101];

  queue<Node*> q;
  q.push(node);

  vis[node->val] = true;

  while (!q.empty()) {
    Node* u = q.front();
    q.pop();

    for (int i = 0; i < u->neighbors.size(); i++) {
      Node* v = u->neighbors[i];

      if (!vis[v->val]) {
        q.push(v);
        adj[u->val].push_back(v->val);
        vis[v->val] = true;
      }
    }
  }

  for (int i = 1; i <= 100; i++) {
    if (!vis[i]) continue;
    cout << "Node is: " << i << "; Values are: ";
    for (int j = 0; j < adj[i].size(); j++) {
      cout << adj[i][j] << ' ';
    }
    cout << endl;
  }

  Node* newNode = new Node(1);
  Node* curr = newNode;

  for (int i = 1; i <= 100; i++) {
    if (!vis[i]) {
      continue;
    }
  }

  return newNode;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}