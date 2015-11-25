/*
 * You are a professional robber planning to rob houses along a street.
 * Each house has a certain amount of money stashed, the only constraint
 * stopping you from robbing each of them is that adjacent houses have
 * security system connected and it will automatically contact the police
 * if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money
 * of each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
   int prevMax, prevPrevMax;

   if (nums.size() == 0) {
      return 0;
   }
   if (nums.size() == 1) {
      return nums[0];
   }
   if (nums.size() == 2) {
      return max(nums[0], nums[1]);
   }

   prevPrevMax = nums[0];
   prevMax = max(nums[1], nums[0]);

   for (int i = 2; i < nums.size(); i++) {
      int currMax = max(prevMax, prevPrevMax + nums[i]);
      prevPrevMax = prevMax;
      prevMax = currMax;
   }
   return prevMax;
}

void _test() {
   //vector<int> nums {1, 3, 1};
   vector<int> nums {2, 1, 1, 2};
   int maxVal = rob(nums);
   cout << "max value: " << maxVal << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
