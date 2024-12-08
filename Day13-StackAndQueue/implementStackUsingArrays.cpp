#include <bits/stdc++.h>
using namespace std;

class MyStack {
 private:
  int arr[1000];
  int top;

 public:
  MyStack() { top = -1; }
  int pop();
  void push(int);
};

void MyStack ::push(int x) {
  top++;
  arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
  if (top == -1) return top;

  int popped = arr[top];
  top--;
  return popped;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}