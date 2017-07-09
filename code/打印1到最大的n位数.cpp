#include <iostream>
#include <cstring>

using namespace std;

bool increment(char *number) {
    int length = strlen(number);
    bool is_overflow = false;
    int takeover = 0;
    for(int i = length - 1; i >= 0; --i) {
        int num = number[i] - '0' + takeover;
        if(i == length - 1)
            ++num;
        if(num <= 9) {
            number[i] = num + '0';
            break;
        }
        else {
            if(i == 0)
                is_overflow = true;
            else {
                takeover = 1;
                num -= 10;
                number[i] = '0' + num;
            }
        }
    }
    return is_overflow;
}

void print_num(char *number) {
    int length = strlen(number);
    for(int i = 0; i < length; ++i) {
        if((number[i] == '0') && (i != length - 1))
            continue;
        else
            printf("%c", number[i]);
    }
    printf("\n");
}

int main() {
    int n;
    cin >> n;
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    while(!increment(number)) {
        print_num(number);
    }
    delete number[];
    return 0;
}