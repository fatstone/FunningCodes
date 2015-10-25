/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int commonLength(string& s1, string& s2) {
   int len = min(s1.length(), s2.length());
   int pos = -1;
   for (int i = 0; i < len; i++) {
      if (s1[i] == s2[i]) {
         pos = i;
      } else {
         break;
      }
   }
   return (pos == -1) ? 0 : pos+1;
}

int _longestCommonPrefix(vector<string>& strs, int start, int end) {
   int minLen1, minLen2;
   string s1, s2;
   int mid = (start + end)/2;

   if (start > end) {
      return 0;
   }
   if (start == end) {
      return strs[start].length();
   }
   if (start == end-1) {
      return commonLength(strs[start], strs[end]);
   }

   minLen1 = _longestCommonPrefix(strs, start, mid);
   minLen2 = _longestCommonPrefix(strs, mid+1, end);
   if (minLen1 == 0 || minLen2 == 0) {
      return 0;
   }

   s1 = strs[start].substr(0, minLen1);
   s2 = strs[mid+1].substr(0, minLen2);
   return commonLength(s1, s2);
}

string longestCommonPrefix(vector<string>& strs) {
   int minLen = _longestCommonPrefix(strs, 0, strs.size()-1);
   return (minLen > 0) ? strs[0].substr(0, minLen) : "";
}

int main (int argc, char* argv[]) {
   vector<string> strs;
   strs.push_back("a");
   strs.push_back("a");
   strs.push_back("b");

   string res = longestCommonPrefix(strs);
   cout << "longest common prefix string: " << res << '\n';
   return 0;
}
