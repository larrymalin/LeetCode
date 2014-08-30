//#include "dataStructure.h"
//#include <iostream>
#include "functions.h"

using namespace std;


ListNode *insertionSortList(ListNode *head) {
  if (head == NULL || head->next == NULL) return head;
  ListNode *p = head;
  ListNode *runner = head;
  ListNode *pre_runner = NULL;
  while(p!=NULL){
    if(p->next!=NULL && p->next->val < p->val){
      runner = head;
      pre_runner = NULL;
      while(runner!=p->next){
	if(runner->val >= p->next->val){
	  ListNode *tempNode = p->next;
	  p->next = p->next->next;
	  tempNode->next = runner;
	  if(pre_runner==NULL) 
	    head = tempNode;
	  else 
	    pre_runner->next = tempNode; 
	  break;
	}else{
	  pre_runner = runner;
	  runner = runner->next;
	}
      }
    }
    else
      p = p->next;
  }
  return head;
  
}


int main (){
  ListNode* head = generateList(20, true);
  printList(head);
  printList(insertionSortList(head) );

}
