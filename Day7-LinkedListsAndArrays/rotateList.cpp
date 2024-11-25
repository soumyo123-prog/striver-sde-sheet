#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  int len = 0;
  ListNode* curr = head;

  while (curr != nullptr) {
    len++;
    curr = curr->next;
  }

  k = k % len;

  if (k == 0) return head;

  curr = head;
  ListNode* nxt = curr->next;

  int pos = 1;
  while (pos < len - k) {
    pos++;
    curr = curr->next;
    nxt = nxt->next;
  }

  curr->next = nullptr;

  ListNode* newHead = nxt;

  while (nxt->next != nullptr) {
    nxt = nxt->next;
  }

  nxt->next = head;

  return newHead;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}