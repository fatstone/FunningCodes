/*
 * Given a string containing just the characters '(', ')', '{', '}',
 * '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are
 * all valid but "(]" and "([)]" are not.
 */
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
   char symbol;
   stack<char> leftParentheses;

   for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
         leftParentheses.push(s[i]);
      } else {
         if (leftParentheses.empty()) {
            return false;
         } 

         symbol = leftParentheses.top();
         leftParentheses.pop();

         if ((s[i] == ')' && symbol != '(') ||
             (s[i] == '}' && symbol != '{') ||
             (s[i] == ']' && symbol != '[')) {
            return false;
         }
      }
   }
   return leftParentheses.empty();       
}

void _test() {
  struct _tests {
    string s1;
    bool   expected;
  } tests[] = {
    {
      "()[]{}",
      true,
    },
    {
      "(",
      false,
    },
    {
      "()",
      true,
    },
    {
      "([)]",
      false,
    },
  };

  int testCases = sizeof(tests)/sizeof(struct _tests);
  bool pass = true;
  for (int i = 0; i < testCases; i++) {
    bool got = isValid(tests[i].s1);
    if (got != tests[i].expected) {
      cout << tests[i].s1 << '\t' << "expected: " << tests[i].expected << '\t' << " got: " << got << endl;
      pass = false;
    }
  }
  if (pass) cout << "pass " << testCases << " cases!" << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
