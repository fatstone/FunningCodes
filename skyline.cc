#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
   vector<pair<int, int> >res;
   vector<pair<int, int> >edgies;
   multiset<int> heap;
   int height = 0;

   if (buildings.size() == 0) {
      return res;
   }

   for (auto& b: buildings) {
      edgies.push_back({b[0], -1*b[2]});
      edgies.push_back({b[1], b[2]});
   }

   sort(edgies.begin(), edgies.end());

   heap.insert(0);
   for (auto& e: edgies) {
      int maxHeight;

      if (e.second > 0) {
         /* Right edge */
         heap.erase(heap.find(e.second));
      } else {
         heap.insert(-1*e.second);
      }
      maxHeight = *heap.rbegin();     

      if (height != maxHeight) {
         res.push_back({e.first, maxHeight});
         height = maxHeight;
      }
   }
   return res;
}

void printSkyline(vector<vector<int> >& buildings) {
   vector<pair<int, int> >res;
   for (int i = 0; i < buildings.size(); i++) {
      for (int j = 0; j < buildings[i].size(); j++) {
         cout << buildings[i][j] << '\t';
      }
      cout << endl;
   }
}

void _test() {
#if 1
   vector<vector<int> >buildings { {2, 9, 10},
                                   {3, 7, 15},
                                   {5, 12, 12},
                                   {15, 20, 10},
                                   {19, 24, 8},
                                 };
#endif
#if 0
   vector<vector<int> >buildings { {0, 2, 3},
                                   {2, 5, 3},
                                 };
#endif
#if 0
   vector<vector<int> >buildings { {1, 2, 1},
                                   {1, 2, 2},
                                   {1, 2, 3},
                                 };
#endif
   vector<pair<int, int> >res;
   printSkyline(buildings);

   cout << "--" << endl;
   res = getSkyline(buildings);
   cout << "Answer:" << endl;
   for (int i = 0; i < res.size(); i++) {
      cout << res[i].first << '\t' << res[i].second << endl;
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
