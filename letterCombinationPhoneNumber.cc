/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given by function getString.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getString(char c) {
    switch (c) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return "";
    }
}

void _letterCombinations(string digits, string prefix, vector<string>& res) {
   if (digits.length() == 0) {
      res.push_back(prefix);
      return;
   }

   string letters = getString(digits[0]);
   string newDigits = digits.substr(1);

   for (int j = 0; j < letters.length(); j++) {
      string newPrefix = prefix + letters[j];
      _letterCombinations(newDigits, newPrefix, res);
   }
}

vector<string> letterCombinations(string digits) {
   vector<string> res;

   _letterCombinations(digits, "", res);
   return res;
}

void _test() {
   string digits = "23";
   vector<string> res;

   res = letterCombinations(digits);
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << '\n';
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
