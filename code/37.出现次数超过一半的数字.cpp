#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void count_by_sort(int *array, int n) {
    if((array != nullptr) && (n >= 1))
    sort(array, array + n);
    for(int i = 1; i < n; ++i) {
        int count = 1;
        if(array[i] == array[i + 1]) {
            while(array[i] == array[i + 1]) {
                ++count;
                ++i;
            }
        }
        if(count >= (n / 2)) {
            cout << array[i] << endl;
            return;
        }
    }
}

void count_by_hash(int *array, int n) {
    if((array != nullptr) && (n >= 1)) {
        map<int, int> map;
        for (int i = 0; i < n; ++i)
            ++map[array[i]];
        int num = -INT32_MAX;
        int max = -INT32_MAX;
        for (auto var : map) {
            if (max < var.second) {
                num = var.first;
                max = var.second;
            }
        }
        if (max >= (n / 2))
            cout << num << endl;
    }
}

void count_by_cal(int *array, int n) {
    if((array != nullptr) && (n >= 1)) {
        map<int, int> stat;
        int result = array[0];
        int times = 1;
        for(int i = 1; i < n; ++i) {
            if(times == 0) {
                result = array[i];
                times = 1;
            }
            if(array[i] == result)
                ++times;
            else
                --times;
        }
        if(times > 0)
            cout << result << endl;
    }
}

int main() {
    int array[9] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    count_by_sort(array, 9);
    count_by_hash(array, 9);
    count_by_cal(array, 9);
    return 0;
}