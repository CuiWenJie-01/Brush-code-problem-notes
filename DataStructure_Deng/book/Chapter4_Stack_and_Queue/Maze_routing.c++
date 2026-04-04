#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 格子状态
enum Status { UNKNOWN, WALL, BACKTRACKED, ROUTE };
// 移动方向
enum Direction { EAST, SOUTH, WEST, NORTH, NO_WAY };

struct Cell {
    int x, y;
    Status status;
    Direction incoming; // 进入该格子的方向
    Direction outgoing; // 下一步尝试的方向

    Cell(int xx = 0, int yy = 0) : x(xx), y(yy), status(UNKNOWN), incoming(NO_WAY), outgoing(EAST) {}
};

// 简单的迷宫地图：0为通路，1为墙
int mazeMap[7][7] = {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}
};

// 获取相邻格子的辅助函数
Cell* getNeighbor(Cell* current, vector<vector<Cell>>& grid) {
    switch (current->outgoing) {
        case EAST:  return &grid[current->x][current->y + 1];
        case SOUTH: return &grid[current->x + 1][current->y];
        case WEST:  return &grid[current->x][current->y - 1];
        case NORTH: return &grid[current->x - 1][current->y];
        default:    return nullptr;
    }
}

void solveMaze(int startX, int startY, int endX, int endY) {
    int rows = 7, cols = 7;
    vector<vector<Cell>> grid(rows, vector<Cell>(cols));
    
    // 初始化网格状态
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++) {
            grid[i][j].x = i; grid[i][j].y = j;
            grid[i][j].status = (mazeMap[i][j] == 1) ? WALL : UNKNOWN;
        }

    stack<Cell*> s;
    Cell* start = &grid[startX][startY];
    start->status = ROUTE;
    s.push(start);

    while (!s.empty()) {
        Cell* curr = s.top();
        if (curr->x == endX && curr->y == endY) break; // 抵达终点

        if (curr->outgoing != NO_WAY) {
            Cell* next = getNeighbor(curr, grid);
            
            // 尝试四个方向
            if (next && next->status == UNKNOWN) { // 发现新大陆
                next->status = ROUTE;
                next->incoming = curr->outgoing;
                s.push(next);
            }
            // 无论刚才走没走通，当前格子下一次都要换个方向试试
            curr->outgoing = (Direction)(curr->outgoing + 1);
        } else {
            // 四周都走不通，回溯
            curr->status = BACKTRACKED;
            s.pop();
        }
    }

    if (s.empty()) {
        cout << "无解！" << endl;
    } else {
        cout << "找到路径！坐标序列如下：" << endl;
        // 打印路径（由于栈是倒序的，实际应用中可以先存入vector再反向打印）
        while (!s.empty()) {
            Cell* p = s.top();
            cout << "(" << p->x << "," << p->y << ") <- ";
            s.pop();
        }
        cout << "START" << endl;
    }
}

int main() {
    solveMaze(1, 1, 5, 5); // 从(1,1)到(5,5)
    return 0;
}