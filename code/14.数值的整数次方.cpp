#include <iostream>

using namespace std;

// 全局变量标记错误类型
bool g_invalid = false;

// 浮点数0判断
bool  equal_zero(double base) {
    g_invalid = false;
    if((base < 0.000001) && (base > -0.000001))
        return true;
    return false;
}

double exe_pow(double base, int exponent) {
    double num = 1.0;
    for(int i = 1; i <= exponent; ++i)
        num = num * base;
    return num;
}

double power(double base, int exponent){
    // 先判断可能导致除0情况
    if(equal_zero(base) && (exponent < 0)) {
        g_invalid = true;
        return 0.0;
    }
    if(exponent > 0)
        return exe_pow(base, exponent);
    else
        // 负指数取倒数
        return  (1.0 / exe_pow(base, exponent));
}

int main() {
    double base;
    int exponent;
    cin >> base >>exponent;
    cout << power(base, exponent) << endl;
    return 0;
}