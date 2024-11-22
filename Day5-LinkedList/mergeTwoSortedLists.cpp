#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  if (list1 == nullptr) {
    return list2;
  }
  if (list2 == nullptr) {
    return list1;
  }

  ListNode* tmp = new ListNode(0);
  ListNode* head = tmp;
  ListNode* c1 = list1;
  ListNode* c2 = list2;

  while (c1 != nullptr && c2 != nullptr) {
    if (c1->val < c2->val) {
      tmp->next = c1;
      c1 = c1->next;
    } else {
      tmp->next = new ListNode(c2->val);
      c2 = c2->next;
    }
    tmp = tmp->next;
  }

  while (c1 != nullptr) {
    tmp->next = c1;
    tmp = tmp->next;
    c1 = c1->next;
  }

  while (c2 != nullptr) {
    tmp->next = c2;
    tmp = tmp->next;
    c2 = c2->next;
  }

  return head->next;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}