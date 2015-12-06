/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
   vector<int> res(2, -1);
   int start = 0, end = nums.size();

   while (start < end) {
      int mid = start + (end-start)/2;
      if (nums[mid] < target) {
         start = mid+1;
      } else {
         end = mid;
      }
   }

   if (nums[start] != target) {
      return res;
   }

   res[0] = start;

   end = nums.size();
   while (start < end) {
      int mid = start + (end-start)/2;
      if (nums[mid] <= target) {
         start = mid+1;
      } else {
         end = mid;
      }
   }
   res[1] = start-1;

   return res;
}

void _test() {
#if 0
   vector<int> nums{5, 7, 7, 8, 8, 10};
   int target = 8;
#endif
   vector<int> nums{2, 2};
   int target = 2;

   vector<int> res = searchRange(nums, target);
   cout << "[" << res[0] << ", " << res[1] << "];" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
