/*
 * Given a pattern and a string str, find if str follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 *
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> split(string s) {
   int idx = 0, begin = 0;
   vector<string> res;
   
   while (idx < s.length()) {
      if (s[idx] == ' ') {
         res.push_back(s.substr(begin, idx-begin));
         idx++;
         begin = idx;
      } else if (s[idx] != ' ') {
         idx++;
      }
   }
   if (begin < s.length()) {
      res.push_back(s.substr(begin));
   }
   return res;
}

bool wordPattern(string pattern, string str) {
   unordered_map<char, string> p2sMaps;
   unordered_map<string, char> s2pMaps;
   vector<string> tokens = split(str);

   if (tokens.size() != pattern.length()) {
      return false;
   }
   
   for (int i = 0; i < pattern.length(); i++) {
      if (p2sMaps.find(pattern[i]) == p2sMaps.end()) {
         p2sMaps[pattern[i]] = tokens[i];
      } else if (p2sMaps[pattern[i]] != tokens[i]) {
         return false;
      }
   }

   for (int i = 0; i < pattern.length(); i++) {
      if (s2pMaps.find(tokens[i]) == s2pMaps.end()) {
         s2pMaps[tokens[i]] = pattern[i];
      } else if (s2pMaps[tokens[i]] != pattern[i]) {
         return false;
      }
   }
   return true;
}

void _test() {
   struct _tests {
      string pattern;
      string str;
      bool   expected;
   } tests[] = {
      {
         "abba",
         "dog cat cat dog",
         true
      },
      {
         "acba",
         "dog cat cat dog",
         false
      },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;
   for (int i = 0; i < testCases; i++) {
      bool got = wordPattern(tests[i].pattern, tests[i].str);
      if (got != tests[i].expected) {
         cout << "errors: " << i << '\t' << tests[i].pattern << '\t' << tests[i].str << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
