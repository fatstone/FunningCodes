/*
 * Given an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
   void swap(int& a, int& b) {
      int tmp = a;
      a = b;
      b = tmp;
   }
public:
   int firstMissingPositive(vector<int>& nums) {
      int pos = 0, targetIdx = 0;       

      while (pos < nums.size()) {
         targetIdx = nums[pos] - 1;

         if (targetIdx < 0 ||
             targetIdx >= nums.size() ||
             pos == targetIdx ||
             nums[pos] == nums[targetIdx]) {
            pos++;
            continue;
         }

         swap(nums[pos], nums[targetIdx]);
      }

      for (pos = 0; pos < nums.size(); pos++) {
         if (nums[pos] != pos+1) {
            break;
         }
      }
      return pos+1;
   }
};

int main (int argc, char* argv[]) {
   vector<int> nums;
#if 0
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(0);
#endif
#if 0
   nums.push_back(3);
   nums.push_back(4);
   nums.push_back(-1);
   nums.push_back(1);
#endif
   nums.push_back(4);
   nums.push_back(9);
   nums.push_back(1);
   nums.push_back(0);
   nums.push_back(2);
   nums.push_back(3);
   Solution *s = new Solution();
   int res = s->firstMissingPositive(nums);
   cout << "miss: " << res << endl;
   return 0;
}
