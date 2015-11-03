/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
   int start = 0, end = nums.size()-1, mid;   
   
   while (start <= end) {
      mid = start + (end-start)/2;
      if (nums[mid] == target) {
         return mid;
      }
      if (nums[start] == target) {
         return start;
      }
      if (nums[end] == target) {
         return end;
      }
      if (nums[start] < nums[mid]) {
         if (nums[start] < target && target < nums[mid]) {
            end = mid - 1;
         } else {
            start = mid + 1;
         }
      } else {
         if (nums[mid] < target && target < nums[end]) {
            start = mid + 1;
         } else {
            end = mid - 1;
         }
      }
   }
   return -1;
}

int main (int argc, char* argv[]) {
   vector<int> nums;
#if 0
   nums.push_back(4);
   nums.push_back(5);
   nums.push_back(6);
   nums.push_back(7);
   nums.push_back(0);
   nums.push_back(1);
   nums.push_back(2);
#endif
   nums.push_back(1);
   int target = 1;

   int res = search(nums, target);
   cout << "target: " << target <<", index: " << res << ", actual val: " << nums[res] << endl;
   return 0;
}
