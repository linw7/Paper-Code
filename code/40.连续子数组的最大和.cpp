#include <iostream>

using namespace std;

int subsum_max(int *array, int length) {
    if((array == nullptr) || (length <= 0))
        return -INT32_MAX;
    int max = array[0];
    for(int i = 1; i < length; ++i) {
        if(max >= 0) {
            if(array[i] >= 0)
                max = max + array[i];
            else
                continue;
        }
        else
            max = array[i];
    }
    return max;
}

int main() {
    int array[8] = {1, -2, 3, 10, 4, 7, 2, -5};
    cout << subsum_max(array, 8);
    return 0;
}