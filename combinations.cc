/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *   [3,4],
 *   [2,3],
 *   [1,2],
 *   [1,3],
 *   [1,4],
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

void _combine(vector<vector<int> >& res,
              vector<int>& combination,
              int start, int end, int k) {
   if (k == 0) {
      res.push_back(combination);
      return;
   }

   for (int i = start; i <= end; i++) {
      combination.push_back(i);
      _combine(res, combination, i+1, end, k-1);
      combination.pop_back();
   }
}

vector<vector<int> > combine(int n, int k) {
   vector<vector<int> >res;
   vector<int> combination;

   _combine(res, combination, 1, n, k);
   return res;
}

void _test() {
   vector<vector<int> >res = combine(4, 2);
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
