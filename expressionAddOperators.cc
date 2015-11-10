/*
 * Given a string that contains only digits 0-9 and a target value,
 * return all possibilities to add binary operators (not unary) +, -,
 * or * between the digits so they evaluate to the target value.
 *
 * Examples: 
 * "123", 6 -> ["1+2+3", "1*2*3"] 
 * "232", 8 -> ["2*3+2", "2+3*2"]
 * "105", 5 -> ["1*0+5","10-5"]
 * "00", 0 -> ["0+0", "0-0", "0*0"]
 * "3456237490", 9191 -> []
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

void dfs(vector<string>& res, string num, string prefix, double sum, int target, double lastNum, set<string>& maps) {
   if (num.length() == 0 && sum == target) {
      res.push_back(prefix);
      return;
   }

   for (int i = 1; i <= num.length(); i++) {
      double cur = stod(num.substr(0, i).c_str());
      if (prefix.length() == 0) {
         dfs(res, num.substr(i), num.substr(0, i), cur, target, cur, maps);
      } else {
         dfs(res, num.substr(i), prefix + "+" + num.substr(0, i), sum+cur, target, cur, maps);
         dfs(res, num.substr(i), prefix + "-" + num.substr(0, i), sum-cur, target, -cur, maps);
         dfs(res, num.substr(i), prefix + "*" + num.substr(0, i), sum-lastNum+cur*lastNum, target, cur*lastNum, maps);
      }
      if (num.substr(0, 1) == "0") {
         break;
      }
   }
}

vector<string> addOperators(string num, int target) {
   vector<string> res;
   set<string> maps;
   dfs(res, num, "", 0, target, 0, maps);

   return res;
}

void _test() {
#if 0
   string num = "123";
   int target = 6;
#endif
#if 0
   string num = "123";
   int target = 6;
#endif
#if 1
   string num = "105";
   int target = 5;
#endif
   vector<string> res;

   res = addOperators(num, target);
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
