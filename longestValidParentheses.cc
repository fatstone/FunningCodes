/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

#include <iostream>
#include <vector>

using namespace std;

/* Solution 1. */
int longestValidParentheses(string s) {
   int leftParenthesses = 0, startPos = -1, res = 0;
   int rightParenthesses = 0, endPos = s.length();

   /* Scan from left to right. */
   for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
         leftParenthesses++;
      } else {
         leftParenthesses--;

         if (leftParenthesses < 0) {
            startPos = i;
            leftParenthesses = 0;
         } else if (leftParenthesses == 0) {
            res = max(res, i - startPos);
         }
      }
   }

   /* Scan from right to left. */
   for (int i = s.length()-1; i >= 0; i--) {
      if (s[i] == ')') {
         rightParenthesses++;
      } else {
         rightParenthesses--;

         if (rightParenthesses < 0) {
            endPos = i;
            rightParenthesses = 0;
         } else if (rightParenthesses == 0) {
            res = max(res, endPos - i);
         }
      }
   }
   return res;
}

/* Solution 2. */
int longestValidParenthesesDP(string s) {
   int len = s.length();
   int res = 0;

   if (len < 2) {
      return 0;
   }
   
   /* dp[i] represents length of valid "()" pairs starting from i. */
   vector<int> dp(len, 0);

   for (int i = len-2; i >= 0; i--) {
      if (s[i] == ')') {
         continue;
      }

      int matchPos = dp[i+1] /* Skip valid "()" pairs */ +
                     i+1;
      if (matchPos < len && s[matchPos] == ')') {
         dp[i] = 2+dp[i+1];

         if (matchPos+1 < len) {
            dp[i] += dp[matchPos+1];
         }

         res = max(res, dp[i]);
      }
   }
   return res;
}

void _test() {
   struct _tests {
      string s;
      int    expected;
   } tests[] = {
       {
          "(()",
          2
       },
       {
          ")()())",
          4
       },
       {
          ")(",
          0
       },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;

   for (int i = 0; i < testCases; i++) {
      int got = longestValidParentheses(tests[i].s);
      if (got != tests[i].expected) {
         cout << "Testcase: " << tests[i].s << '\t' << "Got: " << got << ", expected: " << tests[i].expected << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
