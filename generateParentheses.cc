/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void _generateParenthesis(vector<string>& res, int n, set<string>& maps, string prefix) {
   if (n == 1) {
      if (maps.find(prefix) == maps.end()) {
         maps.insert(prefix); 
         res.push_back(prefix);
      }
      return;
   }

   for (int i = 0; i < prefix.length(); i++) {
      string newPrefix = prefix.substr(0, i) + "()" + prefix.substr(i);
      _generateParenthesis(res, n-1, maps, newPrefix);
   }
}

vector<string> generateParenthesis(int n) {
   vector<string> res;
   set<string> maps;
   if (n <= 0) {
      return res;
   }

   _generateParenthesis(res, n, maps, "()");
   return res;
}

void _generateParenthesis1(vector<string>& res, string s, int leftParNum, int rightParNum, int n) {
   if (leftParNum == n) {
      s.append(leftParNum-rightParNum, ')');
      res.push_back(s);
      return;
   }

   _generateParenthesis1(res, s + "(", leftParNum+1, rightParNum, n);
   if (leftParNum > rightParNum) {
      _generateParenthesis1(res, s + ")", leftParNum, rightParNum+1, n);
   }
}

vector<string> generateParenthesis1(int n) {
   vector<string> res;

   _generateParenthesis1(res, "", 0, 0, n);
   return res;
}

int main (int argc, char* argv[]) {
   //vector<string> res = generateParenthesis(3);
   vector<string> res = generateParenthesis1(3);

   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
   }
   return 0;
}
