/*
 * Given an array nums, there is a sliding window of size k which is
 * moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window
 * moves right by one position.
 *
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 *
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> res; 
      deque<int> maxOnes;
      int i = 0;
      
      for (; i < k; i++) {
         while (!maxOnes.empty() && nums[i] > nums[maxOnes.back()]) {
            maxOnes.pop_back();
         }
         maxOnes.push_back(i);
      }

      for (; i < nums.size(); i++) {

         if (!maxOnes.empty()) {
            res.push_back(nums[maxOnes.front()]);
         }

         while (!maxOnes.empty() && i - maxOnes.front() >= k) {
            maxOnes.pop_front();
         }

         while (!maxOnes.empty() && nums[i] > nums[maxOnes.back()]) {
            maxOnes.pop_back();
         }

         maxOnes.push_back(i);
      }

      if (!maxOnes.empty()) {
         res.push_back(nums[maxOnes.front()]);
      }

      return res;
   }
};

int main (int argc, char* argv[]) {
   vector<int> nums;
   int k = 3;
   nums.push_back(1);
   nums.push_back(3);
   nums.push_back(-1);
   nums.push_back(-3);
   nums.push_back(5);
   nums.push_back(3);
   nums.push_back(6);
   nums.push_back(7);

   Solution *s = new Solution();
   vector<int> res = s->maxSlidingWindow(nums, k);
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
   }
   return 0;
}
