/*
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    if (l2 == NULL) {
        return l1;
    }
    if (l1 == NULL) {
        return l2;
    }
    if (l1->val < l2->val) {
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    } else {
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }
    return head;
}

void _test() {
  int A[] = {-9,-5,-3,-2,-2,3,7};
  ListNode* head1 = construct(A, sizeof(A)/sizeof(int));
  printList(head1);

  int A2[] = {-10,-8,-4,-3,-1,3};
  ListNode* head2 = construct(A2, sizeof(A2)/sizeof(int));
  printList(head2);

  ListNode* head = mergeTwoLists(head1, head2);
  printList(head);
}

int main () {
  _test();
  return 0;
}
