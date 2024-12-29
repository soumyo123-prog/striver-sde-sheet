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

void mirror(Node* node) {
  if (node == nullptr) {
    return;
  }

  mirror(node->left);
  mirror(node->right);

  Node* tmp = node->left;
  node->left = node->right;
  node->right = tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}