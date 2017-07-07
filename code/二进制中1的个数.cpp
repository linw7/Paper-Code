#include <iostream>

using namespace std;

// 移位
int count_1(int n) {
    int count = 0;
    int shift = 1;
    for(int i = 0; i < 32; ++i) {
        if(n & shift)
            ++count;
        shift = shift << 1;
    }
    return count;
}

// 一个数减一再与本身取与，会把最右边的1置0
int count_2(int n) {
    int count = 1;
    while(n = (n & (n - 1))) {
        ++count;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << count_1(n) << endl;
    cout << count_2(n) << endl;
    return 0;
}