#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int value;
  Node* prev;
  Node* next;

  Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

class LRUCache {
 public:
  int capacity;
  unordered_map<int, Node*> mp;
  Node* lowestPriorityNode;
  Node* highestPriorityNode;

  LRUCache(int capacity) {
    this->capacity = capacity;
    lowestPriorityNode = new Node(-1, -1);
    highestPriorityNode = new Node(-1, -1);
    lowestPriorityNode->next = highestPriorityNode;
    highestPriorityNode->prev = lowestPriorityNode;
  }

  void addNode(Node* node) {
    Node* tmp = highestPriorityNode->prev;

    node->next = highestPriorityNode;
    highestPriorityNode->prev = node;

    node->prev = tmp;
    tmp->next = node;
  }

  void removeNode(Node* node) {
    Node* tmp = node->prev;
    Node* nxt = node->next;

    tmp->next = nxt;
    nxt->prev = tmp;

    node->prev = nullptr;
    node->next = nullptr;
  }

  int get(int key) {
    if (mp.find(key) == mp.end()) {
      return -1;
    }

    Node* keyNode = mp[key];

    removeNode(keyNode);
    addNode(keyNode);

    return keyNode->value;
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end()) {
      Node* keyNode = mp[key];
      removeNode(keyNode);
      delete keyNode;
    }

    Node* newNode = new Node(key, value);

    addNode(newNode);
    mp[key] = newNode;

    if (mp.size() > capacity) {
      Node* deletedNode = lowestPriorityNode->next;

      removeNode(deletedNode);
      mp.erase(mp.find(deletedNode->key));

      delete deletedNode;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}