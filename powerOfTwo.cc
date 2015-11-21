/*
 * Given an integer, write a function to determine if it is a power of two.
 */

#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
   if (n == 1 || n == 2) {
      return true;
   }
   if (n <= 0 || n % 2 ) {
      return false;
   }
   return isPowerOfTwo(n/2);
}

void _test() {
   struct _tests {
      int n;
      bool   expected;
   } tests[] = {
      {
         0,
         false,
      },
      {
         -1,
         false,
      },
      {
         1,
         true,
      },
      {
         3,
         false,
      },
      {
         4,
         true,
      },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;
   for (int i = 0; i < testCases; i++) {
      bool got = isPowerOfTwo(tests[i].n);
      if (got != tests[i].expected) {
         cout << "errors: " << i << '\t' << tests[i].n << endl;
         pass = false;
      }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;


}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
