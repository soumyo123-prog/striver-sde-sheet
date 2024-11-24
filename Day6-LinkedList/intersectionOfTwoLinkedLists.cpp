#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
  int len1 = 0, len2 = 0;

  ListNode* c1 = headA;
  ListNode* c2 = headB;

  while (c1 != nullptr) {
    len1++;
    c1 = c1->next;
  }

  while (c2 != nullptr) {
    len2++;
    c2 = c2->next;
  }

  c1 = headA;
  c2 = headB;

  int reqLen = abs(len1 - len2);

  if (len1 > len2) {
    for (int i = 1; i <= reqLen; i++) {
      c1 = c1->next;
    }
  } else if (len2 > len1) {
    for (int i = 1; i <= reqLen; i++) {
      c2 = c2->next;
    }
  }

  while (c1 != nullptr && c2 != nullptr) {
    if (c1 == c2) {
      return c1;
    }
    c1 = c1->next;
    c2 = c2->next;
  }

  return nullptr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}