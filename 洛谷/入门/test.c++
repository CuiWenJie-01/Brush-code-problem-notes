#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int d[4]={0,a,b,c};
    sort(d+1,d+4);
    if(d[1]+d[2]<=d[3]){
        cout<<"No triangle"<<endl;
    }
    long long p1=pow(d[1],2);
    long long p2=pow(d[2],2);
    long long p3=pow(d[3],2);
    if(p1+p2 == p3) cout<<"Right triangle"<<endl;
    else if(p1+p2 > p3) cout<<"Acute triangle"<<endl;
    else if(p1+p2 < p3) cout<<"Obtuse triangle"<<endl;
    if(a==b||b==c||a==c) cout<<"Isosecles triangle"<<endl;
    if(a==b&&b==c) cout<<"Equilateral triangle"<<endl;
    return 0;
}