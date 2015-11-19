/*
 * Given an input string, reverse the string word by word.
 * 
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */

#include <iostream>
#include <string>

using namespace std;

void removeAdditionalSpace(string& s) {
   int pos = 0;
   if (s.length() == 0) {
      return;
   }

   for (int i = 0; i < s.length(); i++) {
      if (i + 1 < s.length() && s[i] == ' ' && s[i+1] == ' ') {
         continue;
      }
      if (pos == 0 && s[i] == ' ') {
         continue;
      }
      s[pos] = s[i];
      pos++;
   }

   if (s[pos-1] == ' ') {
      pos--;
   }

   s = s.substr(0, pos);
}

void _reverseWords(string& s, int start, int end) {
   while (start < end) {
      char tmp = s[start];
      s[start] = s[end];
      s[end] = tmp;

      start++;
      end--;
   }
}

void reverseWords(string &s) {
   int start = 0, i;

   removeAdditionalSpace(s);

   _reverseWords(s, 0, s.length()-1);
   for (i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
         _reverseWords(s, start, i-1);
         start = i+1;
      }
   }
   _reverseWords(s, start, i-1);
}

void _test() {
  struct _tests {
    string s;
    string r;
  } tests[] = {
     {
        "hello",
        "hello",
     },
     {
        " ",
        "",
     },
     {
        "1 ",
        "1",
     },
     {
        " 1",
        "1",
     },
     {
        "  1  ",
        "1",
     },
     {
        "hello world",
        "world hello",
     },
     {
        "",
        "",
     },
     {
        "a   b    c",
        "c b a",
     },
  };

  int testCases = sizeof(tests)/sizeof(struct _tests);
  bool pass = true;
  for (int i = 0; i < testCases; i++) {
     reverseWords(tests[i].s);

     if (tests[i].s != tests[i].r) {
        cout << "errors: " << i << '\t' << "got: " << tests[i].s << ", expected: " << tests[i].r << endl;
        pass = false;
     }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
