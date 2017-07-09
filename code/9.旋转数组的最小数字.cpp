#include <iostream>
#include <vector>

using namespace std;

// 顺序遍历
int find_one_by_one(int *arr, int length) {
    int min = INT32_MAX;
    if((arr != nullptr) && (length > 0)) {
        for(int i = 0; i < length; ++i) {
            if(min > arr[i])
                min = arr[i];
        }
        return min;
    }
    return min;
}

// 折半缩小范围
int find_part(int *arr, int length) {
    int min = INT32_MAX;
    if((arr != nullptr) &&(length > 0)) {
        int p1 = 0;
        int p2 = length - 1;
        while(arr[p1] > arr[p2]) {
            if (p1 + 1 == p2)
                return arr[p2];
            int mid = (p1 + p2) / 2;
            (arr[mid] >= arr[p1]) ? (p1 = mid) : (p2 = mid);
        }
    }
    return min;
}

int main() {
    int arr[5] = {3, 4, 5, 1, 2};
    // int min = find_one_by_one(arr, 5);
    // int min = find_part(arr, 5);
    // cout << min;
    return 0;
}