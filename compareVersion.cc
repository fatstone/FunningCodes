/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string s) {
   int idx = 0, begin = 0;
   vector<int> res;

   while (idx < s.length()) {
      if (s[idx] == '.') {
         res.push_back(atoi(s.substr(begin, idx-begin).c_str()));
         idx++;
         begin = idx;
      } else if (s[idx] != '.') {
         idx++;
      }
   }
   if (begin < s.length()) {
      res.push_back(atoi(s.substr(begin).c_str()));
   }
   return res;
}

int compareVersion(string version1, string version2) {
   vector<int> v1 = split(version1);
   vector<int> v2 = split(version2);

   int len = max(v1.size(), v2.size());
   for (int i = 0; i < len; i++) {
      if (i >= v1.size()) {
         if (v2[i] > 0) {
            return -1;
         } else {
            continue;
         }
      }
      if (i >= v2.size()) {
         if (v1[i] > 0) {
            return 1;
         } else {
            continue;
         }
      }
      if (v1[i] < v2[i]) {
         return -1;
      }
      if (v1[i] > v2[i]) {
         return 1;
      }
   }
   return 0;
}

void _test() {
   struct _tests {
      string version1;
      string version2;
      int    expected;
   } tests[] = {
       {
          "1",
          "0",
          1
       },
       {
          "01",
          "1",
          0
       },
       {
          "0",
          "1",
          -1
       },
       {
          "0.1",
          "0.2",
          -1
       },
       {
          "0.1.1",
          "0.1.2",
          -1
       },
       {
          "1.0",
          "1",
          0
       },

   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;

   for (int i = 0; i < testCases; i++) {
      int got = compareVersion(tests[i].version1, tests[i].version2);
      if (got != tests[i].expected) {
         cout << "v1: " << tests[i].version1 << ", v2: " << tests[i].version2 << ", got: " << got << ", expected: " << tests[i].expected << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
