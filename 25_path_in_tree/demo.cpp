
#include "../utils/tree.h"
#include <iostream>
#include <queue>

using namespace std;


void helper(TreeNode* root, vector<TreeNode*> &path, int curSum, int expectSum);


void checkPath(TreeNode* root, int expectSum) {

  vector<TreeNode*> path;
  int curSum = 0;
  helper(root, path, curSum, expectSum);

}


void helper(TreeNode* root, vector<TreeNode*> &path, int curSum, int expectSum) {

  if (root->left == NULL && root->right == NULL) {
    if (curSum + root->val == expectSum) {
      cout<<"exist"<<endl;
    }
    return;
  }

  path.push_back(root);
  if (root->left) {
    helper(root->left, path, curSum+root->val, expectSum);
  }

  if (root->right) {
    helper(root->right, path, curSum+root->val, expectSum);
  }
  path.pop_back();

}



int main() {


  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  int expectSum = 10;
  checkPath(root, expectSum);

}
