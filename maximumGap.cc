/*
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(vector<int>& nums, int k) {
   vector<int> counts(k, 0);
   vector<int> res(nums.size(), 0);

   for (int i = 0; i < nums.size(); i++) {
      counts[nums[i]]++;
   }
   for (int i = 1; i < counts.size(); i++) {
      counts[i] += counts[i-1];
   }
   for (int i = nums.size()-1; i >= 0; i--) {
      counts[nums[i]]--;
      res[counts[nums[i]]] = nums[i];
   }
   return res;
}

vector<int> radixSort(vector<int>& nums) {
   vector<int> res(nums.size(), 0);
   int maxVal = INT_MIN, base = 1;
   
   for (int i = 0; i < nums.size(); i++) {
      maxVal = max(maxVal, nums[i]); 
   }

   while (maxVal > 0) {
      vector<int> counts(10, 0);

      for (int i = 0; i < nums.size(); i++) {
         int digit = (nums[i]/base) % 10;
         counts[digit]++;
      }

      for (int i = 1; i < counts.size(); i++) {
         counts[i] += counts[i-1];
      }

      for (int i = nums.size()-1; i >= 0; i--) {
         int digit = (nums[i]/base) % 10;
         counts[digit]--;
         res[counts[digit]] = nums[i];
      }

      nums = res;

      maxVal /= 10;
      base *= 10;
   }
   return res;
}

int maximumGap(vector<int>& nums) {
   vector<int> res = radixSort(nums);
   int maxGap = INT_MIN;
   for (int i = 1; i < res.size(); i++) {
      int gap = abs(res[i] - res[i-1]);
      maxGap = max(maxGap, gap);
   }
   return nums.size() <= 1 ? 0 : maxGap;
}

void _test() {
   vector<int> nums;
   nums.push_back(2);
   nums.push_back(2);
   nums.push_back(1);
   nums.push_back(3);
   nums.push_back(2);
   nums.push_back(100);
   nums.push_back(3);
   nums.push_back(10);

   vector<int> csorted = countingSort(nums, 11);
   for (int i = 0; i < csorted.size(); i++) {
      cout << csorted[i] << endl;
   }

   cout << "radix: " << endl;
   vector<int> rsorted = radixSort(nums);
   for (int i = 0; i < rsorted.size(); i++) {
      cout << rsorted[i] << endl;
   }

   int maxGap = maximumGap(nums);
   cout << "max gap: " << maxGap << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
