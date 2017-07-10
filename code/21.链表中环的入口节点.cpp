#include <iostream>

using namespace std;

struct link_list {
    int data;
    struct link_list *next;
};

// 创建链表
link_list* create_circle_link_list() {
    link_list* p = new struct link_list;
    link_list* pmove = p;
    link_list* pcircle = nullptr;
    p->next = nullptr;
    p->data = 1;
    for(int i = 2; i <= 10; ++i) {
        link_list* pnew = new link_list;
        pnew->data = i;
        pnew->next = nullptr;
        pmove->next = pnew;
        pmove = pnew;
        if(i == 7)
            pcircle = pmove;
    }
    pmove->next = pcircle;
    return p;
}

// 返回是否有环（快慢指针碰撞）
link_list* check_link_list_has_circle(link_list* phead) {
    if(phead != nullptr) {
        link_list* pfast = phead;
        link_list* pslow = phead;
        while(pfast != nullptr) {
            pslow = pslow->next;
            pfast = pfast->next;
            if(pfast == nullptr)
                return false;
            pfast = pfast->next;
            if(pfast == pslow) {
                return pslow;
            }
        }
    }
    return nullptr;
}

// 计算环的大小（再次路过碰撞点）
unsigned int calculate_link_list_length(link_list *pbumb) {
    unsigned int k = 1;
    link_list* pfast = pbumb->next->next;
    link_list* pslow = pbumb->next;
    while(pslow != pbumb) {
        ++k;
        pfast = pfast->next->next;
        pslow = pslow->next;
    }
    return k;
}

// 找到换入口（快指针先走环长）
link_list *find_point(link_list *phead, unsigned int k) {
    link_list* pfast = phead;
    link_list* pslow = phead;
    while(k--)
        pfast = pfast->next;
    while(pfast != pslow) {
        pfast = pfast->next;
        pslow = pslow->next;
    }
    return pfast;
}

void print_link_list(link_list* phead) {
    while(phead != nullptr) {
        cout << phead->data << endl;
        phead = phead->next;
    }
}

int main() {
    link_list* phead = create_circle_link_list();
    link_list* pbumb = check_link_list_has_circle(phead);
    unsigned int k = 0;
    if(pbumb)
        k = calculate_link_list_length(pbumb);
    link_list* ppoint = find_point(phead, k);
    cout << ppoint->data << endl;
}