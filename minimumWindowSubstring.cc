/*
 * Given a string S and a string T, find the minimum window in S which
 * will contain all the characters in T in complexity O(n).
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string minWindow(string s, string t) {
   vector<int> matchTableForT(128, -1);
   vector<int> matchTableForS(128, -1);
   vector<bool> matched(128, false);

   int idxT = 0, minLen = INT_MAX, pos = -1, uniqueSNum = 0, uniqueTNum = 0;

   for (int i = 0; i < t.length(); i++) {
      if (matchTableForT[t[i]] == -1) {
         matchTableForT[t[i]] = 1;
         uniqueTNum++;
      } else {
         matchTableForT[t[i]]++;
      }
   }

   for (int i = 0; i < s.length(); i++) {
      int len;
      if (matchTableForT[s[i]] == -1) {
         continue;
      }

      if (matchTableForS[s[i]] == -1) {
         matchTableForS[s[i]] = 1;
      } else {
         matchTableForS[s[i]]++;
      }

      if (matchTableForS[s[i]] >= matchTableForT[s[i]] && !matched[s[i]]) {
         matched[s[i]] = true;
         uniqueSNum++;
      }

      if (uniqueSNum < uniqueTNum) {
         continue;
      }

      while (idxT < i) {
         if (matchTableForS[s[idxT]] == -1) {
            idxT++;
            continue;
         }

         if (matchTableForS[s[idxT]] <= matchTableForT[s[idxT]]) {
            break;
         }

         matchTableForS[s[idxT]]--;
         idxT++;
      }

      len = i - idxT + 1;
      if (len < minLen) {
         minLen = len;
         pos = idxT;
      }
   }

   return pos == -1 ? "" : s.substr(pos, minLen);
}

int main (int argc, char* argv[]) {
#if 1
   string s = "ADOBECODEBANC";
   string t = "ABC";
#endif
#if 0
   string s = "aa";
   string t = "aa";
#endif

   string match = minWindow(s, t);
   cout << s << '\t' << t << '\t' << match << endl;
   return 0;
}
