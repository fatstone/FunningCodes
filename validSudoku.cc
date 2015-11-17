/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 */

#include <iostream>
#include <vector>

using namespace std;

#define SIZE 9

bool isValidSudoku(vector<vector<char> >& board) {
   int len = board.size();
   vector<vector<bool> > rowMaps(len, vector<bool>(len, false));
   vector<vector<bool> > colMaps(len, vector<bool>(len, false));
   vector<vector<bool> > squareMaps(len, vector<bool>(len, false));

   for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
         if (board[i][j] == '.') {
            continue;
         }

         int idx = board[i][j] - '1';
         if (rowMaps[i][idx] || colMaps[j][idx] ||
             squareMaps[3*(i/3) + j/3][idx]) {
            return false;
         }
         rowMaps[i][idx] = colMaps[j][idx] = squareMaps[3*(i/3) + j/3][idx] = true;
      }
   }

   return true;
}

void _test() {
   vector<vector<char> >board(SIZE, vector<char>(SIZE));

   char cboard[SIZE][SIZE] = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

   for (int i = 0; i < SIZE; ++i) {
      board[i].assign(cboard[i], cboard[i] + SIZE);
   }

   for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }

   bool valid = isValidSudoku(board);
   cout << "valid: " << valid << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
