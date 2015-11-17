/*
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isIsomorphic(string s, string t) {
    vector<char> maps(128, -1);
    vector<char> reverseMaps(128, -1);
    
    for (int i = 0; i < s.length(); i++) {
        if (maps[s[i]] == -1) {
           maps[s[i]] = t[i];
        } else if (maps[s[i]] != t[i]) {
           return false;
        }

        if (reverseMaps[t[i]] == -1) {
           reverseMaps[t[i]] = s[i];
        } else if (reverseMaps[t[i]] != s[i]) {
           return false;
        }
    }
    return true;
}

void _test() {
  struct _tests {
    string s;
    string t;
    bool   expected;
  } tests[] = {
     {
        "ab",
        "aa",
        false,
     },
  };

  int testCases = sizeof(tests)/sizeof(struct _tests);
  bool pass = true;
  for (int i = 0; i < testCases; i++) {
     bool got = isIsomorphic(tests[i].s, tests[i].t);
     if (got != tests[i].expected) {
      cout << "errors: " << i << '\t' << tests[i].s << '\t' << tests[i].t << endl;
      pass = false;
    }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;

}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
