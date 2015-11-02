/*
 * Given an array S of n integers, find three integers in S such that
 * the curSum is closest to a given number, target. Return the curSum of the
 * three integers. You may ascurSume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The curSum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
   int diff = INT_MAX, sum = INT_MAX;
   sort(nums.begin(), nums.end());

   for (int i = 0; i <= nums.size() - 3; i++) {
      int start = i+1, end = nums.size()-1;

      while (start < end) {
         int curSum = nums[i] + nums[start] + nums[end];
         if (abs(curSum-target) < diff) {
            diff = abs(curSum-target);
            sum = curSum;
         }
         if (curSum == target) {
            return curSum;
         } else if (curSum > target) {
            end--;
         } else {
            start++;
         }
      }
   }
   return sum;
}

int main (int argc, char* argv[]) {
   vector<int> nums;
   nums.push_back(-1);
   nums.push_back(2);
   nums.push_back(1);
   nums.push_back(-4);
 
   int target = 1;
   int res = threeSumClosest(nums, target);
   cout << "res: " << res << endl;
   return 0;
}
