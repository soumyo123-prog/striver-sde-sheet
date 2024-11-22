#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry = 0;

  ListNode* c1 = l1;
  ListNode* c2 = l2;

  ListNode* head = new ListNode();
  ListNode* tmp = head;

  while (c1 != nullptr && c2 != nullptr) {
    tmp->val = (carry + c1->val + c2->val) % 10;
    carry = (carry + c1->val + c2->val) / 10;
    c1 = c1->next;
    c2 = c2->next;
    tmp->next = new ListNode();
    tmp = tmp->next;
  }

  while (c1 != nullptr) {
    tmp->val = (carry + c1->val) % 10;
    carry = (carry + c1->val) / 10;
    c1 = c1->next;
    tmp->next = new ListNode();
    tmp = tmp->next;
  }

  while (c2 != nullptr) {
    tmp->val = (carry + c2->val) % 10;
    carry = (carry + c2->val) / 10;
    c2 = c2->next;
    tmp->next = new ListNode();
    tmp = tmp->next;
  }

  while (carry > 0) {
    tmp->val = carry % 10;
    carry /= 10;
    tmp->next = new ListNode();
    tmp = tmp->next;
  }

  tmp = head;
  while (tmp->next != nullptr && tmp->next->next != nullptr) {
    tmp = tmp->next;
  }

  tmp->next = nullptr;

  return head;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}