#include <iostream>
//#include "dataStructure.h"
#include <vector>
#include "functions.h"
using namespace std;


void traverse(TreeNode *root, vector<int> &res){
  if(!root) return;
  traverse(root->left, res);
  traverse(root->right, res);
  res.push_back(root->val);
}

vector<int> postOrderTraversal(TreeNode *root){
  vector<int> result;
  if(!root) return result;
  traverse(root, result);
  return result;
}


int main(){
  TreeNode *root = generateTree(1, 10); //  generate binary tree with node 1-10;
  vector<int> result = postOrderTraversal(root);
  printResult(result);
}
