#include<bits/stdc++.h>
using namespace std;
bool compare(const vector<int> &a,const vector<int> &b){
    return a[1]<b[1];// 按结束时间排序
}
int main(){
    vector<vector<int>> intervals={{1,2},{2,3},{3,4},{1,3}};
    //按结束时间排序
    sort(intervals.begin(),intervals.end(),compare);

    int count=0;
    int end=0;
    for(auto interval:intervals){
        if(interval[0]>=end){// 当前区间的开始时间大于等于已结束的区间的结束时间，即不重叠
            count++;
            end=interval[1];
        }
    }
    //总数-保留的=需要删除的
    cout<<intervals.size()-count<<endl;
    return 0;
}