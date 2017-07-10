#include <iostream>

using namespace std;

typedef struct tree Tree;
struct tree {
    int data;
    Tree* right_tree;
    Tree* left_tree;
};

Tree* create_tree_a() {
    Tree* p = new Tree;
    Tree* left = new Tree;
    left->right_tree = left->left_tree = nullptr;
    left->data = 9;
    Tree* right = new Tree;
    right->right_tree = right->left_tree = nullptr;
    right->data = 2;
    p->data = 8;
    p->left_tree = left;
    p->right_tree = right;
}

void exchange(Tree* proot) {
    Tree* ptemp = proot->left_tree;
    proot->left_tree = proot->right_tree;
    proot->right_tree = ptemp;
}

void mirror(Tree* proot) {
    if(proot == nullptr)
        return;
    if((proot->left_tree != nullptr) || (proot->right_tree != nullptr)) {
        exchange(proot);
        mirror(proot->left_tree);
        mirror(proot->right_tree);
    }
    return;
}

void print_tree(Tree* ptree) {
    if(ptree != nullptr)
        cout << ptree->data << endl;
    if(ptree->left_tree)
        print_tree(ptree->left_tree);
    if(ptree->right_tree)
        print_tree(ptree->right_tree);
}

int main() {
    Tree* tree_a = create_tree_a();
    // print_tree(tree_a);
    mirror(tree_a);
    print_tree(tree_a);
}