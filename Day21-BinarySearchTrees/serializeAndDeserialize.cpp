#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    string res = "";

    if (root == nullptr) {
      return res;
    }

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
          res += ",#";
        } else {
          if (res.size() > 0) {
            res += ",";
          }
          res += to_string(node->val);
          q.push(node->left);
          q.push(node->right);
        }
      }
    }

    return res;
  }
  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.size() == 0) {
      return nullptr;
    }

    vector<string> tokens;

    string str = "";
    for (int i = 0; i < data.size(); i++) {
      if (data[i] != ',') {
        str += data[i];
      } else {
        tokens.push_back(str);
        str = "";
      }
    }
    tokens.push_back(str);

    TreeNode *root = new TreeNode(stoi(tokens[0]));

    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < tokens.size()) {
      int size = q.size();
      while (size--) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
          continue;
        }

        string t1 = tokens[i++], t2 = tokens[i++];
        if (t1 != "#") {
          node->left = new TreeNode(stoi(t1));
          q.push(node->left);
        }
        if (t2 != "#") {
          node->right = new TreeNode(stoi(t2));
          q.push(node->right);
        }
      }
    }

    return root;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}