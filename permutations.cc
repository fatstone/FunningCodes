/*
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

void _permute1(vector<int>& prefix, vector<int>& nums,
               vector<bool>& used, int usedNum,
               vector<vector<int> >& res) {
   if (usedNum == nums.size()) {
      res.push_back(prefix);
      return;
   }

   for (int i = 0; i < nums.size(); i++) {

      if (used[i]) {
         continue;
      }

      prefix.push_back(nums[i]);
      used[i] = true;
      _permute1(prefix, nums, used, usedNum+1, res);

      prefix.pop_back();
      used[i] = false;
   }
}

vector<vector<int> > permute(vector<int>& nums) {
   vector<vector<int> >res;
   vector<int> prefix;
   vector<bool> used(nums.size(), false);

   //_permute1(prefix, nums, used, 0, res);
   _permute(prefix, nums, res);
   return res;
}


void _test1() {
   vector<int> nums;
   nums.push_back(1);
   nums.push_back(2);
   nums.push_back(3);

   vector<vector<int> > res = permute(nums); 
   for (int i = 0; i < res.size(); i++) {
      for (int j = 0; j < res[i].size(); j++) {
         cout << res[i][j] << " ";
      }
      cout << endl;
   }
}

void _permuteString(string& prefix, string& s, vector<string>& res) {
   if (s.length() == 0) {
      res.push_back(prefix);
      return;
   }

   for (int i = 0; i < s.length(); i++) {
      string newPrefix = prefix + s[i];
      string newS = s.substr(0, i) + s.substr(i+1);
      _permuteString(newPrefix, newS, res);
   }
}

vector<string> permuteString(string s) {
   vector<string> res;
   string prefix = "";
   _permuteString(prefix, s, res);
   return res;
}

void _test2() {
   string s = "123";

   vector<string> res = permuteString(s);
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << '\n';
   }
}

int main (int argc, char* argv[]) {
   //_test2();
   _test1();
   return 0;
}
