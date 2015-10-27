/*
 * Given an array nums containing n + 1 integers where each integer is
 * between 1 and n (inclusive), prove that at least one duplicate number
 * must exist. Assume that there is only one duplicate number, find the
 * duplicate one.
 *
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * We assume nums must have at least one dup.
 * This problem is actually about how to find a cycle in array.
 *
 * We might find some thoughts on a simlar problem:
 * http://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
 * Summary of these solutions:
 * 1. Brute force;
 * 2. Hash map;
 * 3. Math trick;
 * 4. Value as index;
 * 5. Cycle;
 */
int findDuplicate(vector<int>& nums) {
   int fast, slow;
   fast = slow = 0;
   do {
      /* slow moves one step. */
      slow = nums[slow];
      /* fast moves two steps. */
      fast = nums[nums[fast]];
   } while (fast != slow);

   slow = 0;
   while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
   }
   return slow;
}

void _permute(vector<int>& prefix, vector<int>& nums,
               vector<vector<int> >& res) {
   if (0 == nums.size()) {
      res.push_back(prefix);
      return;
   }

   for (int i = 0; i < nums.size(); i++) {

      vector<int> newNums;
      prefix.push_back(nums[i]);

      newNums = nums;
      newNums.erase(newNums.begin()+i);
      _permute(prefix, newNums, res);

      prefix.pop_back();
   }
}

vector<vector<int> > permute(vector<int>& nums) {
   vector<vector<int> >res;
   vector<int> prefix;
   vector<bool> used(nums.size(), false);

   _permute(prefix, nums, res);
   return res;
}

void _test() {
   vector<int> nums;
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(3);
   nums.push_back(4);
   nums.push_back(1);
   nums.push_back(1);
   nums.push_back(1);

   vector<vector<int> > res = permute(nums);
   int dup, testcases = 0;

   for (int i = 0; i < res.size(); i++) {
      dup = findDuplicate(res[i]);
      if (dup != 1) {
         for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
         }
         cout << '\n' << "expected: 1, got: " << dup << endl;
         break;
      } else {
         testcases++;
      }
   }
   cout << "Passed: " << testcases << " test cases." << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
