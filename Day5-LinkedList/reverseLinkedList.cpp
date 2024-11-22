#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  if (head == nullptr) {
    return head;
  }

  ListNode* curr = head;
  ListNode* nxt = curr->next;

  curr->next = nullptr;

  while (nxt != nullptr) {
    ListNode* tmp = nxt->next;
    nxt->next = curr;
    curr = nxt;
    nxt = tmp;
  }

  return curr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}