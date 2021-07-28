#include "bits/stdc++.h"

using namespace std;
string maxValue(string n, int x) {
    //检查是否为负数
    int flag = 1;
    if(n[0]=='-') flag=-1;
    if(flag==1){
        //正数的情况
        int i;
        for(i=0;i<n.size();i++){
            //找到第一个比x小的位置,在其前面插入
            if(n[i]-'0'<x){
                n.insert(i,to_string(x));
                break;
            }
        }
        if(i==n.size())n.append(to_string(x));
    }
    else{
        //负数的情况
        int i;
        for(i=1;i<n.size();i++){
            //找到第一个比x大的位置
            if(n[i]-'0'>x){
                n.insert(i,to_string(x));
                break;
            }
        }
        if(i==n.size()){
            n.insert(i,to_string(x));
        }
    }
    return n;
}
int main() {
    string n="-87";
    int x = 9;
    string ret = maxValue(n,x);
    return 0;
}