#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int val) {
    this->val = val;
    this->next = nullptr;
  }
};

class MinStack {
 public:
  stack<Node*> st;
  Node* minNode;

  MinStack() {
    st = stack<Node*>();
    minNode = nullptr;
  }

  void push(int val) {
    Node* newNode = new Node(val);
    if (minNode == nullptr) {
      minNode = newNode;
    } else if (val < minNode->val) {
      newNode->next = minNode;
      minNode = newNode;
    }
    st.push(newNode);
  }

  void pop() {
    if (st.empty()) {
      return;
    }

    Node* top = st.top();
    st.pop();

    if (top == minNode) {
      minNode = minNode->next;
      top->next = nullptr;
      delete top;
    }
  }

  int top() {
    if (st.empty()) {
      return -1;
    }

    return st.top()->val;
  }

  int getMin() {
    if (minNode == nullptr) {
      return -1;
    }

    return minNode->val;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}