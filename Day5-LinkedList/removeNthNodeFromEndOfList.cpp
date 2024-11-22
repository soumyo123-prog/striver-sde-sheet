#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  int len = 0;

  ListNode* curr = head;

  while (curr != nullptr) {
    len++;
    curr = curr->next;
  }

  int reqLen = len - n + 1;
  curr = head;
  ListNode* prev = nullptr;

  for (int i = 1; i < reqLen; i++) {
    prev = curr;
    curr = curr->next;
  }

  if (prev != nullptr) {
    prev->next = curr->next;
    return head;
  }

  return curr->next;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}