/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'.
 */

#include <iostream>
#include <vector>

using namespace std;

#define SIZE 9

void initialize(vector<vector<char> >& board,
                vector<int> &rowMap,
                vector<int> &colMap,
                vector<vector<int> > &squareMap) {
   for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {

         if (board[i][j] == '.') {
            continue;
         }

         int val = board[i][j] - '0';
         rowMap[i] |= (1 << val);
         colMap[j] |= (1 << val);
         squareMap[i/3][j/3] |= (1 << val);
      }
   }
}

bool _solveSudoku(vector<vector<char> >& board,
                  vector<int> &rowMap,
                  vector<int> &colMap,
                  vector<vector<int> > &squareMap) {
   for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board.size(); j++) {

         if (board[i][j] != '.') {
            continue;
         }

         for (int k = 1; k <= board.size(); k++) {
            board[i][j] = '0' + k;

            if (rowMap[i] & (1 << k) ||
                colMap[j] & (1 << k) ||
                squareMap[i/3][j/3] & (1 << k)) {
               board[i][j] = '.';
               continue;
            }

            rowMap[i] |= (1 << k);
            colMap[j] |= (1 << k);
            squareMap[i/3][j/3] |= (1 << k);

            if (_solveSudoku(board, rowMap, colMap, squareMap)) {
               return true;
            }

            rowMap[i] &= ~(1 << k);
            colMap[j] &= ~(1 << k);
            squareMap[i/3][j/3] &= ~(1 << k);
            board[i][j] = '.';
         }

         return false;
      }
   }
   return true;
}

void solveSudoku(vector<vector<char> >& board) {
   /*
    * We use the first 9 bits of every int to show if
    * corresponding number has been used.
    */
   vector<int> rowMap(board.size(), 0);
   vector<int> colMap(board.size(), 0);
   vector<vector<int> > squareMap(board.size()/3, vector<int>(board.size()/3, 0));

   initialize(board, rowMap, colMap, squareMap);
   bool addressable = _solveSudoku(board, rowMap, colMap, squareMap);
   cout << "addressable: " << addressable << endl;
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

   solveSudoku(board);

   cout << "==" << endl;
   for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
         cout << board[i][j] << " ";
      }
      cout << endl;
   }


}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
