#include "bits/stdc++.h"

using namespace std;
bool is_repeat(string &s){
    char vis[26];
    memset(vis,0,sizeof(26));
    for(auto i:s){
        if(vis[i-'a']==1){
            return true;
        }
        vis[i-'a'] = 1;
    }
    return false;
}
void backtrace(vector<string>& arr,int k,string tmp,int &ret){
    for(int i=k;i<arr.size();i++){
        string  cc(tmp);
        cc+=arr[i];
        if(is_repeat(cc)){
            backtrace(arr,i+1,tmp,ret);
        }
        else{
            ret =max(ret,(int)cc.size());
            backtrace(arr,i+1,cc,ret);
        }
    }
}
int maxLength(vector<string>& arr) {

    int ret = 0;
    for(int i=0;i<arr.size();i++){
        backtrace(arr,i,"",ret);

    }

    return ret;
}

int main() {
    vector<string> arr = {"a", "abc", "d", "de", "def"};
    int ret = maxLength(arr);
    return 0;
}