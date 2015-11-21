/*
 * Given a singly linked list, determine if it is a palindrome.
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

bool isPalindrome(ListNode* head) {
   ListNode* cursor;
   ListNode* newHead = NULL, *newTail = NULL;
   int nums = 0, halfNum = 0;

   cursor = head;
   while (cursor != NULL) {
      nums++;
      cursor = cursor->next;
   }

   if (nums < 2) {
      return true;
   }

   halfNum = nums/2;
   cursor = head;
   while (halfNum > 0) {
      ListNode *node = cursor;
      cursor = cursor->next;

      if (newHead == NULL) {
         newHead = newTail = node;
      } else {
         node->next = newHead;
         newHead = node;
      }
      halfNum--;
   }
   if (newTail != NULL) {
      newTail->next = NULL;
   }

   head = nums%2 == 0 ? cursor : cursor->next;

   while (head != NULL && newHead != NULL) {
      if (head->val != newHead->val) {
         return false;
      }
      head = head->next;
      newHead = newHead->next;
   }
   return true;
}

void _test() {
  int A[] = {1,2,2,1};
  ListNode* head = construct(A, sizeof(A)/sizeof(int));
  printList(head);

  bool isPal = isPalindrome(head);
  cout << "isPalindrome: " << isPal << endl;
}

int main () {
  _test();
  return 0;
}
