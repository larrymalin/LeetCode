#include <iostream>
#include "functions.h"

using namespace std;


bool hasCycle(ListNode *head){
  if(!head || !head->next || !head->next->next) return false; // cycle has at least 3 nodes
  ListNode* fast = head;
  ListNode* slow = head;
  while(fast!=NULL && slow!=NULL && fast->next!=NULL){
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow) return true;
  }
  return false;
  
}


ListNode *generateLoopedList(ListNode *head, int size){
  if(!head) return head;
  ListNode *tail, *p = head;
  int cnt = size/2;
  while(p->next!=NULL){
    if(cnt--==0) tail = p;
    p = p->next;
  }
  p->next = tail;
  return head;
}


int main(){

  ListNode  *head=generateList(10, false);
  printList(head);
  if(hasCycle(head)) cout << "The Linked List has a Cycle" << endl;
  else cout << "The Linked List has no Cycle" << endl;

  head = generateLoopedList(head, 10);
  //  printList(head);
  if(hasCycle(head)) cout << "The Linked List has a Cycle" << endl;
  else cout << "The Linked List has no Cycle" << endl;

}
