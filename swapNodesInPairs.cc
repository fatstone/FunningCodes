/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode* random;
  ListNode(int x) : val(x), next(NULL), random(NULL) {}
};

ListNode* construct(int A[], int n) {
  ListNode* head = NULL, *tail = NULL;
  for (int i = 0; i < n; i++) {
    ListNode* node = new ListNode(A[i]);
    if (!head) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

void printList(ListNode* head) {
  cout << "{ ";
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << "}" << endl;
}

void purgeStack(stack<ListNode*>& swapStack, ListNode** tail, ListNode** head) {
   while (!swapStack.empty()) {
      ListNode* node = swapStack.top();
      swapStack.pop();
   
      if (*head == NULL) {
         *tail = *head = node;
      } else {
         (*tail)->next = node;
         *tail = node;
      }
   }
}

ListNode* swapPairs(ListNode* head) {
   stack<ListNode*> swapStack;
   ListNode* newHead = NULL;
   ListNode* newTail = NULL;

   while (head != NULL) {
      swapStack.push(head);
      head = head->next;

      if (head == NULL) {
         break;
      }

      swapStack.push(head);
      head = head->next;

      purgeStack(swapStack, &newTail, &newHead);
   }

   purgeStack(swapStack, &newTail, &newHead);

   if (newTail != NULL) {
      newTail->next = NULL;
   }
   return newHead;
}

void _test() {
   int A[] = {-9,-5,-3,-2,-2,3,7};
   ListNode* head = construct(A, sizeof(A)/sizeof(int));
   printList(head);

   ListNode* swapHead = swapPairs(head);
   printList(swapHead);
}

int main () {
  _test();
  return 0;
}
