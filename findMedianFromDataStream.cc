/*
 * Median is the middle value in an ordered integer list.
 * If the size of the list is even, there is no middle value.
 * So the median is the mean of the two middle value.
 *
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5
 */
#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
   vector<int> minHeap;
   static bool compMin(int a, int b) { return a > b; }

public:
   MinHeap() { make_heap(minHeap.begin(), minHeap.end(), compMin); }

   void push(int val) {
      minHeap.push_back(val);
      push_heap(minHeap.begin(), minHeap.end(), compMin);
   }

   void pop() {
      pop_heap(minHeap.begin(), minHeap.end(), compMin);
      minHeap.pop_back();
   }

   int minOne() {
      return minHeap.front();
   }

   int size() { return minHeap.size(); }
};

class MaxHeap {
   vector<int> maxHeap;
   static bool compMax(int a, int b) { return a < b; }

public:
   MaxHeap() { make_heap(maxHeap.begin(), maxHeap.end(), compMax); }

   void push(int val) {
      maxHeap.push_back(val);
      push_heap(maxHeap.begin(), maxHeap.end(), compMax);
   }

   void pop() {
      pop_heap(maxHeap.begin(), maxHeap.end(), compMax);
      maxHeap.pop_back();
   }

   int maxOne() {
      return maxHeap.front();
   }

   int size() { return maxHeap.size(); }
};

class MedianFinder {
   MinHeap *minHeap;
   MaxHeap *maxHeap;
public:
   MedianFinder() {
      minHeap = new MinHeap();
      maxHeap = new MaxHeap();
   }
   ~MedianFinder() {
      delete minHeap;
      delete maxHeap;
   }

   // Adds a number into the data structure.
   void addNum(int num) {
      minHeap->push(num);

      if (minHeap->size() == maxHeap->size() + 2) {
         int val = minHeap->minOne();
         minHeap->pop();
         maxHeap->push(val);
         return;
      }

      if (maxHeap->size() == 0) {
         return;
      }

      int minOne = minHeap->minOne();
      int maxOne = maxHeap->maxOne();
      if (maxOne > minOne) {
         maxHeap->pop();
         minHeap->pop();

         maxHeap->push(minOne);
         minHeap->push(maxOne);
      }
   }

   // Returns the median of current data stream
   double findMedian() {
      int minOne = minHeap->size() == 0 ? 0 : minHeap->minOne();
      int maxOne = maxHeap->size() == 0 ? 0 : maxHeap->maxOne();

      if ((minHeap->size() + maxHeap->size()) % 2 == 0) {
         return ((double)(minOne+maxOne))/2;
      }
      return (double)minOne;
   }
};

bool compMin(int a, int b) { return a > b; }

void _test() {
   MedianFinder *m = new MedianFinder();
   vector<int> num;
   num.push_back(1);
   num.push_back(2);
   num.push_back(3);
   num.push_back(4);
   num.push_back(5);
   
   for (int i = 0; i < num.size(); i++) {
      m->addNum(num[i]);
      double median = m->findMedian();

      cout << "insert: " << num[i] << ", median: " << median << endl;
   }
}

int main () {
  _test();
  return 0;
}
