/*
 * Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.
 * For example,
 * 123 -> "One Hundred Twenty Three"
 * 12345 -> "Twelve Thousand Three Hundred Forty Five"
 * 1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 */

#include <iostream>
#include <unordered_map>

using namespace std;

string _convert(int num) {
   unordered_map<int, string> maps {{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
                                      {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"}, {11, "Eleven"},
                                      {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"},
                                      {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"},
                                      {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
   if (maps.find(num) == maps.end()) {
      return "";
   }
   return maps.find(num)->second;
}
     
string convert(int num, bool ignoreZero) {
   if (num == 0 && ignoreZero) {
      return "";
   }

   string res = "";
   if (num > 99) {
      res += _convert(num/100) + " Hundred";
      num %= 100;
      if (num == 0) {
         return res;
      }
   }
   if (num > 19) {
      res += res.length() > 0 ? " " + _convert(10*(num/10)) :
                                      _convert(10*(num/10));
      num %= 10;
      if (num == 0) {
         return res;
      }
   }
   res += res.length() > 0 ? " " + _convert(num) : 
                                   _convert(num);
   return res;
}

string numberToWords(int num) {
   int billion, million, thousand, hundred;

   billion = num/1000000000;
   num %= 1000000000;

   million = num/1000000;
   num %= 1000000;

   thousand = num/1000;
   num %= 1000;

   hundred = num;

   string billionStr = convert(billion, true);
   string millionStr = convert(million, true);
   string thousandStr = convert(thousand, true);
   string hundredStr = convert(hundred, billionStr.length() != 0 ||
                                        millionStr.length() != 0 || 
                                        thousandStr.length() != 0);

   string res = "";
   if (billionStr.length() > 0) {
      res += billionStr + " Billion";
   }
   if (millionStr.length() > 0) {
      res += res.length() > 0 ? " " + millionStr + " Million" :
                                millionStr + " Million";
   }
   if (thousandStr.length() > 0) {
      res += res.length() > 0 ? " " + thousandStr + " Thousand" :
                                thousandStr + " Thousand";
   }
   if (hundredStr.length() > 0) {
      res += res.length() > 0 ? " " + hundredStr :
                                hundredStr;
   }
   return res;
}

void _test(int num) {
  // int num = 1234567891;
  // int num = 1000;
   string res = numberToWords(num);
   cout << num << '\t' << res << endl;
}

int main (int argc, char* argv[]) {
   _test(atoi(argv[1]));
   return 0;
}
