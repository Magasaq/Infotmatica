#include <iostream>

using namespace std;

struct Node {
  char value;
  Node* left_child = nullptr;
  Node* right_child = nullptr;
};

class Tree {
public:

  Tree(Node* root_) : root(root_) {}

  Tree(char value) {
    root = new Node;
    root->value = value;
  }

  Node* AddLeft_Child(Node* parent) {
    parent->left_child = new Node;
    return parent->left_child;
  }
  Node* AddRight_Child(Node* parent) {
    parent->right_child = new Node;
    return parent->right_child;
  }

  ~Tree() {
    Delete(root);
  }

  void Print_Tree(Node* node) const {
    if(node == nullptr) return;
    if(node->left_child != nullptr) Print_Tree(node->left_child);
    cout << node->value << endl;
    if(node->right_child != nullptr) Print_Tree(node->right_child);
    return;
  }

  Node* root = nullptr;
private:

  void Delete(Node* node) {
    if(node->left_child != nullptr) Delete(node->left_child);
    if(node->right_child != nullptr) Delete(node->right_child);

    delete node;
    return;
  }

};


int main()
{
    Tree tree('g');
    Node* a_l = tree.AddLeft_Child(tree.root);
    Node* a_r = tree.AddRight_Child(tree.root);
    a_r->value = 'l';
    a_l->value = 'f';
    Node* b_l = tree.AddLeft_Child(a_l);
    Node* b_r = tree.AddRight_Child(a_l);
    b_l->value = 'h';
    b_r->value = 'n';
    Node* c = tree.AddLeft_Child(a_r);
    c->value = 'j';
    tree.Print_Tree(tree.root);
    return 0;
}
