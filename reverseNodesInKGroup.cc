/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 * You may not alter the values in the nodes, only nodes itself may be changed.
 *
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
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

void _reverseKGroup(ListNode** start, ListNode** end) {
   ListNode* curr = *start;
   ListNode* newHead = *start;
   ListNode* stop = (*end)->next;

   while (curr != NULL && curr != stop) {
      ListNode *node = curr;
      curr = curr->next;
      node->next = newHead;
      newHead = node;
   }

   *end = *start;
   *start = newHead;
}

void appoint(ListNode** head, ListNode** tail, ListNode* start, ListNode* end) {
   if (*head == NULL) {
      *head = start;
      *tail = end;
   } else {
      (*tail)->next = start;
      *tail = end;
   }
}

ListNode* reverseKGroup(ListNode* head, int k) {
   ListNode *newHead, *newTail;
   ListNode *start, *end;
   int count = 0;

   if (head == NULL) {
      return NULL;
   }

   newHead = newTail = NULL;
   start = end = head;

   while (head != NULL) {
      end = head;
      head = head->next;
      count++;

      if (count == k) {
         _reverseKGroup(&start, &end);
         appoint(&newHead, &newTail, start, end);

         start = end = head;
         count = 0;
      }
   }

   appoint(&newHead, &newTail, start, end);
   return newHead;
}

/* Stack version. */
void purgeStack(stack<ListNode*>& reverseStack,
                ListNode** headPtr,
                ListNode** tailPtr) {
   while (!reverseStack.empty()) {
      ListNode* node = reverseStack.top();
      reverseStack.pop();

      if (*headPtr == NULL) {
         *headPtr = *tailPtr = node;
      } else {
         (*tailPtr)->next = node;
         *tailPtr = node;
      }
   }
}

ListNode* reverseKGroupStack(ListNode* head, int k) {
   ListNode* newHead, *newTail;
   stack<ListNode*> reverseStack;
   int count = 0;

   if (head == NULL) {
      return NULL;
   }

   newHead = newTail = NULL;
   while (head != NULL) {
      reverseStack.push(head);
      count++;
      head = head->next;

      if (count == k) {
         purgeStack(reverseStack, &newHead, &newTail);
         count = 0;
      }
   }

   if (!reverseStack.empty()) {
      stack<ListNode*> _reverseStack;
      while (!reverseStack.empty()) {
         _reverseStack.push(reverseStack.top());
         reverseStack.pop();
      }
      purgeStack(_reverseStack, &newHead, &newTail);
   }
   if (newTail != NULL) {
      newTail->next = NULL;
   }
   return newHead;
}

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



void _test() {
   int A[] = {-9,-5,-3,-2,-2,3,7};
   ListNode* head = construct(A, sizeof(A)/sizeof(int));
   printList(head);

   ListNode* reverseHead = reverseKGroup(head, 2);
   printList(reverseHead);
}

int main () {
  _test();
  return 0;
}
