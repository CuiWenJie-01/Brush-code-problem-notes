#include <bits/stdc++.h>
using namespace std;

// 函数：判断是否能将集合划分为两个和相等的子集
// 参数：S - 正整数集合（vector），target - 每个子集的目标和（即总和的一半）
bool canPartition(const vector<int>& S, int target) {
    int n = S.size();
    // 创建一个布尔型动态规划表 dp，大小为 (target+1)
    // dp[j] 表示是否能从 S 的前 i 个元素中选出子集，使和恰好为 j
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : S) {
        for (int j = target; j >= num; j--) {
             // 从 target 到 num-1 倒序更新dp数组，避免重复使用同一元素
            if (dp[j - num]) {
                dp[j] = true;
                if (j == target) return true;
            }
        }
    }
    return dp[target];
}

int main() {
    vector<int> electoral_votes = {54, 38, 29, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    /*
     accumulate函数
     默认形式：执行加法运算
     自定义形式：可以指定任何二元运算
    */
    int total_votes = accumulate(electoral_votes.begin(), electoral_votes.end(), 0);
    
    if (total_votes % 2 != 0) {
        cout << "总和不是偶数，无法平分" << endl;
        return 1;
    }
    
    int target = total_votes / 2;
    if (canPartition(electoral_votes, target)) {
        cout << "可以划分为两个总和均为 " << target << " 的子集" << endl;
    } else {
        cout << "无法划分" << endl;
    }
    
    return 0;
}