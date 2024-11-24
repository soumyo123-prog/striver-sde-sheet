#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return nullptr;
  }

  ListNode* slowPtr = head;
  ListNode* fastPtr = head;

  do {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  } while (fastPtr != nullptr && fastPtr->next != nullptr &&
           slowPtr != fastPtr);

  if (slowPtr != fastPtr) {
    return nullptr;
  }

  fastPtr = head;

  while (fastPtr != slowPtr) {
    fastPtr = fastPtr->next;
    slowPtr = slowPtr->next;
  }

  return fastPtr;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}