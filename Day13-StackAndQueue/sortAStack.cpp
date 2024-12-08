#include <bits/stdc++.h>
using namespace std;

void takeOut(stack<int> &stack,
             priority_queue<int, vector<int>, greater<int>> &pq) {
  if (stack.empty()) return;

  pq.push(stack.top());
  stack.pop();

  takeOut(stack, pq);
}

void reinsert(stack<int> &stack,
              priority_queue<int, vector<int>, greater<int>> &pq) {
  if (pq.empty()) return;

  stack.push(pq.top());
  pq.pop();
  reinsert(stack, pq);
}

void sortStack(stack<int> &stack) {
  priority_queue<int, vector<int>, greater<int>> pq;
  takeOut(stack, pq);
  reinsert(stack, pq);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}