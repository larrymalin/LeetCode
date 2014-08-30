#include <iostream>
#include <vector>
#include "functions.h"
//#include "dataStructure.h"

using namespace std;


// sort a linked list in O(nlogn) time using constant space complexity
// mergeSort works

ListNode *mergeList(ListNode *h1, ListNode *h2) {
  if(h1 == NULL) return h2;
  if(h2 == NULL) return h1;
  ListNode *newHead = new ListNode(-1);
  ListNode *p = newHead;
  while(h1!=NULL && h2!=NULL){
    if(h1->val <= h2->val) {p->next = h1; h1=h1->next;}
    else {p->next = h2; h2=h2->next;}
    p = p->next;
  }
  if(h1!=NULL) p->next = h1;
  if(h2!=NULL) p->next = h2;
  return newHead->next;
}

ListNode *sortList(ListNode *head) {
  if(head == NULL) return head;
  int cnt = 0; 
  ListNode *p = head;
  while(p!=NULL){
    cnt++;
    p=p->next;
  }
  if(cnt == 1) return head;

  int half = cnt/2;
  ListNode *h1 = head;
  ListNode *h2 = head;
  ListNode *tail;
  while(half-- > 0){
    tail = h2;
    h2=h2->next;
  }

  tail->next = NULL;
  h1 = sortList(h1);
  h2 = sortList(h2);
  return mergeList(h1, h2);
}


int main(){
  ListNode *head = generateList(10, true); // generate Random List
  printList(head);
  printList(sortList(head));
  
}


