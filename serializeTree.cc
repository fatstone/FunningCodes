/*
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or transmitted
 * across a network connection link to be reconstructed later in the same or another
 * computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no restriction
 * on how your serialization/deserialization algorithm should work. You just need to ensure
 * that a binary tree can be serialized to a string and this string can be deserialized to
 * the original tree structure.
 */

#include <iostream>
#include <sstream>

#include <queue>
#include <string>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> tokenString(string s) {
   istringstream f(s);
   string val;
   vector<int> res;

   while (getline(f, val, ',')) {
      if (val == "#") {
         res.push_back(INT_MIN);
      } else {
         res.push_back(atoi(val.c_str()));
      }
   }
   return res;
}

string serialize(TreeNode* root) {
   queue<TreeNode*> bfs;
   string res = "";
   int len;

   bfs.push(root);
   while (!bfs.empty()) {

      TreeNode *node = bfs.front();
      bfs.pop();

      string postFix;
      if (node == NULL) {
         postFix = res.length() == 0 ? "#" : ",#";
      } else {
         postFix = res.length() == 0 ? to_string(node->val):
                                       "," + to_string(node->val);
         bfs.push(node->left);
         bfs.push(node->right);
      }
      res += postFix;
   }
   
   for (len = res.length()-1; len >= 0; len--) {
      if (res[len] != ',' && res[len] != '#') {
         break;
      }
   } 
   return res.substr(0, len+1);
}

TreeNode* deserialize(string data) {
   queue<TreeNode*> bfs;
   TreeNode* root;
   vector<int> tokens;
   int idx = 0;

   tokens = tokenString(data);
   if (tokens.size() == 0) {
      return NULL;
   }

   root = new TreeNode(tokens[idx]);
   bfs.push(root);
   idx++;
   
   while (!bfs.empty() && idx < tokens.size()) {
      TreeNode* node = bfs.front();
      bfs.pop();

      if (tokens[idx] == INT_MIN) {
         node->left = NULL;
      } else {
         node->left = new TreeNode(tokens[idx]);
         bfs.push(node->left);
      }
      idx++;

      if (idx >= tokens.size()) {
         break;
      }

      if (tokens[idx] == INT_MIN) {
         node->right = NULL;
      } else {
         node->right = new TreeNode(tokens[idx]);
         bfs.push(node->right);
      }
      idx++;
   }
   return root;
}

void _test() {
   string s = "1,2";
   TreeNode* tree = deserialize(s);

   string res = serialize(tree);
   cout << s << '\t' << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
