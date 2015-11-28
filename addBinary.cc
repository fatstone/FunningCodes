/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
   int carry = 0;    
   int aIdx = a.length()-1, bIdx = b.length()-1;
   string res = "";

   while (aIdx >= 0 || bIdx >= 0) {
      int aVal = (aIdx < 0 || a[aIdx] == '0') ? 0 : 1;
      int bVal = (bIdx < 0 || b[bIdx] == '0') ? 0 : 1;
      int val = aVal + bVal + carry;

      carry = val/2;
      val %= 2;
      res.append(to_string(val));

      aIdx--; bIdx--;
   }
   if (carry) {
      res.append(to_string(carry));
   }

   reverse(res.begin(), res.end());
   return res;
}

void _test() {
   struct _tests {
      string a;
      string b;
      string expected;
   } tests[] = {
     {
        "1",
        "1",
        "10"
     },
     {
        "0",
        "1",
        "1"
     },
     {
        "0",
        "0",
        "0"
     },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;

   for (int i = 0; i < testCases; i++) {
      string got = addBinary(tests[i].a, tests[i].b);

      if (got != tests[i].expected) {
         cout << "Expected: " << '\t' << tests[i].expected << '\t' << " Got: " << got << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
