/*
 * After robbing those houses on that street, the thief has found himself
 * a new place for his thievery so that he will not get too much attention.
 * This time, all houses at this place are arranged in a circle. That means
 * the first house is the neighbor of the last one. Meanwhile, the security
 * system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight without
 * alerting the police.
 */

#include <iostream>
#include <vector>

using namespace std;

int _rob(vector<int>& nums, int start, int end) {
   int prevMax, prevPrevMax;

   prevPrevMax = nums[start];
   prevMax = max(nums[start], nums[start+1]);

   for (int i = start+2; i <= end; i++) {
      int currMax = max(prevMax, prevPrevMax + nums[i]);
      prevPrevMax = prevMax;
      prevMax = currMax;
   }
   return prevMax;
}

int rob(vector<int>& nums) {
   if (nums.size() == 0) {
      return 0;
   }
   if (nums.size() == 1) {
      return nums[0];
   }
   if (nums.size() == 2) {
      return max(nums[0], nums[1]);
   }

   return max(_rob(nums, 1, nums.size()-1),
              _rob(nums, 0, nums.size()-2));
}

void _test() {
   vector<int> nums {2, 1, 1, 2};
   int maxVal = rob(nums);
   cout << "max value: " << maxVal << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
