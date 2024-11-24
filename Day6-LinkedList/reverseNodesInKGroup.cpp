#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  if (k == 1) {
    return head;
  }

  ListNode* curr = head;
  ListNode* nxt = head->next;
  ListNode* tmp = nullptr;
  ListNode* first = curr;
  ListNode* last = nullptr;
  ListNode* nodeToReturn = nullptr;

  int len = 0;
  while (curr != nullptr) {
    len++;
    curr = curr->next;
  }
  curr = head;

  int cnt = 1, totTimes = len / k, times = 0;

  while (times < totTimes && nxt != nullptr) {
    tmp = nxt->next;
    nxt->next = curr;
    curr = nxt;
    nxt = tmp;

    cnt++;

    if (cnt == k) {
      if (nodeToReturn == nullptr) {
        nodeToReturn = curr;
      }

      cnt = 1;
      times++;

      if (last != nullptr) {
        last->next = curr;
      }

      last = first;
      first->next = nxt;
      curr = nxt;
      if (nxt != nullptr) {
        nxt = nxt->next;
      }
      first = curr;
    }
  }

  return nodeToReturn;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}
