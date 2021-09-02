#include "bits/stdc++.h"

using namespace std;
int n;
bool dfs(int index,long prev,int cnt,string &s){
    if(index==n){
        return cnt>1;
    }
    long cur=0;
    for(int i=index;i<n;i++){
        cur=cur*10+(s[i]-'0');
        if(cnt==0||cur==prev-1){
            if(dfs(i+1,cur,cnt+1,s)){
                return true;
            }
        }
    }
    return false;
}
bool splitString(string s) {
    int prev = INT_MAX;
    n = s.size();
    return dfs(0,0,0,s);
}

int main() {
    string s = "9080701";
    return splitString(s);
    return 0;
}