#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
  int value;
  ListNode* next;

  ListNode(int v):value(v) {}
};

void printReverseList(ListNode* root) {

  if (root == NULL)
    return;

  stack<ListNode*> nodeStack;

  ListNode* p = root;
  while(p) {
    nodeStack.push(p);
    p = p->next;
  }

  while (!nodeStack.empty()) {
    ListNode* t = nodeStack.top();
    nodeStack.pop();
    cout<<t->value<<" ";
  }

  cout<<endl;

}

int main() {

  ListNode* root = new ListNode(0);

  for(int i=4; i>0;i--) {
    ListNode* t = new ListNode(i);
    ListNode* rootNext = root->next;
    root->next = t;
    t->next = rootNext;
  }

  printReverseList(root);

}
