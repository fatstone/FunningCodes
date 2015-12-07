/*
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <iostream>
#include <vector>

using namespace std;

void addRange(vector<string>& res, 
              vector<int>& nums,
              int startPos,
              int endPos) {
   string currRes = to_string(nums[startPos]);
   if (startPos != endPos) {
      currRes += "->" + to_string(nums[endPos]); 
   }
   res.push_back(currRes);
}

vector<string> summaryRanges(vector<int>& nums) {
   vector<string> res;
   int startPos = 0, endPos = 0;

   if (nums.size() == 0) {
      return res;
   } 

   for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[endPos] + 1) {
         endPos = i;
      } else {
         addRange(res, nums, startPos, endPos);
         startPos = endPos = i;
      }
   }
   addRange(res, nums, startPos, endPos);
   return res;
}

void _test() {
   vector<int> nums {0, 1, 2, 4, 5, 7};
   vector<string> res = summaryRanges(nums);
   for (auto& str: res) {
      cout << str << endl;
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
