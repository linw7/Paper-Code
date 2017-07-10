#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int part(int *array, int start, int end) {
    int low = start;
    int high = end;
    int pivot = array[low];
    while(low < high) {
        if(pivot > array[high]) {
            swap(array, low, high);
            ++low;
        }
        else if(pivot <= array[low]) {
            swap(array, low, high);
            --high;
        }
    }
    return low;
}

// O(n)，但会修改原序列
void kth_by_part(int *array, int n, int k) {
    if((array == nullptr) || (k <= 0) || (n <= 0) || (n < k))
        return;
    int start = 0;
    int end = n - 1;
    int index = part(array, start, end);
    while(index != (k - 1)) {
        if(index > (k - 1)) {
            end = index - 1;
            index = part(array, start, end);
        }
        if(index < (k - 1)) {
            start = index + 1;
            index = part(array, start, end);
        }
    }
    for(int i = 0; i < k; ++i)
        cout << array[i] << endl;
}

// O(nlogk)，不修改原序列，适合大数据
void get_least_number(const vector<int>& data, multiset<int, greater<int>> ini_set, int k) {
    if((k < 1) || data.size() < k)
        return;
    for(auto it = data.begin(); it != data.end(); ++it) {
        // 集合够存直接存
        if(ini_set.size() < k)
            ini_set.insert(*it);
        else {
            // 不够存时，若新数小于当前集合最大数，删去最大数并加入新元素
            // multiset<int, greater<int>>最大数位于ini_set.begin()
            auto it_greatest = ini_set.begin();
            if(*it < *(ini_set.begin())) {
                ini_set.erase(it_greatest);
                ini_set.insert(*it);
            }
        }
    }
    for(auto it = ini_set.begin(); it != ini_set.end(); ++it)
        cout << *it << endl;
}
int main() {
    int array[9] = {5, 8, 7, 9, 1, 4, 2, 7, 11};
    kth_by_part(array, 9, 3);
    multiset<int, greater<int>> ini_set;
    vector<int> vec = {5, 8, 7, 9, 1, 4, 2, 7, 11};
    get_least_number(vec, ini_set, 3);
    return 0;
}