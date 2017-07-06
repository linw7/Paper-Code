#include <iostream>
#include <list>
#include <stack>

using namespace std;

void print_reverse_list(list<int> link_list) {
    if (!link_list.empty()) {
        stack<int> stack;
        for (auto it = link_list.begin(); it != link_list.end(); ++it) {
            stack.push(*it);
        }
        while (!stack.empty()) {
            cout << stack.top() << endl;
            stack.pop();
        }
    }
}

int main() {
    list<int> link_list = {1, 2, 3, 4, 5};
    // print_reverse_list(link_list);
    return 0;
}