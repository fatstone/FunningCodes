/*
 * Given an array S of n integers, are there elements a, b, c in S
 * such that a + b + c = 0? Find all unique triplets in the array
 * which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 *
 *   A solution set is:
 *   (-1, 0, 1)
 *   (-1, -1, 2)
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * Some reference: https://en.wikipedia.org/wiki/3SUM
 */
vector<vector<int> > threeSum(vector<int>& nums) {
   vector<vector<int> > res;
   
   if (nums.size() < 3) {
      return res;
   }

   sort(nums.begin(), nums.end());
   for (int i = 0; i <= nums.size() - 3; i++) {
      int val = nums[i];
      int start, end;

      /* We have calculated this case by the previous one. */
      if (i > 0 && val == nums[i-1]) {
         continue;
      }

      start = i+1;
      end = nums.size()-1;
      while (start < end) {

         int left  = nums[start];
         int right = nums[end];
         if (val + left + right == 0) {
            vector<int> _res;
            _res.push_back(val);
            _res.push_back(left);
            _res.push_back(right);
            res.push_back(_res);

            while (left == nums[start] && start < nums.size()) {
               start++;
            }
            while (right == nums[end] && end >= 0) {
               end--;
            }
         } else if (val + left + right > 0) {
            end--;
         } else {
            start++;
         }
      }
   }
   return res;
}

int main (int argc, char* argv[]) {
   vector<int> nums;
   nums.push_back(-1);
   nums.push_back(0);
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(-1);
   nums.push_back(-4);
 
   vector<vector<int> > res = threeSum(nums);
   for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res[i].size(); j++) {
         cout << res[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}
