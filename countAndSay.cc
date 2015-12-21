/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 */

#include <iostream>

using namespace std;

string countAndSay(int n) {
   string res = "1";
   if (n == 1) {
      return res;
   }

   for (int i = 2; i <= n; i++) {
      char currVal = res[0];
      int count = 0;
      string newString = "";

      for (auto& c: res) {
         if (c == currVal) {
            count++;
         } else {
            newString += to_string(count);
            newString += currVal;

            currVal = c;
            count = 1;
         }
      }
      newString += to_string(count);
      newString += currVal;

      res = newString;
   }
   return res;
}

void _test() {
   int n = 4;
   string res = countAndSay(n);
   cout << "n: " << n << ", res: " << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
