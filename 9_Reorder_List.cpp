#include <iostream>
#include "functions.h"


using namespace std;


ListNode *reverseList(ListNode *head){
  ListNode *tail = head, *curr;
  while(tail->next!=NULL) tail = tail->next;
  while(head!=tail){
    curr = head;
    head = head->next;
    curr->next = tail->next;
    tail->next = curr;
  }
  return tail;
}

int getCnt(ListNode *head){
  int cnt = 0;
  while(head!=NULL){
    cnt++;
    head = head ->next;
  }
  return cnt;
}

void reorderList(ListNode *head) {
  if(!head || !head->next || !head->next->next) return;
  int cnt = getCnt(head);
  int second_half = cnt/2;
  int first_half = cnt - cnt/2;

  //cout << first_half << second_half << endl;
  ListNode *p1 = head;
  while(first_half-->1){
    p1 = p1->next;
  }
  ListNode *p2 = p1->next;
  p1->next = NULL;


  p1 = head;
  p2 = reverseList(p2);

  printList(p1);
  printList(p2);
  ListNode *temp;
  while(p2!=NULL){
    temp = p2;
    p2 = p2->next;
    temp->next = p1->next;
    p1->next = temp;
    p1 = p1->next->next;
  }

}



/*

ListNode *reverseList(ListNode *head){
  if(!head || !head->next) return head;
  ListNode *tail = head;
  while(tail->next!=NULL){
    tail=tail->next;
  }
  ListNode *p = head;
  ListNode *temp;
  while(p!=tail){
    temp = p;
    p = p->next;
    temp->next = tail->next;
    tail->next = temp;
  }
  return tail;
}


ListNode *reorderList(ListNode *head){
  if(!head || !head->next) return head;
  ListNode *forward = head;
  ListNode *backward;
  ListNode *f = forward, *b = NULL;
  ListNode *temp;

  while(f!=NULL && f->next!=NULL){
    temp = f->next;
    f->next = f->next->next; f=f->next;
    temp->next = NULL;  // cut the following links for nodes picked out
    if(!b) {b = temp; backward = b;}
    else {b->next = temp; b = b->next;}
  }

  printList(forward);
  printList(backward);
  backward = reverseList(backward);
  f = forward; 
  printList(backward);
  
  
  while(backward!=NULL){
    b = backward;
    backward = backward->next;
    b->next = f->next;
    f->next = b;
    if(f->next!=NULL) f = f->next->next;
  }
  return forward;
}

*/
int main(){
  ListNode *head = generateList(3, false);
  printList(head);
  reorderList(head);
  printList(head);
  //printList(reorderList(head));
}
