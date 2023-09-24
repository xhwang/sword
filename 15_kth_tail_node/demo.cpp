
#include "../utils/list.h"
#include <iostream>

using namespace std;


ListNode* getKthTailNode(ListNode* root, int k) {

  if (root == NULL || k == 0)
    return NULL;

  ListNode* ahead = root;

  for(int i=0; i<k-1; i++) {

    if(ahead->next != NULL)
      ahead = ahead -> next;
    else
      return NULL;
  }

  ListNode* behind = root;
  
  while(ahead->next != NULL) {
    ahead = ahead ->next;
    behind = behind->next;
  }

  return behind;
}


int main() {

  vector<int> vals = {1, 2, 4, 5};

  ListNode* root = buildList(vals);

  printList(root);

  ListNode* rel = getKthTailNode(root, 1);
  cout<<rel->val<<endl;

  return 0;
}
