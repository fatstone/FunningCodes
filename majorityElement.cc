/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 */

#include <iostream>
#include <vector>

using namespace std;

int majorityElement1(vector<int>& nums) {
   int idx = 0, cnt = 1;

   for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == nums[idx]) {
         cnt++;
      } else {
         cnt--;
      }

      if (cnt == 0) {
         idx = i;
         cnt = 1;
      }
   }
   return nums[idx];
}

/* find kth largest element solution. */
void swap(int& a, int& b) {
   int tmp = a;
   a = b;
   b = tmp;
}

int partition(vector<int>& nums, int start, int end) {
   int pivotPos = start;
   int pivot = nums[pivotPos];

   start++;
   while (start <= end) {
      if (nums[start] >= pivot) {
         start++;
      } else if (nums[end] < pivot) {
         end--;
      } else {
         swap(nums[start], nums[end]);
         start++;
         end--;
      }
   }
   swap(nums[pivotPos], nums[end]);
   return end;
}

int _findKthLargest(vector<int>& nums, int start, int end, int k) {
   int pivot = partition(nums, start, end);
   if (pivot == k) {
      return nums[pivot];
   }
   if (pivot > k) {
      return _findKthLargest(nums, start, pivot-1, k);
   }
   return _findKthLargest(nums, pivot+1, end, k);
}

int findKthLargest(vector<int>& nums, int k) {
   return _findKthLargest(nums, 0, nums.size()-1, k-1);
}

int majorityElement(vector<int>& nums) {
   return findKthLargest(nums, nums.size()/2 + 1);
}

void _test() {
   vector<int> nums {1, 5, 3, 5, 5, 2, 5, 4, 5, 6, 5};
   //int major = majorityElement(nums);
   int major = majorityElement1(nums);
   cout << "major: " << major << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
