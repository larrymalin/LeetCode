#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;

bool isSameTree(TreeNode *r1, TreeNode *r2) {
  if(!r1 && !r2) return true;
  else if(!r1 && r2!=NULL || !r2 && r1!=NULL) return false;
  if(r1->val!=r2->val) return false;
  return isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
}

int main(){
  TreeNode *root1 = generateTree(1, 20);
  TreeNode *root2 = generateTree(1, 20);

  if(isSameTree(root1, root2)) 
    cout << "Same Tree" << endl;
  else
    cout << "Not Same Tree" << endl;

}
