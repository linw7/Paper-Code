#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// 找出全部，改变数组，时间O(nlogn)，空间O(1)
void sort_version(int *arr) {
    sort(arr, arr + 7);
    for(int i = 0; i < 7; ++i) {
        int j;
        for(j = 1; arr[i] == arr[i + j]; ++j);
        if(j != 1){
            cout << arr[i] << endl;
            i = i + j - 1;
        }
    }
}

// 找出全部，不改变数组，时间O(n)，空间O(n)
void hash_version(int *arr, int length) {
    map<int, int> map;
    // for(auto : arr)
    for(int i =  0; i < length; ++i) {
        ++map[arr[i]];
    }
    for(auto var : map) {
        if (var.second != 1)
            cout << var.first << endl;
    }
}

// 只找一个，可以改变数组，时间O(n)，空间O(1)
bool solution(int *arr, int length, int *dest) {
    // int length = sizeof(arr);
    // 输入是否有效
    if(arr == nullptr || length <= 0)
        return false;
    // 变量是否符合本方法
    for(int i = 0; i < length; ++i)
        if(arr[i] < 0 || arr[i] > length - 1)
            return false;
    for(int i = 0; i < length; ++i) {
        while(i != arr[i]) {
            if(arr[i] == arr[arr[i]]) {
                *dest = arr[i];
                return true;
            }
            int temp =  arr[i];
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }
    return false;
}

int main() {
    int arr[7] = {2 ,3, 1, 0, 2, 5, 3};
    int *dest = new int;
    // int length = sizeof(arr);
    int length = sizeof(arr) / sizeof(int);
    // sort_version(arr);
    // hash_version(arr, length);
    solution(arr, length, dest);
    cout << *dest << endl;
    return 0;
}