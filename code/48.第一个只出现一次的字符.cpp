#include <iostream>
#include <cstring>

using namespace std;

char first_uni(char *str, int length) {
    if((str == nullptr) || (length <=0))
        throw exception();
    int pos[26];
    for(int i = 0; i < 26; ++i)
        pos[i] = -INT32_MAX;
    for(int i = 0; i < length; ++i){
        if(pos[str[i] - 'a'] == -INT32_MAX)
            pos[str[i] - 'a'] = i;
        else if(pos[str[i] - 'a'] == INT32_MAX)
            continue;
        else
            pos[str[i] - 'a'] = INT32_MAX;
    }
    int offset = 0;
    int min = INT32_MAX;
    for(int i = 0; i < 26; ++i) {
        if((pos[i] != -INT32_MAX) && (pos[i] != INT32_MAX)) {
            if(pos[i] < min) {
                min = pos[i];
                offset = i;
            }
        }
    }
    for (int i = 0; i < 26; i++)
        if((pos[i] != -INT32_MAX) && (pos[i] != INT32_MAX))
            cout << "post[i] = " << pos[i] << "  i = " << i << endl;
    if(min == INT32_MAX)
        return '\0';
    return ('a' + offset);
}

int main() {
    char str[] = "kkggggggggggogrowxv";
    cout << first_uni(str, strlen(str));
    return 0;
}