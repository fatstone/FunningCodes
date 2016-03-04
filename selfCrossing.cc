/*
 * You are given an array x of n positive numbers. You start at point (0,0)
 * and moves x[0] metres to the north, then x[1] metres to the west, x[2]
 * metres to the south, x[3] metres to the east and so on. In other words,
 * after each move your direction changes counter-clockwise.
 *
 * Write a one-pass algorithm with O(1) extra space to determine, if your
 * path crosses itself, or not.
 *
 * Example 1:
 * Given x = [2, 1, 1, 2],
 * ┌───┐
 * │   │
 * └───┼──>
 *     │
 *
 * Return true (self crossing)
 *
 * Example 2:
 * Given x = [1, 2, 3, 4],
 * ┌──────┐
 * │      │
 * │
 * │
 * └────────────>
 *
 * Return false (not self crossing)
 * 
 * Example 3:
 * Given x = [1, 1, 1, 1],
 * ┌───┐
 * │   │
 * └───┼>
 *
 * Return true (self crossing)
 */

#include <iostream>
#include <vector>

using namespace std;

bool isSelfCrossing(vector<int>& x) {
    for (int i = 3; i < x.size(); i++) {

        if (x[i-3] >= x[i-1] && x[i] >= x[i-2]) {
            return true;
        }
        
        if (i >= 5) {
            int x6 = x[i], x5 = x[i-1], x4 = x[i-2], x3 = x[i-3], x2 = x[i-4], x1 = x[i-5];

            if (x3 >= x1 &&
                x3 >= x5 &&
                x1+x5 >= x3 &&
                x4 >= x2 &&
                x2+x6 >= x4 &&
                x1+x5 >= x3) {
                return true;
            }
        }
        
        if (i >= 4) {
            int x5 = x[i], x4 = x[i-1], x3 = x[i-2], x2 = x[i-3], x1 = x[i-4];
            if (x2 == x4 &&
                x3 <= x1 + x5) {
                cout << "3" << endl;
                return true;
            }
        }
    }
    return false;
}

void _test() {
  struct _tests {
    vector<int> x;
    bool   expected;
  } tests[] = {
    {
      {2, 1, 1, 2},
      true,
    },
    {
      {1, 2, 3, 4},
      false,
    },
    {
      {1, 1, 1, 1},
      true,
    },
    {
      {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1},
      false,
    },

  };

  int testCases = sizeof(tests)/sizeof(struct _tests);
  bool pass = true;
  for (int i = 0; i < testCases; i++) {
    bool got = isSelfCrossing(tests[i].x);
    if (got != tests[i].expected) {
      cout << "errors: " << i << '\t' << "got: " << got << '\t' << "expected: " << tests[i].expected << endl;
      pass = false;
    }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
  _test();
  return 0;
}
