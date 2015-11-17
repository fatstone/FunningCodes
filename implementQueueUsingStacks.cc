/*
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Queue {
   stack<int> s1;
   stack<int> s2;

   void flushS2() {
      if (s1.empty()) {
         while (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            s1.push(val);
         }
      } 
   }
public:
   // Push element x to the back of queue.
   void push(int x) {
      s2.push(x); 
   }
   
   // Removes the element from in front of queue.
   void pop(void) {
      flushS2();

      if (!s1.empty()) {
         s1.pop();
      }
   }
   
   // Get the front element.
   int peek(void) {
      flushS2(); 
      if (!s1.empty()) {
         return s1.top();
      }
      return INT_MIN;
   }
   
   // Return whether the queue is empty.
   bool empty(void) {
      return s1.empty() && s2.empty(); 
   }
};

void _test() {
   Queue *queue = new Queue();
   queue->push(1);
   queue->push(2);
   queue->push(3);

   cout << queue->peek() << endl;
   queue->pop();
   cout << queue->peek() << endl;
   queue->pop();
   cout << queue->peek() << endl;
   queue->pop();

   cout << "empty: " << queue->empty() << endl;
}

int main (int argc, char* argv[]) {
   _test();
   return 0;
}
