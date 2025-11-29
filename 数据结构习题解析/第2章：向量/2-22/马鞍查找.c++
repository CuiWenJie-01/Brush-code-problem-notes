#include<bits/stdc++.h>

using namespace std;

// 基础版本 - 直接查找
vector<vector<int>> findSaddlePointsBasic(const vector<vector<int>>& matrix) {
    vector<vector<int>> saddlePoints;
    
    if (matrix.empty() || matrix[0].empty()) {
        return saddlePoints;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // 遍历每一行
    for (int i = 0; i < rows; i++) {
        // 找到当前行的最小值
        int rowMin = matrix[i][0];
        vector<int> minCols = {0};
        
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < rowMin) {
                rowMin = matrix[i][j];
                minCols.clear();
                minCols.push_back(j);
            } else if (matrix[i][j] == rowMin) {
                minCols.push_back(j);
            }
        }
        
        // 检查每个最小值是否是其所在列的最大值
        for (int col : minCols) {
            bool isSaddle = true;
            for (int k = 0; k < rows; k++) {
                if (matrix[k][col] > rowMin) {
                    isSaddle = false;
                    break;
                }
            }
            
            if (isSaddle) {
                saddlePoints.push_back({i, col, rowMin});
            }
        }
    }
    
    return saddlePoints;
}

// 优化版本 - 预先计算列最大值
vector<vector<int>> findSaddlePointsOptimized(const vector<vector<int>>& matrix) {
    vector<vector<int>> saddlePoints;
    
    if (matrix.empty() || matrix[0].empty()) {
        return saddlePoints;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // 预先计算每列的最大值
    vector<int> colMax(cols, INT_MIN);
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > colMax[j]) {
                colMax[j] = matrix[i][j];
            }
        }
    }
    
    // 遍历每一行
    for (int i = 0; i < rows; i++) {
        // 找到当前行的最小值
        int rowMin = *min_element(matrix[i].begin(), matrix[i].end());
        
        // 检查该行的每个最小值元素
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == rowMin && matrix[i][j] == colMax[j]) {
                saddlePoints.push_back({i, j, matrix[i][j]});
            }
        }
    }
    
    return saddlePoints;
}

// 打印矩阵
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

// 打印马鞍点
void printSaddlePoints(const vector<vector<int>>& saddlePoints) {
    if (saddlePoints.empty()) {
        cout << "没有找到马鞍点" << endl;
        return;
    }
    
    cout << "找到 " << saddlePoints.size() << " 个马鞍点:" << endl;
    for (const auto& point : saddlePoints) {
        cout << "位置: (" << point[0] << ", " << point[1] 
             << "), 值: " << point[2] << endl;
    }
}

// 测试函数
void testSaddlePoints() {
    cout << "=== 马鞍点查找算法测试 ===" << endl << endl;
    
    // 测试用例1: 有马鞍点
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    cout << "矩阵1:" << endl;
    printMatrix(matrix1);
    cout << "基础算法结果: ";
    printSaddlePoints(findSaddlePointsBasic(matrix1));
    cout << "优化算法结果: ";
    printSaddlePoints(findSaddlePointsOptimized(matrix1));
    cout << endl;
    
    // 测试用例2: 有多个马鞍点
    vector<vector<int>> matrix2 = {
        {3, 2, 1},
        {4, 5, 6},
        {9, 8, 7}
    };
    
    cout << "矩阵2:" << endl;
    printMatrix(matrix2);
    cout << "基础算法结果: ";
    printSaddlePoints(findSaddlePointsBasic(matrix2));
    cout << "优化算法结果: ";
    printSaddlePoints(findSaddlePointsOptimized(matrix2));
    cout << endl;
    
    // 测试用例3: 无马鞍点
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {2, 3, 1},
        {3, 1, 2}
    };
    
    cout << "矩阵3:" << endl;
    printMatrix(matrix3);
    cout << "基础算法结果: ";
    printSaddlePoints(findSaddlePointsBasic(matrix3));
    cout << "优化算法结果: ";
    printSaddlePoints(findSaddlePointsOptimized(matrix3));
    cout << endl;
    
    // 测试用例4: 多个相同值的马鞍点
    vector<vector<int>> matrix4 = {
        {2, 2, 2},
        {2, 2, 2},
        {2, 2, 2}
    };
    
    cout << "矩阵4:" << endl;
    printMatrix(matrix4);
    cout << "基础算法结果: ";
    printSaddlePoints(findSaddlePointsBasic(matrix4));
    cout << "优化算法结果: ";
    printSaddlePoints(findSaddlePointsOptimized(matrix4));
    cout << endl;
}

// 性能测试函数
void performanceTest() {
    cout << "=== 性能测试 ===" << endl;
    
    // 创建一个较大的矩阵进行测试
    const int SIZE = 100;
    vector<vector<int>> largeMatrix(SIZE, vector<int>(SIZE));
    
    // 填充测试数据
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            largeMatrix[i][j] = (i * 3 + j * 7) % 100; // 伪随机数
        }
    }
    
    // 添加一个已知的马鞍点
    largeMatrix[SIZE/2][SIZE/2] = -1; // 确保有一个马鞍点
    
    clock_t start, end;
    
    // 测试基础算法
    start = clock();
    auto result1 = findSaddlePointsBasic(largeMatrix);
    end = clock();
    cout << "基础算法耗时: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    
    // 测试优化算法
    start = clock();
    auto result2 = findSaddlePointsOptimized(largeMatrix);
    end = clock();
    cout << "优化算法耗时: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    
    cout << "找到马鞍点数量: " << result1.size() << " (基础), " << result2.size() << " (优化)" << endl;
}

int main() {
    // 运行功能测试
    testSaddlePoints();
    
    // 运行性能测试
    performanceTest();
    
    return 0;
}