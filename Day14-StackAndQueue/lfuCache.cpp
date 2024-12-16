#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  int value;
  int useCounter;
  Node* prev;
  Node* next;

  Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->useCounter = 1;
    this->prev = nullptr;
    this->next = nullptr;
  }

  Node(int key, int value, int useCounter) {
    this->key = key;
    this->value = value;
    this->useCounter = useCounter;
    this->prev = nullptr;
    this->next = nullptr;
  }
};

struct Util {
  Node* lpn;
  Node* hpn;

  Util() {
    lpn = new Node(-1, -1);
    hpn = new Node(-1, -1);
    lpn->next = hpn;
    hpn->prev = lpn;
  }
};

class LFUCache {
 public:
  int capacity;
  int lfu;
  unordered_map<int, Node*> nodeInfo;
  unordered_map<int, Util*> freqInfo;

  LFUCache(int capacity) {
    this->capacity = capacity;
    lfu = 0;
  }

  void deleteUtil(Util* util) {
    util->hpn->prev = nullptr;
    util->hpn->next = nullptr;
    util->lpn->prev = nullptr;
    util->lpn->next = nullptr;

    delete util->lpn;
    delete util->hpn;
    delete util;
  }

  int get(int key) {
    if (nodeInfo.find(key) == nodeInfo.end()) {
      return -1;
    }

    Node* node = nodeInfo[key];
    Util* util = freqInfo[node->useCounter];

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = nullptr;
    node->prev = nullptr;

    if (util->lpn->next == util->hpn) {
      freqInfo.erase(node->useCounter);
      if (lfu == node->useCounter) {
        lfu++;
      }
      deleteUtil(util);
    }

    if (freqInfo.find(node->useCounter + 1) == freqInfo.end()) {
      freqInfo[node->useCounter + 1] = new Util();
    }

    node->useCounter = node->useCounter + 1;

    util = freqInfo[node->useCounter];

    util->lpn->next = node;
    node->prev = util->lpn;
    util->hpn->prev = node;
    node->next = util->hpn;

    return node->value;
  }

  void put(int key, int value) {
    if (nodeInfo.find(key) != nodeInfo.end()) {
      Node* node = nodeInfo[key];

      node->prev->next = node->next;
      node->next->prev = node->prev;
      node->prev = nullptr;
      node->next = nullptr;

      Util* util = freqInfo[node->useCounter];
      if (util->lpn->next == util->hpn) {
        freqInfo.erase(node->useCounter);
        if (lfu == node->useCounter) {
          lfu++;
        }
        deleteUtil(util);
      }

      if (freqInfo.find(node->useCounter + 1) == freqInfo.end()) {
        freqInfo[node->useCounter + 1] = new Util();
      }

      node->useCounter = node->useCounter + 1;

      util = freqInfo[node->useCounter];

      util->lpn->next = node;
      node->prev = util->lpn;
      util->hpn->prev = node;
      node->next = util->hpn;

      return;
    }

    if (nodeInfo.size() == capacity) {
      Util* util = freqInfo[lfu];
      Node* nodeToErase = util->lpn->next;

      util->lpn->next = nodeToErase->next;
      nodeToErase->next->prev = util->lpn;
      nodeToErase->prev = nullptr;
      nodeToErase->next = nullptr;

      nodeInfo.erase(nodeToErase->key);
      delete nodeToErase;

      if (util->lpn->next == util->hpn) {
        freqInfo.erase(lfu);
        deleteUtil(util);
      }
    }

    if (freqInfo.find(1) == freqInfo.end()) {
      freqInfo[1] = new Util();
    }

    Util* util = freqInfo[1];
    Node* newNode = new Node(key, value);
    Node* tmp = util->hpn->prev;

    util->hpn->prev = newNode;
    tmp->next = newNode;
    newNode->next = util->hpn;
    newNode->prev = tmp;

    nodeInfo[key] = newNode;

    lfu = 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}