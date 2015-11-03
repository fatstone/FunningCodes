/*
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 */
#include <iostream>
#include <map>

using namespace std;

class LRUCache{
   struct item_t {
      int key;
      int val;
      struct item_t* next;
      struct item_t* prev;
      item_t(int k, int v):key(k), val(v), next(NULL), prev(NULL) {}
   };

   map<int, item_t*> hashMap;
   item_t* head;
   item_t* tail;
   int _capacity;
   int _currNums;

   void item_unlink(item_t* it) {
      if (head == it) {
         head = it->next;
      }
      if (tail == it) {
         tail = it->prev;
      }
      if (it->next) {
         it->next->prev = it->prev;
      }
      if (it->prev) {
         it->prev->next = it->next;
      }
      hashMap.erase(it->key);
      _currNums--;
   }

   void item_link(item_t* it) {
      it->prev = NULL;
      it->next = head;

      if (it->next) {
         it->next->prev = it;
      }

      head = it;
      if (tail == NULL) {
         tail = it;
      }

      hashMap[it->key] = it;
      _currNums++;
   }

   item_t* findItem(int key) {
      item_t* it = NULL;
      if (hashMap.count(key) > 0) {
         it = hashMap[key];
      }
      return it;
   }

   void updateItem(item_t* it) {
      item_unlink(it);
      item_link(it);
   }

   void doEviction() {
      if (_currNums < _capacity) {
         return;
      }
      if (tail != NULL) {
         item_unlink(tail);
      }
   }

public:
   LRUCache(int capacity) {
      head = tail = NULL;
      _capacity = capacity;
      _currNums = 0;
   }
   
   int get(int key) {
      int res = -1;
      item_t* it = findItem(key);
      if (it != NULL) {
         updateItem(it);
         res = it->val;
      }
      return res;
   }
   
   void set(int key, int value) {
      item_t* it = findItem(key);
      if (it != NULL) {
         it->val = value;
         updateItem(it);
      } else {
         item_t* it = new item_t(key, value);
         doEviction();
         item_link(it);
      }
   }
};

void _test() {
   int capacity = 3;
   LRUCache* cache = new LRUCache(capacity);
   cache->set(1, 100);
   cache->set(2, 200);
   cache->set(3, 300);

   int val = cache->get(2);
   cout << "expected: " << 200 << ", got: " << val << '\n';

   val = cache->get(1);
   cout << "expected: " << 100 << ", got: " << val << '\n';

   val = cache->get(3);
   cout << "expected: " << 300 << ", got: " << val << '\n';

   cache->set(4, 400);
   val = cache->get(2);
   cout << "expected: " << -1 << ", got: " << val << '\n';
}

int main (int argc, char* argv[]) {
  _test();
  return 0;
}
