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

tree *kth_node(tree *ptree, int k) {
    if((ptree == nullptr) || (k <= 0))
        return nullptr;
    tree *target = nullptr;
    if(ptree->left != nullptr)
        target = kth_node(ptree->left, k);
    // target为空表示有节点被访问，ptree为指向的节点
    if(target == nullptr) {
        if(k == 1)
            target = ptree;
        k--;
    }
    if(ptree->right != nullptr)
        target = kth_node(ptree->right, k);
    return target;
}

int main() {
    int k;
    cin >> k;
    tree *ptree = create_tree();
    tree *p_kth_node = kth_node(ptree, k);
    cout << p_kth_node->data << endl;
    return 0;
}