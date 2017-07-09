#include <iostream>

using namespace std;

struct list_node {
    int data;
    list_node *next;
};

list_node* reverse_list(list_node* phead) {
    list_node *p_reverse = nullptr;
    if(phead != nullptr) {
        list_node *p_pre = nullptr;;
        list_node *p_now = phead;
        list_node *p_next = p_now->next;
        while(p_now != nullptr) {
            p_next = p_now->next;
            if(p_next == nullptr)
                p_reverse = p_now;
            p_now->next = p_pre;
            p_pre = p_now;
            p_now = p_next;
        }
    }
    return p_reverse;
}

list_node* create_link_list() {
    list_node* pmove = new struct list_node;
    list_node* p = pmove;
    pmove->data = 1;
    pmove->next = nullptr;
    for(int i = 2; i <= 5; ++i) {
        list_node* p_new = new list_node;
        p_new->data = i;
        p_new->next = nullptr;
        pmove->next = p_new;
        pmove = p_new;
    }
    return p;
}

int main() {
    list_node* phead = create_link_list();
    list_node* p = reverse_list(phead);
    while(p != nullptr) {
        cout << p->data;
        p = p->next;
    }
    return 0;
}