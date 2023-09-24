
#include "../utils/tree.h"
#include <iostream>
#include <queue>

using namespace std;


void helper(TreeNode* root, TreeNode** l);


TreeNode* convert(TreeNode* root) {

  TreeNode* rel = NULL;

  helper(root, &rel);

  while(rel and rel->left) {
    rel = rel->left;
  }

  return rel;
}


// Note: l is the pointer points to the last node
// use a pointer cannot work
//
// TODO:
// 因为不仅要使用 node 的值, node 作为树里的成员
// 它本身的地址也会被使用, 如果使用一级指针,
// 在传递参数时, 拷贝构造新的指针, 虽然值不变,
// 但地址已经不是原来的地址了, 也不是树的node

void helper(TreeNode* root, TreeNode** l) {

  if (not root)
    return;

  helper(root->left, l);

  root->left = *l;
  if (*l)
    (*l)->right = root;
  *l = root;

  helper(root->right, l);
}


int main()
{

  TreeNode* root = new TreeNode(10);

  root->left = new TreeNode(6);
  root->right = new TreeNode(14);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(8);
  root->right->left = new TreeNode(12);
  root->right->right = new TreeNode(16);

  TreeNode* rel = convert(root);

  while(rel) {
    cout<<rel->val<<" ";
    rel = rel->right;
  }
  cout<<endl;

}
