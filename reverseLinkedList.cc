/*
 * Reverse a singly linked list.
 */
#include <iostream>
#include <iterator>

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

ListNode* reverseList(ListNode* head) {
   ListNode* newHead = NULL;
   ListNode* newTail = NULL;

   while (head != NULL) {
      ListNode *node = head;
      head = head->next;

      if (newHead == NULL) {
         newHead = newTail = node;
      } else {
         node->next = newHead;
         newHead = node;
      }
   }
   if (newTail != NULL) {
      newTail->next = NULL;
   }
   return newHead;
}

void _test() {
   int A[] = {-9,-5,-3,-2,-2,3,7};
   ListNode* head = construct(A, sizeof(A)/sizeof(int));
   printList(head);

   ListNode* reverseHead = reverseList(head);
   printList(reverseHead);
}

int main () {
  _test();
  return 0;
}
