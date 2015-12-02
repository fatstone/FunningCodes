/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are all
 * surrounded by water.
 *
 * Example 1:
 *
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Answer: 1
 *
 * Example 2:
 *
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Answer: 3
 */

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char> >& grid,
         vector<vector<bool> >& checked,
         int rows, int cols, int currRow, int currCol) {
   if (grid[currRow][currCol] == '0' || checked[currRow][currCol]) {
      return;
   }

   checked[currRow][currCol] = true;

   if (currRow > 0) {
      dfs(grid, checked, rows, cols, currRow-1, currCol);
   }
   if (currRow < rows-1) {
      dfs(grid, checked, rows, cols, currRow+1, currCol);
   }
   if (currCol > 0) {
      dfs(grid, checked, rows, cols, currRow, currCol-1);
   }
   if (currCol < cols - 1) {
      dfs(grid, checked, rows, cols, currRow, currCol+1);
   }
}

int numIslands(vector<vector<char>>& grid) {
   if (grid.size() == 0) {
      return 0;
   }
   int rows = grid.size(), cols = grid[0].size();
   vector<vector<bool> > checked(rows, vector<bool> (cols, false));
   int cnt = 0;

   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         if (grid[i][j] == '1' && !checked[i][j]) {
            dfs(grid, checked, rows, cols, i, j);
            cnt++;
         }
      }
   }
   return cnt;
}

void _test() {
   vector<vector<char> > grid { {'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};
   int cnt = numIslands(grid);
   cout << "cnt: " << cnt << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
