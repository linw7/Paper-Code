#include <iostream>

using namespace std;

// 双指针法
void adjust_number(int *array, int length, bool (*func)(int)) {
    if(array == nullptr || length <=0)
        return;
    int front = 0;
    int rear = length - 1;
    while(front < rear) {
        while((!func(array[front])) && (front < rear))
            front += 1;
        while((func(array[rear])) && (front < rear))
            rear -= 1;
        int temp = array[front];
        array[front++] = array[rear];
        array[rear++] = temp;
    }
    for(int i = 0; i < 9; ++i) {
        cout << array[i] <<endl;
    }
}

bool check(int n) {
    return (n & 0x01 == 0);
}

int main() {
    int array[10] = {4, 2, 3, 1, 8, 5, 6, 0, 9};
    adjust_number(array, 10, check);
    return 0;
}