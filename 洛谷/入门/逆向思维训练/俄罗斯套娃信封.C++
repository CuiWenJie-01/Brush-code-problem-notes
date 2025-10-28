#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> envelopes={{5,4},{6,4},{6,7},{2,3}};
    sort(envelopes.begin(),envelopes.end(),[](const vector<int> &a,const vector<int> &b){
        if(a[0]==b[0])//宽度相同时，按高度降序
            return a[1]>b[1];
        return a[0]<b[0];//宽度升序
    });

    //在高度上找最长递增子序列
    vector<int> heights;
    for(auto &envelope:envelopes){
        heights.push_back(envelope[1]);
    }

    vector<int> dp;
    for(int height:heights){
        auto it=lower_bound(dp.begin(),dp.end(),height);//找到第一个大于height的元素
        if(it==dp.end())//到末尾还没找到，将height加入末尾
            dp.push_back(height);// height比所有元素都大，扩展序列
        else
            *it=height;//换找到位置的值，保持最小结尾
    }
    cout<<dp.size()<<endl;
    return 0;
}
