#include<bits/stdc++.h>
using namespace std;

// 全局变量用于记录骨牌编号
int tile = 1;
// 棋盘数组，假设最大为16x16
int board[16][16];

// 放置L形骨牌的函数
// 在指定位置放置当前编号的骨牌，并更新骨牌编号
void place(int x, int y, int dx, int dy) {
    // 放置3个骨牌单元（L形由3个单位组成）
    board[x][y] = tile;                           // 中心位置
    board[x + dx][y] = tile;                      // 按方向向量偏移
    board[x][y + dy] = tile;
    tile++;                                       // 更新骨牌编号
}

// L形棋盘覆盖函数
// 参数说明:
// n: 棋盘大小为 2^n × 2^n
// x, y: 当前处理区域的左上角坐标
// dx, dy: 方向向量，用于确定缺失方块的相对位置
void cover(int n, int x, int y, int dx, int dy) {  
    // 基本情况：当棋盘大小为2x2时，直接放置一个L形骨牌
    if (n == 1) {
        place(x, y, dx, dy);
        return;
    }
    
    int s = 1 << (n-1); // 计算子棋盘大小 s = 2^(n-1)
    
    // 在中心位置放置一个L形骨牌
    place(x + dx * (s - 1), y + dy * (s - 1), dx, dy); 
    
    // 递归处理四个子棋盘
    cover(n - 1, x, y, dx, dy);                           // 处理左上子棋盘
    cover(n - 1, x + dx * s, y + dy * s, dx, dy);         // 处理右下子棋盘
    cover(n - 1, x + dx * (2*s - 1), y, -dx, dy);         // 处理右上子棋盘，方向翻转
    cover(n - 1, x, y + dy * (2*s - 1), dx, -dy);         // 处理左下子棋盘，方向翻转
}

// 打印棋盘状态
void printBoard(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "请输入棋盘大小的幂次 n (棋盘大小为 2^n × 2^n): ";
    cin >> n;
    
    // 初始化棋盘
    int size = 1 << n;
    memset(board, 0, sizeof(board));
    
    // 假设右上角缺失（即坐标(0, size-1)位置）
    cout << "棋盘覆盖结果 (0表示缺失方块):" << endl;
    cover(n, 0, 0, 1, -1);  // 从左上角开始，缺失方块在右上角
    board[0][size-1] = 0;   // 标记缺失方块
    
    printBoard(size);
    
    return 0;
}