#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

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
 * dp[i][j] represents if s[0 ~ i+1] matches p[0 ~ j+1].
 */
bool isMatchDP(string s, string p) {
   int sLen = s.length();
   int pLen = p.length();
   vector<vector<bool> >dp(sLen+1, vector<bool>(pLen+1, false));

   // If both p and s is NULL, then match.
   dp[0][0] = true;

   for (int i = 0; i < sLen; i++) {
      for (int j = 0; j < pLen; j++) {
         if (p[j+1] != '*') {
            if (p[j] == '.' || s[i] == p[j]) {
               dp[i+1][j+1] = dp[i][j];
            }
         } else {
            dp[i+1][j+1] = dp[i+1][j];
            if (j - 1 >= 0) {
               dp[i+1][j+1] = (dp[i+1][j+1] || dp[i+1][j-1]);
            }
         }
      }
   }

   cout << "=== " << endl;
   for (int i = 0; i <= sLen; i++) {
      for (int j = 0; j <= pLen; j++) {
          cout << dp[i][j] << " ";
      }
      cout << '\n';
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
