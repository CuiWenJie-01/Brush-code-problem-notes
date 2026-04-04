#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Queen {
    int x, y; // 坐标
    Queen(int xx = 0, int yy = 0) : x(xx), y(yy) {}

    // 核心判定：检查当前皇后是否与另一个皇后冲突
    bool operator==(const Queen& q) const {
        return (x == q.x)               // 同行（理论上迭代逻辑已规避）
            || (y == q.y)               // 同列
            || (abs(x - q.x) == abs(y - q.y)); // 同对角线（斜率为1或-1）
    }
};

void placeQueens(int N) {
    vector<Queen> stack; // 存放已放置的皇后
    Queen q(0, 0);       // 从(0,0)开始试探
    int solutions = 0;

    while (q.x < N) { // 修改条件，只要还有行没试完就继续
        // 尝试在当前行的每一列放置
        if (q.y >= N) { 
            // 如果这一行找遍了都没位置
            if (stack.empty()) break; // 如果栈已空，说明所有可能性都已尝试
            q = stack.back(); // 回溯到上一行
            stack.pop_back();
            q.y++;            // 尝试上一行的下一列
        } else {
            // 检查当前位置 q 是否与栈中已有的皇后冲突
            bool collide = false;
            for (const auto& existing : stack) {
                if (existing == q) {
                    collide = true;
                    break;
                }
            }

            if (!collide) { // 不冲突
                stack.push_back(q); // 进栈
                q.x++;              // 进到下一行
                q.y = 0;            // 从第0列开始试
                
                if (stack.size() == (size_t)N) {
                    solutions++; // 找到一个解
                    // 找到解后，回溯继续寻找下一个解
                    q = stack.back(); // 回溯一行
                    stack.pop_back();
                    q.x--; // 回到上一行
                    q.y++; // 尝试下一列
                }
            } else {
                q.y++; // 冲突，尝试当前行的下一列
            }
        }
    }
    cout << "共找到 " << solutions << " 个解。" << endl;
}

int main() {
    placeQueens(8);
    return 0;
}