/*
 * Given a string of numbers and operators, return all possible results
 * from computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> diffWaysToCompute(string input) {
   vector<int> res;

   for (int i = 0; i < input.length(); i++) {
      if (input[i] != '+' && input[i] != '-' && input[i] != '*') {
         continue;
      }
      vector<int> leftPart = diffWaysToCompute(input.substr(0, i));
      vector<int> rightPart = diffWaysToCompute(input.substr(i+1));

      for (auto& left: leftPart) {
         for (auto& right: rightPart) {
            if (input[i] == '+') {
               res.push_back(left+right);
            } else if (input[i] == '-') {
               res.push_back(left-right);
            } else {
               res.push_back(left*right);
            }
         }
      }
   }

   if (res.empty()) {
      res.push_back(stoi(input));
   }
   return res;
}

void _test() {
   string input = "2*3-4*5";
   vector<int> res = diffWaysToCompute(input);
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " ";
   }
   cout << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
