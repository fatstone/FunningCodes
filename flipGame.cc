/*
 * You are playing the following Flip Game with your friend: Given a string that
 * contains only these two characters: + and -, you and your friend take turns to
 * flip two consecutive "++" into "--". The game ends when a person can no longer
 * make a move and therefore the other person will be the winner.
 *
 * Write a function to compute all possible states of the string after one valid move.
 *
 * For example, given s = "++++", after one move, it may become one of the following states:
 *
 * [
 *   "--++",
 *   "+--+",
 *   "++--"
 * ]
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generatePossibleNextMoves(string s) {
   vector<string> res;
   if (s.length() < 2) {
      return res;
   }

   for (int i = 0; i < s.length(); i++) {
      if (i < s.length()-1) {
         if (s[i] == '+' && s[i+1] == '+') {
            string newString = s.substr(0, i) + "--" + s.substr(i+2);
            res.push_back(newString);
         }
      }
   }
   return res;
}

void _test() {
   string s = "++++";
   vector<string> res = generatePossibleNextMoves(s);
   for (int i = 0; i < res.size(); i++) {
      cout << res[i] << endl;
   }
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
