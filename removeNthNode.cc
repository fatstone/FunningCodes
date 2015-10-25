/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
#include <iostream>

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
   ListNode *nextP = head, *prevP = head;

   while (nextP != NULL && n > 0) {
      nextP = nextP->next;
      n--;
   }
   if (n > 0) {
      return head;
   }
   if (nextP == NULL && prevP == head) {
      return head->next;
   }
   while (nextP != NULL && nextP->next != NULL) {
      nextP = nextP->next;
      prevP = prevP->next;
   }
   prevP->next = (prevP->next == NULL) ? NULL :
                 prevP->next->next;
   return head;
}

void _test() {
  int A[] = {1, 2, 3, 4, 5};
  int n = 2;

//  int A[] = {1, 2};
//  int n = 1;

//  int A[] = {1, 2};
//  int n = 2;

//  int A[] = {1};
//  int n = 1;

  ListNode* head = construct(A, sizeof(A)/sizeof(int));
  printList(head);

  ListNode* head1 = removeNthFromEnd(head, n);
  printList(head1);
}

int main () {
  _test();
  return 0;
}
