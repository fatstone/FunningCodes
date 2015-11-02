/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
#include <iostream>
#include <vector>
#include <queue>

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

ListNode* _mergeTwoLists(ListNode* list1, ListNode* list2) {
   ListNode* head = NULL, *tail = NULL;
   ListNode** nextElement = NULL;

   while (list1 != NULL || list2 != NULL) {
      if (list1 == NULL || (list2 != NULL && list1->val >= list2->val)) {
         nextElement = &list2;
      } else  {
         nextElement = &list1;
      }

      if (head == NULL) {
         head = *nextElement;
         tail = (*nextElement);
      } else {
         tail->next = *nextElement;
         tail = *nextElement;
      }
      *nextElement = (*nextElement)->next;
   }
   return head;
}

ListNode* _mergeKLists(vector<ListNode*>& lists, int start, int end) {
   int mid = start + (end-start)/2;
   ListNode* list1, *list2;

   if (start > end) {
      return NULL;
   }
   if (start == end) {
      return lists[start];
   }
   if (start == end - 1) {
      return _mergeTwoLists(lists[start], lists[end]);
   }
   
   list1 = _mergeKLists(lists, start, mid);
   list2 = _mergeKLists(lists, mid+1, end);
   
   return _mergeTwoLists(list1, list2);
}

bool comp(ListNode* n1, ListNode* n2) {
   return n1->val > n2->val;
}

ListNode* _mergeKListsViaHeap(vector<ListNode*>& lists) {
   ListNode* head = NULL, *tail = NULL;
   vector<ListNode*> minHeap;

   for (int i = 0; i < lists.size(); i++) {
      if (lists[i] != NULL) {
         minHeap.push_back(lists[i]);
         push_heap(minHeap.begin(), minHeap.end(), comp);
      }
   }

   while (!minHeap.empty()) {
      pop_heap(minHeap.begin(), minHeap.end(), comp);
      ListNode* node = minHeap.back();
      minHeap.pop_back();

      if (head == NULL) {
         head = tail = node;
      } else {
         tail->next = node;
         tail = node;
      }
      if (node->next != NULL) {
         minHeap.push_back(node->next);
         push_heap(minHeap.begin(), minHeap.end(), comp);
      }
   }
   return head;

}

ListNode* mergeKLists(vector<ListNode*>& lists) {
   // Divide and conquer.
   // return _mergeKLists(lists, 0, lists.size()-1);

   return _mergeKListsViaHeap(lists);
}

void _test() {
   int A[] = {-9,-5,-3,-2,-2,3,7};
   ListNode* listA = construct(A, sizeof(A)/sizeof(int));
   printList(listA);

   int B[] = {-8,-4,-2,-1,-1,2,6};
   ListNode* listB = construct(B, sizeof(B)/sizeof(int));
   printList(listB);

   int C[] = {-7,-3,-1,0,0,1,5};
   ListNode* listC = construct(C, sizeof(C)/sizeof(int));
   printList(listC);

   vector<ListNode*> lists;
   lists.push_back(listA);
   lists.push_back(listB);
   lists.push_back(listC);

   ListNode* newList = mergeKLists(lists);
   printList(newList);
}

int main () {
  _test();
  return 0;
}
