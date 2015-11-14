/*
 * A peak element is an element that is greater than its neighbors.
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nextOne(vector<int>& nums, int idx) {
        if (idx >= nums.size()-1) {
            return INT_MIN;
        }
        return nums[idx+1];
    }
    int prevOne(vector<int>& nums, int idx) {
        if (idx == 0) {
            return INT_MIN;
        }
        return nums[idx-1];
    }
    int findPeakElement(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (prevOne(nums, i) < nums[i] && nums[i] > nextOne(nums, i)) {
                res = i;
                break;
            }
        }
        return res;
    }
};

void _test() {
   int res;
   vector<int> input;
   input.push_back(1);
   input.push_back(2);

   Solution *s = new Solution();
   res = s->findPeakElement(input);
   cout << "res: " << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
