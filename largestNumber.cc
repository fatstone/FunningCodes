/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool comp(int a, int b) {
   string strA = to_string(a) + to_string(b);
   string strB = to_string(b) + to_string(a);

   return stoll(strA) < stoll(strB);
}

string largestNumber(vector<int>& nums) {
   string res = "";

   if (nums.size() == 0) {
      return res;
   }

   sort(nums.begin(), nums.end(), comp);
   for (int i = nums.size()-1; i >= 0; i--) {
      res += to_string(nums[i]);
   }

   return res[0] == '0' ? "0" : res;
}

void initialize(vector<int>& nums) {
   for (int i = 0; i < 4; i++) {
      nums.push_back(random() % 100);
   }
}

int main (int argc, char* argv[]) {
   vector<int> nums;
   initialize(nums);

   string res = largestNumber(nums);
   cout << "res: " << res << endl;
   return 0;
}
