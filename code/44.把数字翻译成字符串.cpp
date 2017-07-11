#include <iostream>
#include <string>

using namespace std;

int to_number(string str, int i) {
    int dig1 = str[i] - '0';
    int dig2 = str[i + 1] - '0';
    return ((dig1 * 10) + dig2);
}

int get_count(string str) {
    int length = str.length();
    int *counts = new int[length];
    counts[length - 1] = 1;
    for(int i = length - 2; i >= 0; --i) {
        int num = to_number(str, i);
        if((num >= 10) && (num <= 25)) {
            if(i < length - 2) {
                counts[i] = counts[i + 1] + counts[i + 2];
                continue;
            }
        }
        counts[i] = counts[i + 1];
    }
    return counts[0];
}

int main() {
    string str = "12215";
    cout << get_count(str);
    return 0;
}