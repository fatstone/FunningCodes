/*
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 * search(word) can search a literal word or a regular expression string containing
 * only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
   bool endOfString;
   unordered_map<char, TrieNode*> children;
};

TrieNode* findTrieNode(TrieNode* root, char c) {
   if (root->children.find(c) == root->children.end()) {
      return NULL;
   }
   return root->children[c];
}

class WordDictionary {
   TrieNode* root;
   bool _search(TrieNode* root, string word) {
      if (word.length() == 0) {
         return root->endOfString;
      }
      if (word[0] == '.') {
         for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            if (_search(it->second, word.substr(1))) {
               return true;
            }
         }
         return false;
      }

      if (findTrieNode(root, word[0]) == NULL) {
         return false;
      }

      return _search(root->children[word[0]], word.substr(1));
   }

public:
   WordDictionary() {
      root = new TrieNode();
      root->endOfString = false;
   }

   // Adds a word into the data structure.
   void addWord(string word) {
      if (word.length() == 0) {
         return;
      } 

      TrieNode* _root = root;
      for (int i = 0; i < word.length(); i++) {
         TrieNode* node = findTrieNode(_root, word[i]);
         if (node == NULL) {
            node = new TrieNode();
            _root->children[word[i]] = node;
         }
         _root = node;
      }
      _root->endOfString = true;
   }
   
   // Returns if the word is in the data structure. A word could
   // contain the dot character '.' to represent any one letter.
   bool search(string word) {
      return _search(root, word);
   }
};

void _test1() {
   WordDictionary *w = new WordDictionary();
   w->addWord("a");
   w->addWord("ab");

   bool res = w->search("a");
   cout << res << endl;

   res = w->search("a.");
   cout << res << endl;

   res = w->search("ab");
   cout << res << endl;

   res = w->search(".a");
   cout << res << endl;

   res = w->search(".b");
   cout << res << endl;

   res = w->search("ab.");
   cout << res << endl;

   res = w->search(".");
   cout << res << endl;

   res = w->search("..");
   cout << res << endl;
}
void _test() {
   WordDictionary *w = new WordDictionary();
   w->addWord("bad");
   w->addWord("dad");
   w->addWord("mad");

   bool res = w->search("pad");
   cout << res << endl;

   res = w->search("bad");
   cout << res << endl;

   res = w->search(".ad");
   cout << res << endl;

   res = w->search("..d");
   cout << res << endl;
   cout << "===" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   _test1();
   return 0;
}
