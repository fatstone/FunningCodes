/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
   int start = 0, end = s.length()-1;

   while (start <= end) {
      if (!isalnum(s[start])) {
         start++;
         continue;
      }
      if (!isalnum(s[end]) ) {
         end--;
         continue;
      }
      if (tolower(s[start]) == tolower(s[end])) {
         start++; end--;
      } else {
         break;
      }
   }
   return start > end;
}

int main (int argc, char* argv[]) {
   string s = "A man, a plan, a canal: Panama";
   bool res = isPalindrome(s);
   cout << s << ", palindrom: " << res << endl;
   return 0;
}
