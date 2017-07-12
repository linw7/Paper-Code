#include <iostream>

using namespace std;

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
}tree;

tree *create_tree() {
    tree *ptree = new tree;
    ptree->data = 0;
    ptree->left = nullptr;
    ptree->right = nullptr;
    return ptree;
}

int tree_height(tree *ptree) {
    if(ptree == nullptr)
        return 0;
    int left_height = tree_height(ptree->left);
    int right_height = tree_height(ptree->right);
    return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

int main() {
    tree *ptree = create_tree();
    int height = tree_height(ptree);
    cout << height << endl;
    return 0;
}