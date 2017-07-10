#include <iostream>
#include <queue>

using namespace std;

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* create_tree() {
    struct tree* proot = new struct tree;
    struct tree* pleft = new struct tree;
    struct tree* pright = new struct tree;
    proot->data = 10;
    proot->left = pleft;
    proot->right = pright;
    pleft->data = 8;
    pleft->left = nullptr;
    pleft->right = nullptr;
    pright->data = 6;
    pright->left = nullptr;
    pright->right = nullptr;
    return proot;
}

void print_tree_up_to_down(struct tree* proot) {
    if(proot != nullptr) {
        queue<struct tree *> tree_queue;
        tree_queue.push(proot);
        while(!tree_queue.empty()) {
            cout << tree_queue.front()->data << endl;
            if(tree_queue.front()->left != nullptr)
                tree_queue.push(tree_queue.front()->left);
            // 这里不要使用else if
            if(tree_queue.front()->right != nullptr)
                tree_queue.push(tree_queue.front()->right);
            tree_queue.pop();
        }
    }
}

void print_tree(struct tree* proot) {
    if(proot == nullptr)
        return;
    if(proot != nullptr) {
        cout << proot->data << endl;
        print_tree(proot->left);
        print_tree(proot->right);
    }
}

int main() {
    struct tree* proot = create_tree();
    // print_tree(proot);
    print_tree_up_to_down(proot);
    return 0;
}