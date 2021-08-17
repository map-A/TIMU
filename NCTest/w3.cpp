#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ret;
    sort(intervals.begin(), intervals.end());
    ret.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= ret.back()[1]) {
            ret.back()[1] = max(ret.back()[1], intervals[i][1]);
        } else {
            ret.push_back(intervals[i]);
        }
    }
    return ret;
}
int solve3(vector<vector<int>>&interval){
    auto ret = merge(interval);
    int ans=0;
    for(auto i:ret){
        ans+=i[1]-i[0];
    }
    cout<<ans;
    return ans;
}
//
//int main() {
//    int n;
//    cin>>n;
//    vector<vector<int>>interval(n,vector<int>(2,0));
//    int start,con;
//
//    for(int i=0;i<n;i++){
//        scanf("%d %d",&start,&con);
//        interval[i][0] = start;
//        interval[i][1] = start+con;
//    }
//    solve3(interval);
//
//    return 0;
//}




vector<int>factor(int N){
    vector<int>ret;
    for(int i=1;i<sqrt(N);i++){
        if(N%i==0){
            ret.push_back(i);
        }
    }
    return ret;
}
void help(int N,int time,vector<int>&times){
    //小王先找出所有因数，选择因数和为奇数，然后减去其中一个
    if(N==1){
        times.push_back(time);
        return;
    }
    vector<int>fc =factor(N);
    for(auto i:fc){
        if((i+N/i)%2==1){
            N = N-i;
            help(N,time+1,times);
        }

    }
    //times.push_back(time);
}
void solve2(int N){
    vector<int>times;
    help(N,0,times);
    for(auto i:times){
        if(i%2!=1){
            cout<<"win";
            return;
        }
    }
    cout<<"lose";

}


void solve(int N){
    if(N==2){
        cout<<"win";
        return;
    }
    if(N==3){
        cout<<"lose";
        return;
    }
    vector<int>dp(N+1,0);
    dp[2] = 1;
    dp[3] = 0;
    for(int i=4;i<=N;i++){
        for(int j=2;j<i;j++){
            if(i%(i-j)==0&&dp[j]==0){
                dp[i] = 1;
            }
        }
    }
    if(dp[N]==1){
        cout<<"win";
    }
    else{
        cout<<"lose";
    }
    return;
}
int main() {
    int T=0;
    cin>>T;
    while(T--){
        int N;
        scanf("%d",&N);
        solve(N);
    }
    return 0;
}