#include "bits/stdc++.h"

using namespace std;
void solve(vector<pair<int,int>>&goods){
    int n = goods.size();
    int total_score = 0;
    for(auto i:goods){
        total_score+=i.first;
    }
    ///dp[i][j]选择了第i个物品后总的socore为j，
     vector<vector<bool>>dp(n,vector<bool>(total_score+1,false));
    dp[0][0] = true;
    for(int i=1;i<n;i++){
        for(int j=0;j<total_score+1;j++){
            for(auto k:goods){
                if(j>=k.first&&i>k.second){
                    dp[i][j] = dp[i-1][j]|dp[i-1][j-k.first];
                }
            }
        }
    }

}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        scanf("%d\n",&N);
        vector<pair<int,int>>goods(N); //score-last
        for(int i=0;i<N;i++){
            scanf("%d %d",&goods[i].first,&goods[i].second);
        }
        solve(goods);

    }

    return 0;
}