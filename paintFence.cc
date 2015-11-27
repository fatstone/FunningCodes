/*
 * There is a fence with n posts, each post can be painted with one of the k colors.
 *
 * You have to paint all the posts such that no more than two adjacent fence posts have the same color.
 *
 * Return the total number of ways you can paint the fence.
 */

#include <iostream>

using namespace std;

int numWays(int n, int k) {
   if (n == 0 || n == 1) {
      return n*k;
   }

   int prevPrev = k;
   int prev = k*(k-1) /* Different color with previous post. */ +
              k;      /* Same color with previous post. */ 
   int curr = 0;
   for (int i = 3; i <= n; i++) {
      curr = prev*(k-1)  /* Different color with previous post. */ +
             prevPrev*(k-1); /* Different color with previous previous post. */
      prevPrev = prev;
      prev = curr;
   }

   return curr;
}

void _test() {
   struct _tests {
      int n;
      int k;
      int expected;
   } tests[] = {
      {
         3,
         3,
         24
      },
      {
         4,
         1,
         0
      },
      {
         5,
         0,
         0
      },
      {
         0,
         9,
         0
      },
      {
         1,
         2,
         2
      },
      {
         3,
         2,
         6
      },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;
   for (int i = 0; i < testCases; i++) {
      int got = numWays(tests[i].n, tests[i].k);
      if (got != tests[i].expected) {
         cout << "errors: " << i << '\t' << tests[i].n << '\t' << tests[i].k << endl;
         pass = false;
      }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
