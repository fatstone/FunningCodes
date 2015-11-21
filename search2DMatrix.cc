/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 * 
 * [
 *  [1,   3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
   int rows, cols, start, end;
   if (matrix.size() == 0) {
      return false;
   }
   
   rows = matrix.size();
   cols = matrix[0].size();
   start = 0;
   end = rows*cols - 1;
   while (start <= end) {
      int mid = start + (end-start)/2;
      int val = matrix[mid/cols][mid%cols];
  
      if (target == val) {
         return true;
      } else if (target < val) {
         end = mid - 1;
      } else {
         start = mid + 1;
      }
   }
   return false;
}

void printOut(vector<vector<int> >& matrix) {
   cout << " == " << endl;
   for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
         cout << matrix[i][j] << '\t';
      }
      cout << endl;
   }
}

void _test() {
#if 1
   vector<vector<int> >matrix { {1, 3, 5, 7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50},
                              };
   printOut(matrix);
   bool res = searchMatrix(matrix, 3);
#endif
#if 0
   vector<vector<int> >matrix { {1, 1}
                              };
   printOut(matrix);
   bool res = searchMatrix(matrix, 2);
#endif
   cout << "res: " << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
