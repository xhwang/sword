
#include "../utils/tree.h"
#include <iostream>
#include <queue>

using namespace std;


void printLevelTree(TreeNode* root) {

  if (not root)
    return;

  queue<TreeNode*> q;

  q.push(root);

  while (not q.empty()) {
  
    TreeNode* node = q.front();
    q.pop();

    cout<<node->val<<" ";

    if (node->left)
      q.push(node->left);

    if (node->right)
      q.push(node->right);
  }

  cout<<endl;

}


int main() {


  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  printLevelTree(root);

}
