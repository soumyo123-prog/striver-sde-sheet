#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
  if (head->next == nullptr) {
    return true;
  }

  int len = 0;
  ListNode* curr = head;
  while (curr->next != nullptr) {
    len++;
    curr = curr->next;
  }
  len++;

  ListNode* tail = curr;

  curr = head;
  for (int i = 1; i < len / 2; i++) {
    curr = curr->next;
  }

  ListNode* t = len & 1 ? curr->next->next : curr->next;
  ListNode* nxt = t->next;

  curr->next = nullptr;
  t->next = nullptr;
  curr = t;

  ListNode* tmp = nullptr;

  while (nxt != nullptr) {
    tmp = nxt->next;
    nxt->next = curr;
    curr = nxt;
    nxt = tmp;
  }

  ListNode* c1 = head;
  ListNode* c2 = tail;

  while (c1 != nullptr && c2 != nullptr) {
    if (c1->val != c2->val) {
      return false;
    }
    c1 = c1->next;
    c2 = c2->next;
  }

  c1 = head;
  c2 = tail;

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}