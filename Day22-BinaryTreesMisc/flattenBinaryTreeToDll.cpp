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

Node* bToDLL(Node* root) {
  if (root == nullptr) {
    return root;
  }

  Node* head = nullptr;
  Node* tail = nullptr;

  Node* curr = root;
  while (curr != nullptr) {
    if (curr->left == nullptr) {
      if (head == nullptr) {
        head = curr;
        tail = curr;
      } else {
        tail->right = curr;
        curr->left = tail;
        tail = curr;
      }
      curr = curr->right;
      continue;
    }

    Node* tmp = curr->left;
    while (tmp->right != nullptr && tmp->right != curr) {
      tmp = tmp->right;
    }

    if (tmp->right == nullptr) {
      tmp->right = curr;
      curr = curr->left;
    } else {
      if (head == nullptr) {
        head = curr;
        tail = curr;
      } else {
        tail->right = curr;
        curr->left = tail;
        tail = curr;
      }
      curr = curr->right;
    }
  }

  return head;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}