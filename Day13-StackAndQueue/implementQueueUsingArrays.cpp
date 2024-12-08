#include <bits/stdc++.h>
using namespace std;

class MyQueue {
 private:
  int arr[100005];
  int front;
  int rear;

 public:
  MyQueue() {
    front = 0;
    rear = 0;
  }
  void push(int);
  int pop();
};

void MyQueue ::push(int x) {
  rear++;
  arr[rear] = x;
}

int MyQueue ::pop() {
  if (front == rear) {
    return -1;
  }

  front++;
  return arr[front];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}