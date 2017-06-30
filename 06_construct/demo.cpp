
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

#define LEFT 1
#define RIGHT 2

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct NodeTag {
    TreeNode *node;
    int tag;
    NodeTag(TreeNode* n, int t) : node(n), tag(t) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int len = preorder.size();
      TreeNode* root = recursive(preorder, inorder, 0, len-1, 0, len-1);
      return root;
    }

    TreeNode* recursive(
      vector<int>& preorder, vector<int>& inorder,
      int preStart, int preEnd, int inStart, int inEnd) {

      if (preStart > preEnd)
        return NULL;
    
      int rootVal = preorder[preStart];

      TreeNode* root = new TreeNode(rootVal);

      if (preStart == preEnd)
        return root;

      int pos = -1;
      for(int i = inStart; i<=inEnd; i++) {
        if(inorder[i] == rootVal) {
          pos = i;
          break;
        }
      }

      int leftTreeNum = pos - inStart;
      root->left = recursive(preorder, inorder, preStart+1, preStart+leftTreeNum, inStart, pos-1);
      root->right = recursive(preorder, inorder, preStart+leftTreeNum+1, preEnd, pos+1, inEnd);

      return root;
    }

    void printTree(TreeNode* root) {
    
      if (root == NULL)
        return;

      deque<TreeNode*> q = deque<TreeNode*>();
      q.push_back(root);
      int num = 1;

      while(num > 0) {
        TreeNode* p = q.front();
        q.pop_front();

        if (p == NULL) {
          cout<<"null ";
          q.push_back(NULL);
          q.push_back(NULL);
        }
        else {
          cout<<p->val<<" ";
          num--;

          q.push_back(p->left);
          q.push_back(p->right);

          if(p->left)
            num++;
          if(p->right)
            num++;
        }

      }

      cout<<endl;
    }


    void travelPreOrderWithStack(TreeNode* root) {
    
      TreeNode* p = root;
      stack<TreeNode*> s = stack<TreeNode*>();

      while(!s.empty() || p) {
      
        if(p) {
          cout<<p->val<<" ";
          s.push(p);
          p = p->left;
        }
        else {
          p = s.top();
          s.pop();
          p = p->right;
        }

      }

      cout<<endl;
    }

    void travelInOrderWithStack(TreeNode* root) {
    
      TreeNode* p = root;
      stack<TreeNode*> s = stack<TreeNode*>();

      while(!s.empty() || p) {
      
        if(p) {
          s.push(p);
          p = p->left;
        }
        else {
          p = s.top();
          s.pop();
          cout<<p->val<<" ";
          p = p->right;
        }

      }

      cout<<endl;
    }

    void travelPostOrderWithStack(TreeNode* root) {
    
      TreeNode* p = root;
      NodeTag* n;
      stack<NodeTag*> s = stack<NodeTag*>();

      while(!s.empty() || p) {
      
        if(p) {
          n = new NodeTag(p, LEFT);
          s.push(n);
          p = p->left;
        }
        else {
          n = s.top();
          if(n->tag == LEFT) {
            p = n->node->right;
            n->tag = RIGHT;
          }
          else {
            cout<<n->node->val<<" ";
            s.pop();
            p = NULL;
          }
        }

      }

      cout<<endl;
    }

    void travelPostOrder(TreeNode* root) {
    
      TreeNode* p = root;
      NodeTag* n;
      stack<NodeTag*> s = stack<NodeTag*>();

      while(true) {
      
        while(p) {
          n = new NodeTag(p, LEFT);
          s.push(n);
          p = p->left;
        }

        n = s.top();
        s.pop();
        p = n->node;

        int count = 0;
        while(n->tag == RIGHT) {
          // cout<<p->val<<" ";
          count++;

          if(s.empty()) {
            cout<<endl;
            return;
          }
          else {
            n = s.top();
            s.pop();
            p = n->node;
          }
        }
        cout<<count<<endl;

        n->tag = RIGHT;
        s.push(n);
        p = p -> right;

      }

      cout<<endl;
    }
};


int main() {

  vector<int> preorder = {1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 6};

  Solution demo = Solution();
  TreeNode* root = demo.buildTree(preorder, inorder);

  demo.printTree(root);

  demo.travelPreOrderWithStack(root);
  demo.travelInOrderWithStack(root);
  demo.travelPostOrderWithStack(root);
  demo.travelPostOrder(root);

}
