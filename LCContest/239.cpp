#include "bits/stdc++.h"

using namespace std;
int getMinDistance(vector<int>& nums, int target, int start) {
    int ret = INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==target){
            ret = min(ret,abs(start-i));
        }
    }
    return ret;
}


bool dfs(int index,long prev,int cnt,string &s,int n){
    if(index==n){
        return cnt>1;
    }
    long cur=0;
    for(int i=index;i<n;i++){
        cur=cur*10+(s[i]-'0');
        if(cnt==0||cur==prev-1){
            if(dfs(i+1,cur,cnt+1,s,n)){
                return true;
            }
        }
    }
    return false;
}
bool splitString(string s) {
    int prev = INT_MAX;
    int n = s.size();
    return dfs(0,0,0,s,n);
}

int getMinSwaps(string num, int k) {
    string num_k = num;
    for (int i = 0; i < k; ++i) {
        next_permutation(num_k.begin(), num_k.end());
    }

    int n = num.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (num[i] != num_k[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (num[j] == num_k[i]) {
                    for (int k = j - 1; k >= i; --k) {
                        ++ans;
                        swap(num[k], num[k + 1]);
                    }
                    break;
                }
            }
        }
    }

    return ans;
}


int main() {

    return 0;
}