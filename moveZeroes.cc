/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void moveZeroes(vector<int>& nums) {
  int nonZeroPos = 0, zeroPos = 0;
  for (;;) {
     while (nums[zeroPos] != 0 && zeroPos < nums.size()) {
        zeroPos++;
     }
     nonZeroPos = zeroPos;
     while (nums[nonZeroPos] == 0 && nonZeroPos < nums.size()) {
        nonZeroPos++;
     }
     if (zeroPos == nums.size() || nonZeroPos == nums.size()) {
        break;
     }
     nums[zeroPos] = nums[nonZeroPos];
     nums[nonZeroPos] = 0;
  }
}

int main (int argc, char* argv[]) {
   vector<int> nums;
   nums.push_back(0);
   nums.push_back(1);
   nums.push_back(0);
   nums.push_back(3);
   nums.push_back(12);

   moveZeroes(nums);
   for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << endl;
   }

   return 0;
}
