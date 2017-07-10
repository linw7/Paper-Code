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
    left->data = 4;
    Tree* right = new Tree;
    right->right_tree = right->left_tree = nullptr;
    right->data = 4;
    p->data = 8;
    p->left_tree = left;
    p->right_tree = right;
}

void print_tree(Tree* ptree) {
    if(ptree != nullptr)
        cout << ptree->data << endl;
    if(ptree->left_tree)
        print_tree(ptree->left_tree);
    if(ptree->right_tree)
        print_tree(ptree->right_tree);
}

bool has_one_null(Tree* p) {
    if((p->left_tree == nullptr) && (p->right_tree != nullptr))
        return true;
    if((p->right_tree == nullptr) && (p->left_tree != nullptr))
        return true;
    return false;
}

bool is_symmetrical(Tree* proot) {
    if(proot == nullptr)
        return false;
    if(has_one_null(proot))
        return false;
    if((proot->left_tree == nullptr) && (proot->left_tree == nullptr))
        return true;
    if((proot->left_tree != nullptr) && (proot->right_tree != nullptr)) {
        if(proot->left_tree->data == proot->right_tree->data) {
            return is_symmetrical(proot->left_tree) && is_symmetrical(proot->right_tree);
        }
    }
    return false;
}

int main() {
    Tree* tree_a = create_tree_a();
    // print_tree(tree_a);
    cout << is_symmetrical(tree_a);
}