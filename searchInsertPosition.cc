/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
   int start = 0, end = nums.size();
   while (start < end) {
      int mid = start + (end-start)/2;
      if (nums[mid] <= target) {
         start = mid+1;
      } else {
         end = mid;
      }
   }
   if (start >= 1 && nums[start-1] == target) {
      return start-1;
   }
   return start;
}

void _test() {
#if 0
   vector<int> nums{1, 3, 5, 6};
   int target = 0;
#endif
   vector<int> nums{1};
   int target = 0;

   int res = searchInsert(nums, target);
   cout << "res: " << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
