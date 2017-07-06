#include <iostream>
#include <stack>

using namespace std;

// 定义模板类，形式template <typename T>或者template <class T>
template <typename  T>
class new_queue {
public:
    // 构造函数析构函数
    new_queue(void){};
    ~new_queue(void){};
    // 操作类型为通用类型
    void append_tail(const T &node);
    T delete_head();
private:
    stack<T> stack1;
    stack<T> stack2;
};
// 使用T的地方都需要先加上template <typename  T>
template <typename  T>
void new_queue<T>::append_tail(const T& node) {
    stack1.push(node);
}
template <typename T>
T new_queue<T>::delete_head() {
    // 只要stack2为空则先把stack1内容退栈压入
    if(stack2.empty()) {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    // 执行完上一步仍为空，表示队列为空
    if(stack2.empty())
        throw new exception();
    T node = stack2.top();
    stack2.pop();
    return node;
}

int main() {
    new_queue<int> queue;
    queue.append_tail(1);
    queue.append_tail(2);
    cout << queue.delete_head() << endl;
    queue.append_tail(3);
    cout << queue.delete_head() << endl;
    cout << queue.delete_head() << endl;
    // cout << queue.delete_head() << endl;
    return 0;
}