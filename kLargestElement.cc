/*
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 */

#include <iostream>
#include <vector>

using namespace std;

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

void _test() {
   vector<int> nums{3, 2, 1, 5, 6, 4};
   int k = findKthLargest(nums, 2);
   cout << "k = " << k << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
