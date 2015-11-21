/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * 1. Integers in each row are sorted in ascending from left to right.
 * 2. Integers in each column are sorted in ascending from top to bottom.
 *
 * For example,
 * 
 * [
 *  [1,   4,  7, 11, 15],
 *  [2,   5,  8, 12, 19],
 *  [3,   6,  9, 16, 22],
 *  [10, 13, 14, 17, 24],
 *  [18, 21, 23, 26, 30]
 * ]
 * Given target = 5, return true.
 * Given target = 20, return false.
 */

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
   int rows, cols, curRow, curCol;
   if (matrix.size() == 0) {
      return false;
   }

   rows = matrix.size();
   cols = matrix[0].size();
   curRow = 0;
   curCol = cols - 1;

   while (curRow < rows && curCol >= 0) {
      if (matrix[curRow][curCol] == target) {
         return true;
      }

      if (matrix[curRow][curCol] < target) {
         curRow++;
      } else {
         curCol--;
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
   vector<vector<int> >matrix { {1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30},
                              };
   printOut(matrix);
   bool res = searchMatrix(matrix, 26);
   cout << "res: " << res << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
