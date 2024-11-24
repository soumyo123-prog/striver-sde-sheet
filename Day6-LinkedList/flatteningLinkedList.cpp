#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  struct Node* bottom;

  Node(int x) {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

Node* merge(Node* head1, Node* head2) {
  Node* dummy = new Node(-1);
  Node* curr = dummy;

  while (head1 != nullptr && head2 != nullptr) {
    if (head1->data <= head2->data) {
      curr->bottom = head1;
      curr = curr->bottom;
      head1 = head1->bottom;
    } else {
      curr->bottom = head2;
      curr = curr->bottom;
      head2 = head2->bottom;
    }
  }

  if (head1 != nullptr) {
    curr->bottom = head1;
  }

  if (head2 != nullptr) {
    curr->bottom = head2;
  }

  return dummy->next;
}

// Function which returns the  root of the flattened linked list.
Node* flatten(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  head->next = flatten(head->next);

  return merge(head, head->next);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}