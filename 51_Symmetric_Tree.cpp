#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;


bool isSameTree(TreeNode *r1, TreeNode *r2) {
  if(!r1 && !r2) return true;
  else if(!r1 && r2!=NULL || !r2 && r1!=NULL) return false;
  if(r1->val!=r2->val) return false;
  return isSameTree(r1->left, r2->right) && isSameTree(r1->right, r2->left);
}



bool isSymmetricTree(TreeNode *root) {
  if(!root) return true;
  return isSameTree(root->left, root->right);
}

int main(){
  TreeNode *root = generateTree(1, 20);


  if(isSymmetricTree(root)) 
    cout << "Symmetric Tree" << endl;
  else
    cout << "Not Symmetric Tree" << endl;

}
