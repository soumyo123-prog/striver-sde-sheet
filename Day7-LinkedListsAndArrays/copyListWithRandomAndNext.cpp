#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node* copyRandomList(Node* head) {
  if (head == nullptr) {
    return head;
  }

  Node* curr = head;
  Node* newNode = nullptr;
  while (curr != nullptr) {
    newNode = new Node(curr->val);
    newNode->next = curr->next;
    curr->next = newNode;
    curr = newNode->next;
  }

  curr = head;
  Node* nxt = curr->next;
  while (curr != nullptr) {
    nxt->random = curr->random == nullptr ? nullptr : curr->random->next;
    curr = nxt->next;
    if (curr != nullptr) {
      nxt = curr->next;
    }
  }

  Node* newHead = new Node(-1);
  nxt = newHead;
  curr = head;

  while (curr != nullptr) {
    nxt->next = curr->next;
    nxt = nxt->next;

    curr->next = curr->next->next;
    curr = curr->next;
  }

  return newHead->next;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}