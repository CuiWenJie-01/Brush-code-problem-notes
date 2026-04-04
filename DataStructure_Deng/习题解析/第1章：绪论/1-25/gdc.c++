#include <iostream>
using namespace std;

// 中华更相减损术
__int64 gcdCN(__int64 a, __int64 b) {
    // 前提：a > 0, b > 0
    int r = 0; // 记录共同的2的幂因子

    // 步骤1：同时去除 a 和 b 的公因子 2
    while (!((a & 1) || (b & 1))) {
        a >>= 1;
        b >>= 1;
        r++;
    }

    // 步骤2：分别去除 a 或 b 中多余的因子 2
    while (!(a & 1)) a >>= 1;
    while (!(b & 1)) b >>= 1;

    // 步骤3：核心循环 —— 更相减损
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a << r; // 最终结果乘以 2^r
}

// 欧几里得算法
__int64 gcdEuclidean(__int64 a, __int64 b) {
    while (b != 0) {
        __int64 temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    __int64 a = 48, b = 18;
    cout << "gcdCN(" << a << ", " << b << ") = " << gcdCN(a, b) << endl;
    cout << "gcdEuclidean(" << a << ", " << b << ") = " << gcdEuclidean(a, b) << endl;
    return 0;
}