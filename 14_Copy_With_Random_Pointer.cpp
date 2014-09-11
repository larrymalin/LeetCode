#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;

struct RandomListNode{
  int label;
  RandomListNode *next, random;
  RandomListNode(int l):label(l), next(), random(){}
};



RandomListNode *copyRandomList(RandomListNode *head){
  if(!head) return head;
  map<RandomListNode*, RandomListNode*> mapping;
  RandomListNode *newHead = new RandomListNode(head->label);
  mapping[head] = newHead;
 
  RandomListNode *p1 = head, p2 = newHead;
  while(p1->next!=NULL){
    RandomListNode *node = new RandomListNode(p1->next->label);
    p2->next = node; p2 = p2->next;
    mapping[p1->next] = node;    
    p1 = p1->next;
  }
  p1 = head;
  while(p1!=NULL){
    mapping[p1]->random = mapping[p1->random];
    p1 = p1->next;
  }
  
  return newHead;
}


int main(){
  RandomListNode *head = NULL;
  RandomListNode *newHead = copyRandomList(head);
  
}
