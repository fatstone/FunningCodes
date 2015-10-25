/*
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * The challenge here is how we handle '*'. Overall, there are two cases
 * regarding '*': 1) '*' represents 0 character, 2) '*' represents one
 * or more characters.
 *
 * So, once we meet p[j] == '*', let's ignore this '*' by keep scanning
 * from p[j+1], which represents case 1. However, '*' might match some
 * character(s). So, when we ignore '*', we need to remember its position
 * and s current position accordingly. Once our assumption ('*' matches
 * 0 character) fails, we reset current p position to what we remembered,
 * and s position that was remembered plus one, and keep scanning.
 */
bool isMatch(string s, string p) {
   int sPos = 0, pPos = 0;
   int starSPos = -1, starPPos = -1;

   while (sPos < s.length()) {
      
      if (s[sPos] == p[pPos] || p[pPos] == '?') {
         sPos++; pPos++;
      } else if (p[pPos] == '*') {
         starPPos = pPos;
         starSPos = sPos;
         /* Let's assume '*' matches 0 character, so move forward pPos. */
         pPos++;
      } else if (starPPos > -1 && starPPos < p.length()) {
         pPos = starPPos + 1;
         /*
          * It turns out '*' we remembered at least matches one character,
          * thus move forward starSPos by one.
          */
         starSPos++;
         sPos = starSPos;
      } else {
         return false;
      }
   }
   while (pPos < p.length() && p[pPos] == '*') {
      pPos++;
   }
   return pPos == p.length();
}

/*
 * DP solution:
 *   1) if s[i] matches p[j], dp[i][j] = dp[i-1][j-1]
 *   2) if p[j] is '*':
 *      a) dp[i][j-1] represents case that '*' creates 0 characters;
 *      b) dp[i-1][j] represents case that '*' replaces s[i]; 
 *      Thus dp[i][j] = dp[i][j-1] || dp[i-1][j];
 */
bool isMatchDP(string s, string p) {
   int sLen = s.length();
   int pLen = p.length();
   vector<vector<bool> >dp(sLen+1, vector<bool>(pLen+1, false));

   /* Init case: match if s == NULL and p == NULL. */
   dp[0][0] = true;

   /* Init case: if s == NULL, match iff all p characters are '*'. */
   for (int i = 1; i <= pLen; i++) {
      dp[0][i] = dp[0][i-1] && (p[i-1] == '*');
   }

   for (int i = 1; i <= sLen; i++) {
      for (int j = 1; j <= pLen; j++) {
         int sIdx = i-1, pIdx = j-1;

         if (s[sIdx] == p[pIdx] || p[pIdx] == '?') {
            dp[i][j] = dp[i-1][j-1];
         } else if (p[pIdx] == '*') {
            dp[i][j] = dp[i][j-1] || dp[i-1][j];
         }
      }
   }
   return dp[sLen][pLen];
}

void _test() {
  struct _tests {
    string s1;
    string s2;
    bool   expected;
  } tests[] = {
    {
      "aa",
      "a",
      false,
    },
    {
      "",
      "*",
      true,
    },
    {
      "aa",
      "aa",
      true,
    },
    {
      "aaa",
      "aa",
      false,
    },
    {
      "aa",
      "*",
      true,
    },
    {
      "aa",
      "a*",
      true,
    },
    {
      "ab",
      "?*",
      true,
    },
    {
      "aab",
      "c*a*b",
      false,
    },
    {
      "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
      "a*******b",
      false,
    },
    {
      "hi",
      "*?",
      true,
    },
    {
      "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
      "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb",
      false,
    },
  };

  int testCases = sizeof(tests)/sizeof(struct _tests);
  bool pass = true;
  for (int i = 0; i < testCases; i++) {
    bool got = isMatch(tests[i].s1, tests[i].s2);
    //bool got = isMatchDP(tests[i].s1, tests[i].s2);
    if (got != tests[i].expected) {
      cout << "errors: " << i << '\t' << tests[i].s1 << '\t' << tests[i].s2 << endl;
      pass = false;
    }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
  _test();
  return 0;
}
