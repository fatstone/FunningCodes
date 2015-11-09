/*
 * Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 * Note: The input string may contain letters other than the parentheses ( and ).
 *
 * Examples:
 * "()())()" -> ["()()()", "(())()"]
 * "(a)())()" -> ["(a)()()", "(a())()"]
 * ")(" -> [""]
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>

using namespace std;

bool isParenthessValid(string s) {
   int leftParenthess = 0;

   for (int i = 0; i < s.length(); i++) {
      if (s[i] != ')' && s[i] != '(') {
         continue;
      }

      if (s[i] == ')') {
         if (leftParenthess == 0) {
            return false;
         } else {
            leftParenthess--;
         }
      } else {
         leftParenthess++;
      }
   }
   return leftParenthess == 0;
}

vector<string> removeInvalidParentheses(string s) {
   vector<string> res;
   queue<string>  pendingStrings;
   set<string> maps;

   pendingStrings.push(s);

   while (!pendingStrings.empty()) {
      string curString = pendingStrings.front();
      pendingStrings.pop();

      if (isParenthessValid(curString)) {
         res.push_back(curString);
      } else if (res.size() == 0) {
         string newString;

         for (int i = 0; i < curString.length(); i++) {
            if (curString[i] != ')' && curString[i] != '(') {
               continue;
            }
            if (i > 0 && curString[i] == curString[i-1]) {
               continue;
            }
            newString = curString.substr(0, i) + curString.substr(i+1);
            if (maps.find(newString) == maps.end()) {
               maps.insert(newString);
               pendingStrings.push(newString);
            }
         }
      }
   }
   return res;
}

void _test() {
   string s = ")k)))())()())))())";
   vector<string> res = removeInvalidParentheses(s);

   for (int j = 0; j < res.size(); j++) {
      cout << res[j] << endl;
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
