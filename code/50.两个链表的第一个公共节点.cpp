#include <iostream>
#include <stack>

using namespace std;

typedef struct link_list {
    int data;
    struct link_list *next;
}list;

list* create_list() {
    list* phead = new list;
    phead->data = 1;
    phead->next = nullptr;
    for(int i = 2; i <= 5; ++i) {
        list* pnew = new list;
        pnew->data = i;
        pnew->next = phead;
        phead = pnew;
    }
    return phead;
}

void print_list(list *phead) {
    if(phead == nullptr)
        return;
    while(phead) {
        cout << phead->data << ' ';
        phead = phead->next;
    }
    cout << endl;
}

list* stack_fun(list* phead_1, list* phead_2) {
    if((phead_1 == nullptr) || (phead_2 == nullptr))
        return nullptr;
    stack<list *> stack_1, stack_2;
    while(phead_1) {
        stack_1.push(phead_1);
        phead_1 = phead_1->next;
    }
    while(phead_2) {
        stack_2.push(phead_2);
        phead_2= phead_2->next;
    }
    list* first_common = nullptr;
    while(stack_1.top() == stack_2.top()) {
        first_common = stack_1.top();
        stack_1.pop();
        stack_2.pop();
    }
    return first_common;
}

list* run_point_fun(list* phead_1, list* phead_2) {
    if((phead_1 == nullptr) || (phead_2 == nullptr))
        return nullptr;
    list* pmove_1 = phead_1;
    list* pmove_2 = phead_2;
    int len_1 = 0;
    int len_2 = 0;
    while(pmove_1) {
        ++len_1;
        pmove_1 = pmove_1->next;
    }
    while(pmove_2) {
        ++len_2;
        pmove_2 = pmove_2->next;
    }
    int k = abs(len_1 - len_2);
    if(len_1 > len_2) {
        while(k--) {
            phead_1 = phead_1->next;
        }
    }
    else if(len_2 > len_1) {
        while(k--) {
            phead_2 = phead_2->next;
        }
    }
    list* first_common = nullptr;
    while((phead_1 != nullptr) && (phead_2 != nullptr)) {
        if(phead_1 != phead_2) {
            phead_1 = phead_1->next;
            phead_2 = phead_2->next;
        }
        if (phead_1 == phead_2) {
            first_common = phead_1;
            break;
        }
    }
    return first_common;
}

int main() {
    list* phead_1 = create_list();
    list* phead_2 = phead_1;
    for(int i = 6; i <= 10; ++i) {
        list* pnew = new list;
        pnew->data = i;
        pnew->next = phead_2;
        phead_2 = pnew;
    }
    print_list(phead_1);
    print_list(phead_2);
    list* p_common_1 = stack_fun(phead_1, phead_2);
    cout << p_common_1->data << endl;
    list* p_common_2 = run_point_fun(phead_1, phead_2);
    cout << p_common_2->data << endl;
    return 0;
}