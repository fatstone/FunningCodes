/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
   stack<int> minStack;
   stack<int> _stack;
public:
   void push(int x) {
      _stack.push(x); 
      if (x <= getMin()) {
         minStack.push(x);
      }
   }
   
   void pop() {
      int val = _stack.top();
      _stack.pop();

      if (val == minStack.top()) {
         minStack.pop();
      }
   }
   
   int top() {
      return _stack.top(); 
   }
   
   int getMin() {
      return minStack.empty() ? INT_MAX : minStack.top(); 
   }
};

void _test() {
   MinStack *ms = new MinStack();
   ms->push(0);
   ms->push(1);
   ms->push(0);
   cout << ms->getMin() << endl;
   ms->pop();
   cout << ms->getMin() << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
