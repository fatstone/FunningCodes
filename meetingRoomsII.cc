/*
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return 2.
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

int minMeetingRooms(vector<Interval>& intervals) {
   vector<int> starts;
   vector<int> ends;
   int minRooms = 0, endPos = 0;

   for (auto& i: intervals) {
      starts.push_back(i.start);
      ends.push_back(i.end);
   }

   sort(starts.begin(), starts.end());
   sort(ends.begin(), ends.end());

   for (int i = 0; i < starts.size(); i++) {
      if (starts[i] < ends[endPos]) {
         minRooms++;
      } else {
         endPos++;
      }
   }
   return minRooms;
}

void _test() {
   vector<Interval> intervals;
   intervals.push_back(Interval(0, 30));
   intervals.push_back(Interval(5, 10));
   intervals.push_back(Interval(15, 20));
   int res = minMeetingRooms(intervals);
   cout << "res: " << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
