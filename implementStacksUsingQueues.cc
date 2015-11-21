/*
 * Implement the following operations of a stack using queues.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Stack {
   queue<int> _queue;

public:
   // Push element x to the back of queue.
   void push(int x) {
      int len = _queue.size();
      _queue.push(x); 
      while (len > 0) {
         int val = _queue.front();
         _queue.pop();
         _queue.push(val);
         len--;
      }
   }
   
   // Removes the element from in front of queue.
   void pop(void) {
      if (_queue.empty()) {
         return;
      }
      _queue.pop();
   }
   
   // Get the front element.
   int peek(void) {
      if (!_queue.empty()) {
         return _queue.front();
      }
      return INT_MIN;
   }
   
   // Return whether the queue is empty.
   bool empty(void) {
      return _queue.empty();
   }
};

void _test() {
   Stack *s = new Stack();
   s->push(1);
   s->push(2);
   s->push(3);

   cout << s->peek() << endl;
   s->pop();
   cout << s->peek() << endl;
   s->pop();
   cout << s->peek() << endl;
   s->pop();

   cout << "empty: " << s->empty() << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
