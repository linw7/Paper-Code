#include <iostream>
#include <stack>

using namespace std;

bool is_pop_order(const int *push_order, const int *pop_order, int length) {
    bool is_order = false;
    if((push_order != nullptr) && (pop_order != nullptr) && (length > 0)) {
        int i_pop = 0;
        int i_push = 0;
        stack<int> stack;
        // 未pop完数据
        while(i_pop != length) {
            // 栈空则按入栈顺序一直压栈直到栈顶压入第一个出栈序首元素
            while (((stack.empty()) || stack.top() != pop_order[i_pop]))
                stack.push(push_order[i_push++]);
            // 不存在出栈序，返回false，否则栈顶元素出栈
            if (stack.top() != pop_order[i_pop])
                return false;
            else {
                stack.pop();
                ++i_pop;
            }
        }
        if (stack.empty())
            is_order = true;
    }
    return is_order;
}
int main() {
    int push_order[5] = {1, 2, 3, 4, 5};
    int pop_order_1[5] = {4, 5, 3, 2, 1};
    int pop_order_2[5] = {4, 3, 5, 1, 2};
    int pop_order_3[5] = {5, 4, 3, 2, 1};
    cout << is_pop_order(push_order, pop_order_1, (sizeof(pop_order_1) / sizeof(int))) << endl;
    cout << is_pop_order(push_order, pop_order_2, (sizeof(pop_order_2)) / sizeof(int))<< endl;
    cout << is_pop_order(push_order, pop_order_3, (sizeof(pop_order_3)) / sizeof(int))<< endl;
}