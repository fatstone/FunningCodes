/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 * It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
   int pos = 0, dupNum = 0;
   for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i-1]) {
         dupNum++;
      } else {
         pos++;
         nums[pos] = nums[i];
      }
   }
   return nums.size()-dupNum;
}

int main (int argc, char* argv[]) {
   vector<int> nums;
   nums.push_back(1);
   nums.push_back(1);
   nums.push_back(2);

   int n = removeDuplicates(nums);
   for (int i = 0; i < n; i++) {
      cout << nums[i] << endl;
   }
   return 0;
}
