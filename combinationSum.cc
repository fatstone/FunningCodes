/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 */

#include <iostream>
#include <vector>

using namespace std;

void _combinationSum(vector<int>& candidate,
                     vector<vector<int>>& res,
                     vector<int>& combination,
                     int target, int startPos) {
   if (target == 0) {
      res.push_back(combination);
      return;
   }

   for (int i = startPos; i < candidate.size(); i++) {
      if (candidate[i] > target) {
         return;
      }

      combination.push_back(candidate[i]);
      _combinationSum(candidate, res, combination, target-candidate[i], i);
      combination.pop_back();
   }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
   vector<vector<int>>res;
   vector<int> combination;

   sort(candidates.begin(), candidates.end());
   _combinationSum(candidates, res, combination, target, 0);
   return res;
}

void _test() {
   vector<int> candidates {2, 3, 6, 7};
   int target = 7;

   vector<vector<int> > res = combinationSum(candidates, target);
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
