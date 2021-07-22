#include "bits/stdc++.h"

using namespace std;

int coinCombine(vector<int>&coins,int total){
    vector<int>dp(total+1,INT_MAX);
    dp[0] = 0;
    for(int i=0;i<coins.size();i++){
        int coin = coins[i];
        for(int j=coin;j<=total;j++){
            dp[j] = min(dp[j],dp[j-coin]+1);
        }
    }
    return dp[total];
}
int main() {
    string line;
    vector<int> vec;
    string temp;
    //每次读取一整行
    while(getline(cin, line)){
        //创建字符串流stringstream对象
        stringstream ss(line);

        //根据指定字符分割字符串
        while(getline(ss, temp, ',')){
            vec.push_back(stoi(temp));
        }
        break;
    }

    int total;
    cin>>total;
    int ret = coinCombine(vec,total);
    cout<<ret;
    return 0;
}