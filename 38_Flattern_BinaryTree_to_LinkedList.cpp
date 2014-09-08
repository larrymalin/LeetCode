#include <iostream>
#include "functions.h"


using namespace std;


TreeNode *findTail(TreeNode *root){
  TreeNode *temp= root;
  if(root==NULL) return root;
  else
    while(temp->right!=NULL) temp = temp->right;
  return temp;
}

void flatten(TreeNode *root){
  if(root==NULL) return;
  if(root->left!=NULL){
    if(root->right==NULL){
      flatten(root->left);
      root->right = root->left;
      root->left = NULL;
    }else{
      flatten(root->left);
      flatten(root->right);
      TreeNode *tail = findTail(root->left);
      tail->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
  }else if(root->left == NULL){
    if(root->right!=NULL) flatten(root->right);
  }
}


int main(){

  TreeNode *root = generateTree(1, 10);
  flatten(root);

}
