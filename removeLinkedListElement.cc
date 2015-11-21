/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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

ListNode* removeElements(ListNode* head, int val) {
   ListNode* cursor = head;
   ListNode* newHead = NULL, *newTail = NULL;

   while (cursor != NULL) {

      if (cursor->val != val) {
         if (newHead == NULL) {
            newHead = newTail = cursor;
         } else {
            newTail->next = cursor;
            newTail = cursor;
         }
      }
      cursor = cursor->next;
   }
   if (newTail != NULL) {
      newTail->next = NULL;
   }
   return newHead;
}

void _test() {
  int A[] = {1,2,6,3,4,5,6};
  ListNode* head = construct(A, sizeof(A)/sizeof(int));
  printList(head);

  ListNode* head1 = removeElements(head, 6); 
  printList(head1);
}

int main () {
  _test();
  return 0;
}
