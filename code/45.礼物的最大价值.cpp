#include <iostream>

using namespace std;

// greedy, wrong
int max_greedy(int (*array)[4]) {
    if(array == nullptr)
        throw exception();
    int max = array[0][0];
    int pos_i = 0;
    int pos_j = 0;
    while((pos_i != 3) || (pos_j != 3)) {
        if(pos_i == 3) {
            while(pos_j != 3) {
                max += array[pos_i][pos_j + 1];
                pos_j += 1;
            }
        }
        if(pos_j == 3) {
            while(pos_i != 3) {
                max += array[pos_i + 1][pos_j];
                pos_j += 1;
            }
        }
        if((pos_i + 1 <= 3) && (array[pos_i + 1][pos_j] >= array[pos_i][pos_j + 1])) {
            max += array[pos_i + 1][pos_j];
            pos_i += 1;
        }
        if((pos_j + 1 <= 3) && (array[pos_i + 1][pos_j] < array[pos_i][pos_j + 1])){
            max += array[pos_i][pos_j + 1];
            pos_j += 1;
        }
    }
    return max;
}

void ini_arr(int (*count)[4], int (*array)[4]) {
    count[0][0] = array[0][0];
    for(int i = 1; i < 4; ++i)
        count[i][0] = array[i][0] + count[i - 1][0];
    for(int j = 1; j < 4; ++j)
        count[0][j] = array[0][j] + count[0][j - 1];
}

int max_dp(int (*array)[4]) {
    if (array == nullptr)
        throw exception();
    int count[4][4];
    ini_arr(count, array);
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            if(count[i - 1][j] > count[i][j - 1])
                count[i][j] = count[i - 1][j] + array[i][j];
            else
                count[i][j] = count[i][j - 1] + array[i][j];
        }
    }
    return count[3][3];
}

int main() {
    int array[4][4] = {
            {1, 10, 3, 8},
            {12, 2, 9, 6},
            {5, 7, 4, 11},
            {3, 7, 16, 5}
    };
    cout << max_greedy(array) << endl;
    cout << max_dp(array);
    return 0;
}