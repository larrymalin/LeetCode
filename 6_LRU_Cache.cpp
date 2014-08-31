#include <iostream>
#include <map>
#include "dataStructure.h"

#include <stdlib.h>
using namespace std;

class LRUCache{

  struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int k, int v, Node* p, Node* n):key(k), val(v), pre(p), next(n){}
    Node(int k, int v):key(), val(v){}
  };

public:

  int cap;
  map<int, Node*> dataInCache;
  Node* head;
  Node* tail;

  LRUCache(int capacity) {
    cap = capacity;
    head = NULL;
    tail = NULL;
    dataInCache.clear();
  }

  void  moveNode(Node *node){
    if(node == tail) return;
    else if(node == head){
      head = head->next;
      head->pre = NULL;
    }
    else{
      node->pre->next = node->next;
      node->next->pre = node->pre;
    }
    node->pre = tail;
    tail->next = node;
    tail = tail->next;
  }

  void removeNode(Node* node){
    head = head->next;
    if(head!=NULL) head->pre = NULL;
  }

  void insertNode(Node *node){
    if(head==NULL){
      head = node;
      tail = node;
    }else{
      tail->next = node;
      node->pre = tail;
      tail = tail->next;
    }
  }



    

  int get(int key) {
    if(dataInCache.find(key)!=dataInCache.end()){
      moveNode(dataInCache[key]);
      return dataInCache[key]->val;
    }else
      return -1;
  }

  void set(int key, int value) {
    if(dataInCache.find(key)!=dataInCache.end()){
      moveNode(dataInCache[key]);    
      dataInCache[key]->val = value;
    }else{  // add new item in, kick the LRU item
      if(dataInCache.size()==cap){
	dataInCache.erase(head->key);
	removeNode(head);
      }
      Node *newNode = new Node(key, value);
      insertNode(newNode);
      dataInCache[key] = newNode;
    }
  }
};

int main(){

  LRUCache cache(1);
  //  cache = LRUCache(5);
  cache.set(2, 1);
  cout << cache.get(1) << endl;
  /*
  cache.set(3, 2);
  cout << cache.get(2) << endl;
  cout << cache.get(3) << endl;


    cache.set(2, 6);
    cache.set(1, 5);
    cache.set(5, 9);
    cache.set(4, 8);
    cache.set(3, 7);
    cout << cache.get(6) << endl;
    cout << cache.get(2) << endl;
    cache.set(6, 10);
    cout << cache.get(1) << endl;
    cout << cache.get(6) << endl;
  */
}
