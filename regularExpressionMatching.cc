/*
 *  '.' Matches any single character.
 *  '*' Matches zero or more of the preceding element.
 *
 *  The matching should cover the entire input string (not partial).
 *
 *  The function prototype should be:
 *  bool isMatch(const char *s, const char *p)
 *
 *  Some examples:
 *  isMatch("aa","a") → false
 *  isMatch("aa","aa") → true
 *  isMatch("aaa","aa") → false
 *  isMatch("aa", "a*") → true
 *  isMatch("aa", ".*") → true
 *  isMatch("ab", ".*") → true
 *  isMatch("aab", "c*a*b") → true
 */

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

/*
 * Recursive solution:
 * http://articles.leetcode.com/2011/09/regular-expression-matching.html
 */
bool _isMatch(const char* s, const char* p) {
   if (*p == '\0') {
      return *s == '\0';
   }

   if (*(p+1) != '*') {
      if (*s == *p || (*p == '.' && *s != '\0')) {
         return _isMatch(s+1, p+1);
      }
      return false;
   } else {
      while ((*s == *p) || (*p == '.' && *s != '\0')) {
         if (_isMatch(s, p+2)) {
            return true;
         }
         s++;
      }
      return _isMatch(s, p+2);
   }
}

bool isMatch(string s, string p) {
   return _isMatch(s.c_str(), p.c_str());
}

/*
 * DP Solution:
 * dp[i][j] represents if s.substr(0, i) matches p.substr(0, j).
 *
 *    s:  .....X....      p:......X.....
 *             ^                  ^
 *             |                  |
 *             ith                jth
 *
 * Generally, let's talk about this problem by two categories:
 * Case A: p[j] is not '*':
 *    This is a simple case: if ith of s matches jth of p, we
 *    should check result of s.substr(0, i-1) and s.substr(0, j-1):
 *    dp[i+1][j+1] = dp[i][j] && (s[i] matches p[j])
 *
 * Case B: p[j] is '*': 
 *    In this case, we need to check if s[i] matches p[j-1]
 *    1) if s[i] doesn't match p[j-1], we have to move backwards
 *       2 elements of p and check again:
 *       dp[i+1][j+1] = dp[i+1][j-1]
 *    2) if s[i] matches p[j-1], this indicates s[i] can be replaced
 *       by '*', thus we need to check s.substr(0, i-1) and p.substr(0, j).
 *       dp[i+1][j+1] = dp[i][j+1]
 */

bool isMatchDP(string s, string p) {
   int sLen = s.length();
   int pLen = p.length();
   vector<vector<bool> >dp(sLen+1, vector<bool>(pLen+1, false));

   for (int i = 0; i <= sLen; i++) {
      for (int j = 0; j <= pLen; j++) {
         int sIdx = i - 1, pIdx = j - 1;

         /* If both s and p are NULL, match. */
         if (sIdx < 0 && pIdx < 0) {
            dp[i][j] = true;
            continue;
         }
         /* If s is not NULL but p is NULL, never match. */
         if (pIdx < 0 && sIdx >= 0) {
            continue;
         }
         if (p[pIdx] == '*') {
            /* '*' can represent 0 match. */
            if (j >= 2) {
               dp[i][j] = dp[i][j] || dp[i][j-2];
            }
            /* '*' can represent 1 or more matches. */
            if (pIdx > 0 && sIdx >= 0 &&
                (p[pIdx-1] == s[sIdx] || p[pIdx-1] == '.')) {
               dp[i][j] = (dp[i][j] || dp[i-1][j]);
            }
         } else if (sIdx >= 0 && (p[pIdx] == s[sIdx] || p[pIdx] == '.')) {
            dp[i][j] = dp[i-1][j-1];
         }
      }
   }
   return dp[sLen][pLen];
}

string s = "aab";
string p = "c*a*b";

int main () {
   bool res = isMatch(s, p);
   bool res1 = isMatchDP(s, p);
   cout << "s: " << s << ", p: " << p << ", match? " << res << '\n';
   cout << "s: " << s << ", p: " << p << ", match? " << res1 << '\n';
   return 0;
}
