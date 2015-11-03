/*
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process:
 * Starting with any positive integer, replace the number by the
 * sum of the squares of its digits, and repeat the process until
 * the number equals 1 (where it will stay), or it loops endlessly
 * in a cycle which does not include 1. Those numbers for which
 * this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 02 = 1
 */
#include <iostream>
#include <set>

using namespace std;

bool _isHappy(int n, set<int>& checkedNums) {
   int digit, newN;

   if (checkedNums.find(n) != checkedNums.end()) {
      return false;
   }

   checkedNums.insert(n);
   newN = 0;

   while (n) {
      digit = n % 10;
      n /= 10;
      newN += digit*digit;
   }

   return newN == 1 ? true: _isHappy(newN, checkedNums);
}

bool isHappy(int n) {
   set<int> checkedNums;
   return _isHappy(n, checkedNums);
}

void _test() {
   struct _tests {
      int input;
      bool expected;
   } tests[] = {
     {
        1,
        true,
     },
     {
        19,
        true,
     },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;

   for (int i = 0; i < testCases; i++) {
      bool got = isHappy(tests[i].input);

      if (got != tests[i].expected) {
         cout << tests[i].input << ", Expected: " << '\t' << tests[i].expected << '\t' << " Got: " << got << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
