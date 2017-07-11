#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool error_null_array = false;

template <typename T> class dynamic_array {
public:
    dynamic_array(){};
    ~dynamic_array(){};
    void insert(T node);
    T get_mid();
private:
    vector<T> min_heap;
    vector<T> max_heap;
};
template <typename T> void dynamic_array<T>::insert(T node) {
    int length = min_heap.size() + max_heap.size();
    if((length & 1) == 0) {
        if((max_heap.size() > 0) && (node < max_heap[0])) {
            max_heap.push_back(node);
            push_heap(max_heap.begin(), max_heap.end(), less<T>());
            node = max_heap[0];
            pop_heap(max_heap.begin(), max_heap.end(), less<T>());
            max_heap.pop_back();
        }
        min_heap.push_back(node);
        push_heap(min_heap.begin(), min_heap.end(), greater<T>());
    }
    else {
        if((min_heap.size() > 0) && (node > min_heap[0])) {
            min_heap.push_back(node);
            push_heap(min_heap.begin(), min_heap.end(), greater<T>());
            node = min_heap[0];
            pop_heap(min_heap.begin(), min_heap.end(), greater<T>());
            min_heap.pop_back();
        }
        max_heap.push_back(node);
        push_heap(max_heap.begin(), max_heap.end(), less<T>());
    }
}
template <typename T> T dynamic_array<T>::get_mid() {
    int length = min_heap.size() + max_heap.size();
    if(length == 0){
        error_null_array = true;
        return -INT32_MAX;
    }
    return ((length & 1) == 1) ? min_heap[0] : ((min_heap[0] + max_heap[0]) / 2);
}

int main() {
    dynamic_array<int> array;
    array.insert(2);
    array.insert(3);
    array.insert(4);
    array.insert(5);
    array.insert(6);
    cout << array.get_mid() << endl;
    return 0;
}