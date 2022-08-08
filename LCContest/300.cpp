#include "bits/stdc++.h"

using namespace std;
string decodeMessage(string key, string message) {
    vector<int>table(26,-1);
    int index = 0;
    for (auto &i:key) {
        if(i!=' '&&table[i-'a']==-1){
            table[i-'a'] = index;
            index++;
        }
    }
    string ret = "";
    for (auto i:message) {
        if(i!=' '){
            ret+=string(1,'a'+table[i-'a']);
        }
        else{
            ret+=" ";
        }
    }
    return ret;
}


vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>>ret(m,vector<int>(n,-1));
    vector<pair<int,int>>dir  = {{0,1},{1,0},{0,-1},{-1,0}};
    ListNode*p = head;
    int x = 0,y = 0;
    int turn = 0;
    while (p){
        //检测是否应该转向
        if(x>=m||x<0||y>=n||y<0||ret[x][y]!=-1){
            x = x-dir[turn%4].first;
            y = y-dir[turn%4].second;
            turn++;
            x = x+dir[turn%4].first;
            y = y+dir[turn%4].second;
        }
        else{
            ret[x][y] = p->val;
            p = p->next;
            x = x+dir[turn%4].first;
            y = y+dir[turn%4].second;
        }
    }
    return ret;
}


int peopleAwareOfSecret(int n, int delay, int forget) {
    const int mod = 1e9+7;
    vector<long long> x(n+1),y(n+1),z(n+1);
    x[1] = 1;y[1]=0;z[1] = 0;
    for(int i = 2;i<n+1;i++){
        if(i-delay>0)  y[i] = x[i-delay];
        if(i-forget > 0) z[i] = x[i-forget];
        x[i] = (x[i-1]-z[i]+y[i]+mod)%mod;
    }
    return (x[n]-z[n]+mod)%(mod);
}



int main() {

    return 0;
}