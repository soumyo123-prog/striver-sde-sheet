#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
  if (head->next == nullptr) {
    return head;
  }

  int len = 0;
  ListNode* curr = head;
  while (curr != nullptr) {
    len++;
    curr = curr->next;
  }

  int reqLen = len / 2 + 1;
  curr = head;
  for (int i = 1; i < reqLen; i++) {
    curr = curr->next;
  }

  return curr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}