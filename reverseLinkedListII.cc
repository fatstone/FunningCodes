/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
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

void _reverse(ListNode** start, ListNode** end) {
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

ListNode* reverseBetween(ListNode* head, int m, int n) {
   ListNode *newHead, *newTail;
   ListNode *start, *end;
   int cnt = 1;

   if (head == NULL) {
      return NULL;
   }

   newHead = head;
   newTail = NULL;
   start = end = NULL;

   while (head != NULL) {
      ListNode* headNext = head->next;
      if (cnt == m) {
         start = head;
      }
      if (cnt == n) {
         end = head;
      }
      if (start != NULL && end != NULL) {
         _reverse(&start, &end);
         if (newTail == NULL) {
            newHead = start;
            newTail = end;
         } else {
            newTail->next = start;
            newTail = end;
         }
         newTail->next = headNext;
         start = end = NULL;
      } else if (start == NULL && end == NULL) {
         newTail = head;
      }
      head = headNext;
      cnt++;
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
   int m = 1, n = 7;
   ListNode* head = construct(A, sizeof(A)/sizeof(int));
   printList(head);

   ListNode* reverseHead = reverseBetween(head, m, n);
   printList(reverseHead);
}

int main () {
  _test();
  return 0;
}
