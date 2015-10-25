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

   dp[0][0] = true;
   for (int i = 1; i <= pLen; i++) {
      if (i >= 2 && p[i-1] == '*') {
         dp[0][i] = dp[0][i-2];
      }
   }

   for (int i = 1; i <= sLen; i++) {
      for (int j = 1; j <= pLen; j++) {
         int sIdx = i - 1, pIdx = j - 1;

         if (p[pIdx] == '*') {
            /* '*' can represent 0 match. */
            if (j >= 2) {
               dp[i][j] = dp[i][j] || dp[i][j-2];
            }
            /* '*' can represent 1 or more matches. */
            if ((p[pIdx-1] == s[sIdx] || p[pIdx-1] == '.')) {
               dp[i][j] = (dp[i][j] || dp[i-1][j]);
            }
         } else if ((p[pIdx] == s[sIdx] || p[pIdx] == '.')) {
            dp[i][j] = dp[i-1][j-1];
         }
      }
   }
   return dp[sLen][pLen];
}

string s = "aa";
string p = "a*";

void _test() {
   struct _tests {
      string s1;
      string s2;
      bool   expected;
   } tests[] = {
     {
        "a",
        "ab*a",
        false,
     },
     {
        "aab",
        "c*a*a*b",
        true,
     },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;

   for (int i = 0; i < testCases; i++) {

      //bool got = isMatch(tests[i].s1, tests[i].s2);
      bool got = isMatchDP(tests[i].s1, tests[i].s2);
      if (got != tests[i].expected) {
         cout << "errors: " << i << '\t' << tests[i].s1 << '\t' << tests[i].s2 << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main () {
   _test();
   return 0;
}
