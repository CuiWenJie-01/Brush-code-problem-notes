//逆向思维提示： 不要试图直接构造新字符串，而是从原字符串中提取单词再倒序输出
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="hello world C++";
    /**
     * stringstream 是一个字符串流类，它把字符串当作输入输出流来处理，
     * 可以像处理文件流或控制台流一样处理字符串。
    */
    stringstream ss(s);//创建字符串流对象
    string word;//定义存储单词的变量
    vector<string> words;

    //提取所有单词
    while(ss>>word){//每次从ss中提取一个单词到word中
        words.push_back(word);
    }
    //倒序输出
    for(int i=words.size()-1;i>=0;i--){
        cout<<words[i];
        if(i>0) cout<<" ";
    }
    cout<<endl;
    return 0;
}