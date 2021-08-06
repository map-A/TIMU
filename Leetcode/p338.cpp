#include "bits/stdc++.h"

using namespace std;
vector<int> countBits(int num) {
    vector<int>dp(num+1,0);
    for(int i=0;i<=num;i++){
        dp[i] = dp[i&(i-1)] +1;
        //dp[i] = dp[i>>1]+(i&1);
    }
    return dp;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}