#include <iostream>
#include <cstring>
#include <set>

using namespace std;

// liner * set，O(nlogn)
int max_uni(char *str, int length) {
    if((str == nullptr) || (length <= 0))
        throw exception();
    int cur_len = 0;
    int max_len = 0;
    multiset<char> c_set;
    for(int i = 0; i < length; ++i) {
        if(!(c_set.count(str[i]))) {
            c_set.insert(str[i]);
            ++cur_len;
        }
        else {
            if(cur_len >= max_len)
                max_len = cur_len;
            c_set.clear();
            cur_len = 1;
        }
    }
    if(cur_len >= max_len)
        max_len = cur_len;
    return max_len;
}

int max_dp(char* str, int length) {
    if((str == nullptr) || (length <= 0))
        throw exception();
    int cur_len = 0;
    int max_len = 0;
    int pos[26];
    for(int i = 0; i < 26; ++i)
        pos[i] = -1;
    for(int i = 0; i < length; ++i) {
        int pre_index = pos[str[i] - 'a'];
        if((pre_index < 0) || (i - pre_index > cur_len))
            ++cur_len;
        else {
            if(cur_len > max_len)
                max_len = cur_len;
            cur_len = i - pre_index;
        }
        pos[str[i] - 'a'] = i;
    }

    if(cur_len > max_len)
        max_len = cur_len;
    return max_len;
}
int main() {
    char str[10] = "qwertyuio";
    cout << max_uni(str, strlen(str)) << endl;
    cout << max_dp(str, strlen(str));
    return 0;
}