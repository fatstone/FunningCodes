/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 * forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * maxCapacity = max(maxCapacity, (j-i)*min(height[j], height[i]));
 */
int maxArea(vector<int>& height) {
   int maxCapacity = 0;
   int start = 0, end = height.size()-1;

   while (start <= end) {
      maxCapacity = max(maxCapacity,
                        (end-start) * min(height[start], height[end]));
      if (height[start] < height[end]) {
         start++;
      } else {
         end--;
      }
   }
   return maxCapacity;
}

int main (int argc, char* argv[]) {
   vector<int> height;
   height.push_back(1);
   height.push_back(2);
   height.push_back(4);
   height.push_back(3);
   height.push_back(5);

   int capacity = maxArea(height);
   cout << "capacity: " << capacity << '\n';
   return 0;
}
