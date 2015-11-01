/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int removeElement(vector<int>& nums, int val) {
   int newIdx = 0;
   for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
         nums[newIdx] = nums[i];
         newIdx++;
      }
   }
   return newIdx;
}

int main (int argc, char* argv[]) {
   vector<int> nums;
   int val = 2;
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(1);

   int newLen = removeElement(nums, val);
   for (int i = 0; i < newLen; i++) {
      cout << nums[i] << endl;
   }
   return 0;
}
