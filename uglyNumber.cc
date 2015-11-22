/*
 * Write a program to check whether a given number is an ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 *
 * Note that 1 is typically treated as an ugly number.
 */

#include <iostream>

using namespace std;

bool isUgly(int num) {
   if (num <= 0) {
      return false;
   }
   if (num == 1) {
      return true;
   }
   for (;;) {
      if (num == 0 || num == 1) {
         return true;
      }

      if (num % 2 == 0) {
         num /= 2;
      } else if (num % 3 == 0) {
         num /= 3;
      } else if (num % 5 == 0) {
         num /= 5;
      } else {
         break;
      }
   }
   return false;
}

void _test() {
   struct _tests {
     int  num;
     bool expected;
   } tests[] = {
    {
       1,
       true,
    },
    {
       7,
       false,
    },
    {
       2,
       true,
    },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;
   for (int i = 0; i < testCases; i++) {
      bool got = isUgly(tests[i].num);
      if (got != tests[i].expected) {
         cout << "errors: " << i << '\t' << tests[i].num << '\t' << got << '\t' << tests[i].expected << endl;
         pass = false;
      }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
