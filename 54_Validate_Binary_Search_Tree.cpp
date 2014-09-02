#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;

bool inorderTraversal(TreeNode *root, TreeNode *&lastOneBefore) {
  if(!root) return true;
  if(!inorderTraversal(root->left, lastOneBefore)) return false;
  if(lastOneBefore!=NULL && lastOneBefore->val >= root->val) return false;
  lastOneBefore = root;
  if(!inorderTraversal(root->right, lastOneBefore)) return false;
  return true;
}


bool isValidBST(TreeNode *root) {
  if(!root) return true;
  TreeNode *lastOneBefore = NULL;
  return inorderTraversal(root, lastOneBefore);
}


int main(){
  TreeNode *root = generateTree(1, 20);
  if(isValidBST(root)) 
    cout << "Valid BST" << endl;
  else
    cout << "Not Valid BST" << endl;

}
