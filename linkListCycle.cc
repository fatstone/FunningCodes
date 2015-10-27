/*
 * Given a linked list, determine if it has a cycle in it.
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

void generateCycle(ListNode* head) {
   int num = random() % 5;
   ListNode* cursor = head;

   while (cursor && cursor->next && num > 0) {
      cursor = cursor->next;
      num--;
   }

   cursor->next = head->next;
}

bool hasCycle(ListNode *head) {
   ListNode* slow = head;
   ListNode* fast = head;

   for (;;) {
      /* slow pointer moves one step. */
      if (slow == NULL) {
         return false;
      } else {
         slow = slow->next;
      }
      /* fast pointer moves two steps. */
      if (fast == NULL) {
         return false;
      } else {
         fast = fast->next;
      }
      if (fast == NULL) {
         return false;
      } else {
         fast = fast->next;
      }
      if (slow == fast) {
         return true;
      }
   }
   return true;
}

ListNode* detectCycle(ListNode *head) {
   ListNode* slow = head;
   ListNode* fast = head;

   for (;;) {
      /* slow pointer moves one step. */
      if (slow == NULL) {
         return NULL;
      } else {
         slow = slow->next;
      }
      /* fast pointer moves two steps. */
      if (fast == NULL) {
         return NULL;
      } else {
         fast = fast->next;
      }
      if (fast == NULL) {
         return NULL;
      } else {
         fast = fast->next;
      }
      if (slow == fast) {
         break;
      }
   }

   slow = head;
   while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
   }
   return slow;
}

void _test() {
   int A[] = {-9,-5,-3,-2,-2,3,7};
   ListNode* head = construct(A, sizeof(A)/sizeof(int));
   printList(head);

   bool res1 = hasCycle(head);

   generateCycle(head);
   bool res2 = hasCycle(head);
   cout << res1 << '\t' << res2 << endl;

   ListNode* cycleNode = detectCycle(head);
   cout << "detected node: " << cycleNode->val << endl;
}

int main () {
  _test();
  return 0;
}
