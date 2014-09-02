#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;

int findHeight(TreeNode *root) {
  if(!root) return 0;
  return max(findHeight(root->left), findHeight(root->right))+1;
}


bool isBalanced(TreeNode *root) {
  if(!root) return true;
  if(isBalanced(root->left) && isBalanced(root->right) 
     && abs(findHeight(root->left)-findHeight(root->right))<=1)
    return true;
  else return false;
}


int main(){
  TreeNode *root = generateTree(1, 20);
  if(isBalanced(root)) 
    cout << "Balanced" << endl;
  else
    cout << "Not Balanced" << endl;

}
