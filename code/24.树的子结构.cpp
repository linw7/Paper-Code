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

Tree* create_tree_b(Tree* tree_a) {
    Tree* p = new Tree;
    p->data = 8;
    p->right_tree = nullptr;
    p->left_tree = tree_a;
}

bool tree_b_has_tree_a(Tree* tree_b, Tree* tree_a) {
    if(tree_a == nullptr)
        return true;
    if(tree_b == nullptr)
        return false;
    if(tree_a->data != tree_b->data)
        return false;
    return (tree_b_has_tree_a(tree_b->left_tree, tree_a->left_tree) && tree_b_has_tree_a(tree_b->right_tree, tree_a->right_tree));
}

bool has_subtree(Tree* tree_b, Tree* tree_a) {
    bool result = false;
    if((tree_a != nullptr) && (tree_b != nullptr)) {
        // 定根
        if (tree_a->data == tree_b->data)
            result = tree_b_has_tree_a(tree_b, tree_a);
        // 递归左子树
        if (!result)
            result = has_subtree(tree_b->left_tree, tree_a);
        // 递归右子树
        if (!result)
            result = has_subtree(tree_b->right_tree, tree_a);
    }
    return result;
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
    Tree* tree_b = create_tree_b(tree_a);
    // print_tree(tree_a);
    // print_tree(tree_b);
    bool has_sub = has_subtree(tree_b, tree_a);
    cout << has_sub << endl;
}