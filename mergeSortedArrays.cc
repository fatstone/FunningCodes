/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to
 * hold additional elements from nums2. The number of elements initialized in nums1 and
 * nums2 are m and n respectively.
 */
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int idx1 = m-1;
   int idx2 = n-1;
   int idx = m+n-1;
   
   while (idx1 >= 0 && idx2 >= 0) {
      if (nums1[idx1] > nums2[idx2]) {
         nums1[idx] = nums1[idx1];
         idx1--;
      } else {
         nums1[idx] = nums2[idx2];
         idx2--;
      }
      idx--;
   }
   while (idx2 >= 0) {
      nums1[idx] = nums2[idx2];
      idx--;
      idx2--;
   }
}

int main (int argc, char* argv[]) {
   vector<int> nums1;
   vector<int> nums2;
   nums1.push_back(1);
   nums1.push_back(2);
   nums1.push_back(3);
   nums1.push_back(0);
   nums1.push_back(0);
   nums1.push_back(0);

   nums2.push_back(2);
   nums2.push_back(5);
   nums2.push_back(6);

   merge(nums1, 3, nums2, 3);

   for (int i = 0; i < nums1.size(); i++) {
      cout << nums1[i] << '\n';
   }
   return 0;
}
