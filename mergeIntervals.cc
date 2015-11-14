/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    void printIntervals(vector<Interval>& intervals) {
       for (int i = 0; i < intervals.size(); i++) {
          cout << "[" << intervals[i].start << ", " << intervals[i].end << "]" << endl;
       }
    }

    static bool comp(Interval& a, Interval& b) {
       return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
       vector<Interval> res;    
       if (intervals.size() <= 1) {
          return intervals;
       }

       sort(intervals.begin(), intervals.end(), comp);

       Interval currInterval = intervals[0];
       for (int i = 0; i < intervals.size(); i++) {
          if (intervals[i].start > currInterval.end) {
             res.push_back(currInterval);
             currInterval = intervals[i];
          } else {
             currInterval.end = max(intervals[i].end, currInterval.end);
          }
       }

       res.push_back(currInterval);
       return res;
    }
};

void _test() {
   vector<Interval> intervals;
   vector<Interval> res;

   intervals.push_back(Interval(1, 3));
   intervals.push_back(Interval(2, 6));
   intervals.push_back(Interval(8, 10));
   intervals.push_back(Interval(15, 18));

   Solution *s = new Solution();
   res = s->merge(intervals);
   s->printIntervals(intervals);

   cout << " == " << endl;
   s->printIntervals(res);
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
