/*
 * Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 *
 * For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 */

#include <iostream>
#include <vector>

using namespace std;

void wiggleSort(vector<int>& nums) {
   if (nums.size() <= 1) {
      return;
   }

   for (int i = 0; i < nums.size() - 1; i++) {
      if ((i%2 == 0 && nums[i] > nums[i+1]) ||
          (i%2 && nums[i] < nums[i+1])) {
         swap(nums[i], nums[i+1]);
      }
   }
}

void _test() {
   vector<int> nums {3, 5, 2, 1, 6, 4};
   wiggleSort(nums);
   for (int i = 0; i < nums.size(); i++) {
      cout << nums[i] << " ";
   }
   cout << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
