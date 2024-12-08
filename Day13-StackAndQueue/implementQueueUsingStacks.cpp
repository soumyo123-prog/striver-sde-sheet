#include <bits/stdc++.h>
using namespace std;

class MyQueue {
  stack<int> s1;
  stack<int> s2;

 public:
  MyQueue() {
    s1 = stack<int>();
    s2 = stack<int>();
  }

  void push(int x) { s1.push(x); }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }

    int popped = s2.top();
    s2.pop();
    return popped;
  }

  int peek() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }

    return s2.top();
  }

  bool empty() {
    if (!s1.empty() || !s2.empty()) return false;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}