#include <iostream>
#include <list>

using namespace std;

int the_kth_back_node(list<int> link_list, int k) {
    if((!link_list.empty()) && (k <= link_list.size()) && (k > 0)) {
        auto it_fast = link_list.begin();
        auto it_slow = link_list.begin();
        while(k--)
            ++it_fast;
        while(it_fast != link_list.end()) {
            ++it_fast;
            ++it_slow;
        }
        return *it_slow;
    }
    return INT32_MAX;
}

int main() {
    int k;
    cin >> k;
    list<int> link_list;
    for(int i = 1; i <= 10; ++i)
        link_list.push_back(i);
    cout << the_kth_back_node(link_list, k) << endl;
    return 0;
}