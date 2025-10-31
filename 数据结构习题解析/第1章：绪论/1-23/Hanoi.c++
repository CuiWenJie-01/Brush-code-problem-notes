#include<bits/stdc++.h>
using namespace std;

// 定义Disk结构体
struct Disk {
    int size;
    Disk(int s = 0) : size(s) {}
};

// 为每个栈添加名称标识
string getStackName(stack<Disk>* stackPtr) {
    // 注意：这里使用静态变量保存栈的标识符
    static map<stack<Disk>*, string> stackNames;
    static bool initialized = false;
    
    if (!initialized) {
        initialized = true;
    }
    
    if (stackNames.find(stackPtr) == stackNames.end()) {
        // 如果还没有分配名称，则根据调用顺序分配 x, y, z
        if (stackNames.empty()) {
            stackNames[stackPtr] = "x";
        } else if (stackNames.size() == 1) {
            stackNames[stackPtr] = "y";
        } else {
            stackNames[stackPtr] = "z";
        }
    }
    
    return stackNames[stackPtr];
}

// 移动磁盘的函数
void move(stack<Disk>& from, stack<Disk>& to) {
    if (!from.empty()) {
        Disk disk = from.top();
        from.pop();
        to.push(disk);
        cout << "Move disk " << disk.size << " from " << getStackName(&from) << " to " << getStackName(&to) << endl;
    }
}

void hanoi(int n, stack<Disk>& Sx, stack<Disk>& Sy, stack<Disk>& Sz) {
    if (n > 0) {
        hanoi(n - 1, Sx, Sz, Sy);
        move(Sx, Sz);
        hanoi(n - 1, Sy, Sx, Sz);
    }
}

int main() {
    int n = 3; // 设置汉诺塔的层数
    stack<Disk> Sx, Sy, Sz; // 创建三个栈，分别代表A、B、C三根柱子
    
    // 初始化起始栈Sx，将盘子按从大到小的顺序放入
    for (int i = n; i >= 1; i--) {
        Sx.push(Disk(i));
    }
    
    cout << "开始解决" << n << "层汉诺塔问题：" << endl;
    hanoi(n, Sx, Sy, Sz);
    
    return 0;
}