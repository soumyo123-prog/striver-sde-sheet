#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
  if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
    return false;
  }

  ListNode* slowPtr = head->next;
  ListNode* fastPtr = head->next->next;

  while (slowPtr != nullptr && fastPtr != nullptr && fastPtr->next != nullptr &&
         slowPtr != fastPtr) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }

  if (fastPtr == nullptr || slowPtr == nullptr || slowPtr != fastPtr) {
    return false;
  }

  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}