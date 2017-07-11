#include <iostream>

using namespace std;

int has_1_count(int num) {
    int abs_num = abs(num);
    int count = 0;
    while(abs_num) {
        if(abs_num % 10 == 1)
            ++count;
        abs_num = abs_num /10;
    }
    return count;
}

int count_1(int *array, int length) {
    if((array == nullptr) || (length <= 0))
        return -INT32_MAX;
    int sum = 0;
    for(int i = 0; i < length; ++i)
        sum = sum + has_1_count(array[i]);
    return sum;
}

int main() {
    int array[8] = {1, -12, 3, 10, 4, 7, 21, 51};
    cout << count_1(array, 8);
    return 0;
}