#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

void str_reverse(string str){
    if(str.empty())
        return;
    int length = str.length();
    stack<string> stack;
    string word;
    for(int i = 0; i <= length; ++i) {
        if((str[i] == ' ') || (i == length)) {
            stack.push(word);
            word.clear();
        } else {
            word.push_back(str[i]);
        }
    }
    int word_count = stack.size();
    cout << word_count << " words." <<endl;
    for(int i = 0; i < word_count; ++i) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main() {
    // 仅输出
    string str = "I am a students.";
    str_reverse(str);
    return 0;
}