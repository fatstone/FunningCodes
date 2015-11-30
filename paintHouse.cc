/*
 * There are a row of n houses, each house can be painted with one of the three colors:
 * red, blue or green. The cost of painting each house with a certain color is different.
 * You have to paint all the houses such that no two adjacent houses have the same color.
 *
 * The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
 * For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is
 * the cost of painting house 1 with color green, and so on... Find the minimum cost to
 * paint all houses.
 */

#include <iostream>
#include <vector>

using namespace std;

/* Reuse costs matrix. */
int minCost(vector<vector<int>>& costs) {
   if (costs.size() == 0) {
      return 0;
   }
   
   int n = costs.size();
   for (int i = 1; i < n; i++) {
      costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
      costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
      costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
   }
   return min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]);
}

int minCost1(vector<vector<int>>& costs) {
   if (costs.size() == 0) {
      return 0;
   }
   
   vector<int> cost(3, 0);
   cost[0] = costs[0][0];
   cost[1] = costs[0][1];
   cost[2] = costs[0][2];
   for (int i = 1; i < costs.size(); i++) {
      int cost0 = costs[i][0] + min(cost[1], cost[2]);
      int cost1 = costs[i][1] + min(cost[0], cost[2]);
      int cost2 = costs[i][2] + min(cost[1], cost[0]);

      cost[0] = cost0;
      cost[1] = cost1;
      cost[2] = cost2;
   }
   return min(min(cost[0], cost[1]), cost[2]);
}

void _test() {
   vector<vector<int> >costs{{17, 2, 17},
                             {16, 16, 5},
                             {14, 3, 19}};
   //int cost = minCost(costs);
   int cost = minCost1(costs);
   cout << "cost: " << cost << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
