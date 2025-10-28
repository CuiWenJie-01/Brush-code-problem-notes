//逆向思维提示： 不要统计每个数字出现次数，而是利用异或运算的性质
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={4,1,2,1,2};
    int result=0;

    //利用异或运算：a^a=0,a^0=a
    for(int num:nums){
        result^=num;
    }
    cout<<result<<endl;
    return 0;
}
/*
 * 为什么这种方法有效？
在数组 [4, 1, 2, 1, 2] 中：

所有数字异或在一起：4 ^ 1 ^ 2 ^ 1 ^ 2
利用交换律重排：4 ^ (1 ^ 1) ^ (2 ^ 2)
因为 a ^ a = 0，所以：4 ^ 0 ^ 0
因为 a ^ 0 = a，所以：4
*/
// result = 0 ^ 4 = 4
// result = 4 ^ 1 = 5,用二进制算
// result = 5 ^ 2 = 7
// result = 7 ^ 1 = 6  (注意: 4^1^2^1 = 4^2, 因为1^1=0)
// result = 6 ^ 2 = 4  (注意: 4^1^2^1^2 = 4, 因为1^1=0, 2^2=0)

// 实际上就是: 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4 ^ (1^1) ^ (2^2) = 4 ^ 0 ^ 0 = 4