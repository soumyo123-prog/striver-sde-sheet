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

void traverse(Node* root, vector<int> path, vector<vector<int>>& paths) {
  path.push_back(root->data);

  if (root->left == nullptr && root->right == nullptr) {
    paths.push_back(path);
    return;
  }

  if (root->left != nullptr) {
    traverse(root->left, path, paths);
  }

  if (root->right != nullptr) {
    traverse(root->right, path, paths);
  }
}

vector<vector<int>> Paths(Node* root) {
  vector<int> path;
  vector<vector<int>> paths;

  if (root == nullptr) {
    return paths;
  }

  traverse(root, path, paths);

  return paths;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}