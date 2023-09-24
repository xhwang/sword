#include <iostream>

using namespace std;

struct Node {
  Node *next;
  const char *data;
};

void printLink(const Node *root) {
  const Node *p = root;
  while (p != nullptr) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

void addNode(Node *root, Node *n) {
  Node *p = root;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = n;
}

Node *reverseLink(Node *root) {
  if (nullptr == root)
    return nullptr;

  Node *p = root;
  while (p->next != nullptr) {
    Node *temp = p->next;
    p->next = temp->next;
    temp->next = root;
    root = temp;
  }

  return root;
}

int main() {
  Node *root = new Node();
  root->data = "A";

  Node *t;
  t = new Node();
  t->data = "B";

  addNode(root, t);
  printLink(root);

  t = new Node();
  t->data = "C";
  addNode(root, t);
  printLink(root);

  t = new Node();
  t->data = "D";
  addNode(root, t);
  printLink(root);

  root = reverseLink(root);
  printLink(root);
}
