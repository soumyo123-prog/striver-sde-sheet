#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

void inorder(Node *node, int k, int &counter, int &res) {
  if (node == nullptr) {
    return;
  }

  inorder(node->right, k, res, counter);

  counter++;
  if (counter == k) {
    res = node->data;
    return;
  }

  inorder(node->left, k, res, counter);
}

int kthLargest(Node *root, int k) {
  int counter = 0, res;
  inorder(root, k, counter, res);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}