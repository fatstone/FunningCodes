/*
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * https://en.wikipedia.org/wiki/Roman_numerals
 */
#include <iostream>
#include <vector>

using namespace std;

void appendRoman(string& res, int digit, int scale) {
   char symbols[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
   int pos = -1;

   if (digit == 0) {
      return;
   }
   switch(scale) {
      case 1000:
         pos = 6; /* 'M' */
         break;
      case 100:
         pos = 4; /* 'C' */
         break;
      case 10:
         pos = 2; /* 'X' */
         break;
      default:
         pos = 0; /* 'I' */
   }

   if (digit <= 3) {
      res.append(digit, symbols[pos]);
   } else if (digit == 4) {
      res.append(1, symbols[pos]);
      res.append(1, symbols[pos+1]);
   } else if (digit == 5) {
      res.append(1, symbols[pos+1]);
   } else if (digit <= 8) {
      res.append(1, symbols[pos+1]);
      res.append(digit-5, symbols[pos]);
   } else {
      res.append(1, symbols[pos]);
      res.append(1, symbols[pos+2]);
   }
}

/*
 * Symbol	Value
 * I	1
 * V	5
 * X	10
 * L	50
 * C	100
 * D	500
 * M	1,000
 */
string intToRoman(int num) {
   string res;   
   int scale = 1000, digit;

   while (scale > 0) {
      digit = num/scale;
      num %= scale;

      appendRoman(res, digit, scale);
      scale /= 10;
   }
   return res;
}

int charToDigit (char c) {
   int res = 0;
   switch (c) {
       case 'I':
           res = 1;
           break;
       case 'V':
           res = 5;
           break;
       case 'X':
           res = 10;
           break;
       case 'L':
           res = 50;
           break;
       case 'C':
           res = 100;
           break;
       case 'D':
           res = 500;
           break;
       case 'M':
           res = 1000;
           break;
   }
   return res;
}

int romanToInt(string s) {
   int res = 0;
   for (int i = 0; i < s.length(); i++) {
      res += charToDigit(s[i]);
      if (i > 0 && charToDigit(s[i-1]) < charToDigit(s[i])) {
         res -= 2*charToDigit(s[i-1]);
      }
   }
   return res;
}

void _test() {
   struct _tests {
      int input;
      int output;
   } tests[] = {
     {
        1,
        1,
     },
     {
        125,
        125,
     },
     {
        917,
        917,
     },
   };

   int testCases = sizeof(tests)/sizeof(struct _tests);
   bool pass = true;

   for (int i = 0; i < testCases; i++) {
      string res = intToRoman(tests[i].input);
      int got = romanToInt(res);

      if (got != tests[i].output) {
         cout << "Expected: " << '\t' << tests[i].output << '\t' << " Got: " << got << endl;
         pass = false;
      }
   }
   if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
