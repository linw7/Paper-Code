#include <iostream>

using namespace std;

// 递归二分查找
int binary_search_recursion(int *array, int length, int k, int begin, int end) {
    if((array == nullptr) || (length <= 0) || (begin > end))
        return -1;
    int mid = (begin + end) / 2;
    int mid_data = array[mid];
    if(mid_data == k)
        return mid;
    else if(mid_data > k)
        return binary_search_recursion(array, length, k, begin, mid - 1);
    else
        return binary_search_recursion(array, length, k, begin + 1, end);
}

// 迭代二分查找
int binary_search_iteration(int *array, int length, int k, int begin, int end) {
    if((array == nullptr) || (length <= 0) || (begin > end))
        return -1;
    // 注意可以取等
    while(begin <= end) {
        int mid = begin + ((end - begin) >> 2);
        if(array[mid] == k)
            return mid;
        else if(array[mid] > k)
            end = end - 1;
        else 
            begin = begin + 1;
    }
    return -1;
}

int get_first_k(int *array, int length, int k, int begin, int end) {
    if((array == nullptr) || (length <= 0) || (begin > end))
        return -1;
    int mid = (begin + end) / 2;
    int mid_data = array[mid];
    if(mid_data == k) {
        if(mid == 0)
            return mid;
        if((mid > 0) && (array[mid - 1] != k))
            return mid;
        else
            return get_first_k(array, length, k, begin, mid - 1);
    }
    else if(mid_data > k)
        return get_first_k(array, length, k, begin, end - 1);
    else
        return get_first_k(array, length, k, begin + 1, end);
}

int get_last_k(int *array, int length, int k, int begin, int end) {
    if((array == nullptr) || (length <= 0) || (begin > end))
        return -1;
    int mid = (begin + end) / 2;
    int mid_data = array[mid];
    if(mid_data == k) {
        if(mid == length - 1)
            return mid;
        if((array[mid + 1] != k) && (mid < length - 1))
            return mid;
        else
            return get_last_k(array, length, k, mid + 1, end);

    }
    else if(mid_data > k)
        return get_last_k(array, length, k, begin, end - 1);
    else
        return get_last_k(array, length, k, begin + 1, end);
}

int main() {
    int array[8] = {1, 2, 3, 3, 3, 3, 4, 5};
    int length = sizeof(array) / sizeof(int);
    int k = 3;
    int first_k = get_first_k(array, length, k, 0, length - 1);
    int last_k = get_last_k(array, length, k, 0, length - 1);
    // check valid
    if((first_k > -1) && (last_k > -1)
        cout << last_k - first_k + 1<< endl;
    return 0;
}