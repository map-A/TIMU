#include "bits/stdc++.h"

using namespace std;

//将字符映射为26进制，然后与操作判断两个字符之间有没有重复的元素
bool  multiply(vector<int>&a,vector<int>&b){
    for(int i=0;i<26;i++){
        if(a[i]&b[i]==1)return false;
    }
    return true;
}
int maxProduct(vector<string>& words) {
    int ret = 0;
    sort(words.begin(),words.end());
    vector<vector<int>>tmp;
    for(auto i:words){
        vector<int>hs_a(26,0);
        for(auto j:i)hs_a[j-'a'] = 1;
        tmp.push_back(hs_a);
    }
    for(int i=0;i<words.size();i++){
        for(int j=i+1;j<words.size();j++){
            if(multiply(tmp[i],tmp[j])){
                int t = words[i].size()*words[j].size();
                ret = max(ret,t);
            }
        }
    }
    return ret;
}

int main() {

    return 0;
}