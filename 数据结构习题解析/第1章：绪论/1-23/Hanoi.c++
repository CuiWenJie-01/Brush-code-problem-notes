#include<bits/stdc++.h>
using namespace std;

// ����Disk�ṹ��
struct Disk {
    int size;
    Disk(int s = 0) : size(s) {}
};

// Ϊÿ��ջ������Ʊ�ʶ
string getStackName(stack<Disk>* stackPtr) {
    // ע�⣺����ʹ�þ�̬��������ջ�ı�ʶ��
    static map<stack<Disk>*, string> stackNames;
    static bool initialized = false;
    
    if (!initialized) {
        initialized = true;
    }
    
    if (stackNames.find(stackPtr) == stackNames.end()) {
        // �����û�з������ƣ�����ݵ���˳����� x, y, z
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

// �ƶ����̵ĺ���
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
    int n = 3; // ���ú�ŵ���Ĳ���
    stack<Disk> Sx, Sy, Sz; // ��������ջ���ֱ����A��B��C��������
    
    // ��ʼ����ʼջSx�������Ӱ��Ӵ�С��˳�����
    for (int i = n; i >= 1; i--) {
        Sx.push(Disk(i));
    }
    
    cout << "��ʼ���" << n << "�㺺ŵ�����⣺" << endl;
    hanoi(n, Sx, Sy, Sz);
    
    return 0;
}