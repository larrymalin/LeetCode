#include <iostream>
#include "functions.h"
#include <vector>

using namespace std;

int minDepth(TreeNode *root) {
  if(!root) return 0;
  int minL = 0; 
  int minR = 0; 
  if(root->left!=NULL) minL = minDepth(root->left);
  if(root->right!=NULL) minR = minDepth(root->right);
  if(minL == 0 && minR ==0) return 1;
  else if(minL == 0) return minR+1;
  else if(minR == 0) return minL+1;
  else return 1+min(minR, minL);
}


int main(){
  TreeNode *root = generateTree(1, 20);
  cout << minDepth(root) << endl;

}
