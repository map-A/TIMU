#include "bits/stdc++.h"

using namespace std;
static bool cmp(string a,string b){
    if(a.size()>b.size()){
        return true;
    }
    else if(a.size()<b.size()){
        return false;
    }
    else{
        for(int i=0;i<a.size();i++){
            if(a[i]>b[i]) return true;
            else if(a[i]<b[i])  return false;
            else continue;
        }
    }
    return true;
}

string largestOddNumber(string num) {
    string ret = "";
    int n = num.size();
    vector<int>index;
    for(int i=0;i<n;i++){
        if((num[i]-'0')%2==1){
            index.push_back(i);
        }
    }
    for(int i=n;i>0;i--){
        //判断长度为i的
        for(int j=0;j<n-i+1;j++){
            string tmp=num.substr(j,i);

            if(tmp[0]!=0&&(tmp[i-1]-'0')%2==1&&!cmp(ret,tmp)){
                ret = tmp;
            }
        }
        if(ret!="") return ret;
    }
    return ret;

}
int main() {
    string num = "4205";
    auto ret = largestOddNumber(num);
    return 0;
}