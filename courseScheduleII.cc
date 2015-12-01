/*
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
   queue<int> noIncomeEdgiesNodes;
   vector<int> res;
   vector<int> internalRes;

   unordered_map<int, unordered_set<int> > inCommingNodes;
   unordered_map<int, unordered_set<int> > outGoingNodes;

   for (auto& prerequisite : prerequisites) {
      // [1, 0]: to take course 1, you have to finish course 0: 0-->1
      inCommingNodes[prerequisite.first].insert(prerequisite.second);
      outGoingNodes[prerequisite.second].insert(prerequisite.first);
   }
   for (int i = 0; i < numCourses; i++) {
      if (inCommingNodes.find(i) == inCommingNodes.end()) {
         noIncomeEdgiesNodes.push(i);
      }
   }
   while (!noIncomeEdgiesNodes.empty()) {
      /* Pick up a node that doesn't have in comming edgies. */
      int node = noIncomeEdgiesNodes.front();
      noIncomeEdgiesNodes.pop();

      internalRes.push_back(node);

      /*
       * For all nodes that this node connects to, let's see if they
       * can become nodes that don't have incoming edgies without this
       * node.
       */
      for (auto& _node: outGoingNodes[node]) {
         inCommingNodes[_node].erase(node);
         if (inCommingNodes[_node].empty()) {
            noIncomeEdgiesNodes.push(_node);
         }
      }

      outGoingNodes.erase(node);
   }
   if (!outGoingNodes.empty() /*|| !inCommingNodes.empty()*/) {
      return res;
   }
   return internalRes;
}

void _test() {
   int numCourses = 4;
   vector<pair<int, int> > prerequisites;
   prerequisites.push_back({1, 0});
   prerequisites.push_back({2, 0});
   prerequisites.push_back({3, 1});
   prerequisites.push_back({3, 2});

   vector<int> res = findOrder(numCourses, prerequisites);
   for (int i = 0; i < res.size(); i++) {
      cout << i << " ";
   }
   cout << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
