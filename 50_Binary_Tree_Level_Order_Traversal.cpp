#include <iostream>
#include "functions.h"
#include <vector>
#include <queue>

using namespace std;


void traversal(queue<TreeNode*> &level, vector<vector<int> >&result){
  if(level.empty()) return;
  vector<int> valueOfThisLevel;
  queue<TreeNode*> nextLevel;
  while(!level.empty()){
    TreeNode* node = level.front();
    level.pop();
    valueOfThisLevel.push_back(node->val);
    if(node->left!=NULL) nextLevel.push(node->left);
    if(node->right!=NULL) nextLevel.push(node->right);
  }
  if(!valueOfThisLevel.empty()) result.push_back(valueOfThisLevel);
  if(!nextLevel.empty()) traversal(nextLevel, result);

}

vector<vector<int> > levelOrder(TreeNode *root) {
  vector<vector<int> >result;
  if(!root) return result;
  queue<TreeNode*> level;
  level.push(root);
  traversal(level, result);
  return result;
}


int main(){
  TreeNode *root = generateTree(1, 10);
  
  vector< vector<int> > result = levelOrder(root);
  for(int i = 0; i<result.size(); i++){
    for(int j = 0; j< result[i].size(); j++)
      cout << result[i][j] << " ";
    cout << endl;
  }

}
