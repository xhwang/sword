
#include "../utils/tree.h"
#include <iostream>

using namespace std;

TreeNode* mirrorTree(TreeNode* root) {

  if (!root)
    return NULL;

  if (root->left == NULL and root->right == NULL) {
    return root;
  }

  TreeNode* temp = root->left;
  root->left = mirrorTree(root->right);
  root->right = mirrorTree(temp);

  return root;
}


int main() {

  TreeNode* root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  printTree(root);
  root = mirrorTree(root);
  printTree(root);

  return 0;
}
