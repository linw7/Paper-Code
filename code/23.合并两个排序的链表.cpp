#include <iostream>

using namespace std;

struct link_list {
    int  data;
    link_list *next;
};

link_list *create_link_list(int n) {
    link_list* phead = new link_list;
    link_list* pmove = phead;
    if(phead != nullptr) {
        phead->data = n;
        phead->next = nullptr;
    }
    for(int i = n + 1; i < n + 5; ++i) {
        link_list *pnew = new link_list;
        if(pnew != nullptr) {
            pnew->data = i;
            pnew->next = nullptr;
            pmove->next = pnew;
            pmove = pnew;
        }
    }
    return phead;
}

// 迭代处理
link_list* merge_link_list(link_list *phead_1, link_list* phead_2) {
    link_list *pmove = nullptr;
    link_list *p = nullptr;
    if((phead_1 != nullptr) && (phead_2 != nullptr)) {
        if(phead_1->data < phead_2->data) {
            pmove = phead_1;
            p = pmove;
            phead_1 = phead_1->next;
        }
        else {
            pmove = phead_2;
            p = pmove;
            phead_2 = phead_2->next;
        }

        while((phead_1 != nullptr) && (phead_2 != nullptr)) {
            if(phead_1->data < phead_2->data) {
                pmove->next = phead_1;
                pmove = phead_1;
                phead_1 = phead_1->next;
            }
            else {
                pmove->next = phead_2;
                pmove = phead_2;
                phead_2 = phead_2->next;
            }
        }
        if(phead_1 != nullptr)
            pmove->next = phead_1;
        else
            pmove->next = phead_2;
    }
    return p;
}

// 递归处理
link_list *merge(link_list *phead1, link_list *phead2) {
    if(phead1 == nullptr)
        return phead2;
    else if(phead2 == nullptr)
        return phead1;
    link_list *p = nullptr;
    if(phead1->data < phead2->data) {
        p = phead1;
        p->next = merge(phead1->next, phead2);
    }
    else {
        p = phead2;
        p->next = merge(phead1, phead2->next);
    }
    return p;
}

int main() {
    int i, j;
    cin >> i >> j;
    link_list *phead_1 = create_link_list(i);
    link_list *phead_2 = create_link_list(j);
    // link_list* p = merge(phead_1, phead_2);
    // link_list *phead = merge_link_list(phead_1, phead_2);
    return 0;
}