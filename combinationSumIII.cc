/*
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination
 * should be a unique set of numbers.
 *
 * Ensure that numbers within the set are sorted in ascending order.
 *
 * Example 1:
 * Input: k = 3, n = 7
 * Output:
 * [[1,2,4]]
 *
 * Example 2:
 * Input: k = 3, n = 9
 * Output:
 * [[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>

using namespace std;

void _combinationSum(vector<vector<int>>& res,
                     vector<int>& combination,
                     int target, int startPos, int allowedNum) {
   if (target == 0 && allowedNum == 0) {
      res.push_back(combination);
      return;
   }
   if (allowedNum == 0) {
      return;
   }

   for (int i = startPos; i <= 9; i++) {
      if (i > target) {
         return;
      }

      combination.push_back(i);
      _combinationSum(res, combination, target-i, i+1, allowedNum-1);
      combination.pop_back();
   }
}

vector<vector<int>> combinationSum3(int k, int n) {
   vector<vector<int>>res;
   vector<int> combination;
   _combinationSum(res, combination, n, 1, k);
   return res;
}

void _test() {
   int k = 3, n = 9;
   vector<vector<int> > res = combinationSum3(k, n);
   for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res[i].size(); j++) {
         cout << res[i][j] << " ";
      }
      cout << endl;
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
