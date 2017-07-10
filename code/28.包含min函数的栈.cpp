#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class new_stack {
public:
    new_stack(void){};
    T pop();
    void push(const T& node);
    T min();
    ~new_stack(void){};
private :
    stack<T> data_stack;
    stack<T> min_stack;
};
template <typename T>
T new_stack<T>::pop() {
    // 弹出元素前检查栈内是否有元素
    if((!data_stack.empty()) && (!min_stack.empty())) {
        data_stack.pop();
        min_stack.pop();
    }
}
template <typename T>
void new_stack<T>::push(const T& node) {
    data_stack.push(node);
    // 特殊处理min_stack为空情况（注意顺序）
    if(min_stack.empty() || (node < min_stack.top()))
        min_stack.push(node);
    else
        min_stack.push(min_stack.top());
}
template <typename T>
T new_stack<T>::min() {
    if((!data_stack.empty()) && (!min_stack.empty())) {
        return min_stack.top();
    }
}

int main() {
    new_stack<int> *s = new new_stack<int>;
    s->push(1);
    s->push(3);
    s->push(2);
    s->push(5);
    s->pop();
    s->pop();
    cout << s->min() << endl;
}