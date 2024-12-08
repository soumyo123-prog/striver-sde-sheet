#include <bits/stdc++.h>
using namespace std;

class MyStack {
  queue<int> q1;
  queue<int> q2;

 public:
  MyStack() {
    q1 = queue<int>();
    q2 = queue<int>();
  }

  void push(int x) {
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    q1.push(x);
    while (!q2.empty()) {
      q1.push(q2.front());
      q2.pop();
    }
  }

  int pop() {
    int popped = q1.front();
    q1.pop();
    return popped;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}