//逆向思维提示： 不要删除重复元素，而是保留不重复元素
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    if(nums.empty()){
        cout<<0<<endl;
        return 0;
    }
    int j=0;//指向不重复元素位置
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[j]){
            j++;
            nums[j]=nums[i];//保留不重复元素
        }
    }
    cout<<j+1<<endl;//返回长度
    //输出前j+1个元素
    for(int i=0;i<=j;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}