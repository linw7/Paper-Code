#include <iostream>
#include <algorithm>

using namespace std;

// 基于双指针
bool exist_sum(int *array, int length, int num) {
    if((array == nullptr) && (length <= 0))
        return false;
    int begin = 0;
    int end = length - 1;
    while(begin < end) {
        if(array[begin] + array[end] == num)
            return true;
        else if(array[begin] + array[end] < num)
            begin += 1;
        else
            end -= 1;
    }
    return false;
}

// 基于二分查找
bool binary_search(int *array, int begin, int end, int num) {
    if((array == nullptr) || (begin > end))
        return false;
    while(begin <= end) {
        int mid = (begin + end) / 2;
        if(num == array[mid])
            return true;
        else if(num < array[mid])
            end = mid - 1;
        else
            begin = mid + 1;
    }
    return false;
}

bool exist_search(int *array, int length, int num) {
    for(int i = 0; i < length; ++i) {
        if(binary_search(array, i + 1, length - 1, num - array[i]))
            return true;
    }
    return false;
}

int main() {
    int num;
    cin >> num;
    int array[6] = {1, 2, 4, 7, 11, 15};
    int length = sizeof(array) / sizeof(int);
    bool exist = exist_sum(array, length, num);
    cout << exist << endl;
    bool exist_search_sum = exist_search(array, length, num);
    cout << exist_search_sum << endl;
    return 0;
}