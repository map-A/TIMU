#include "bits/stdc++.h"

using namespace std;


void backtrack(vector<int>& candidates, int target,int sum,vector<int>&tmp,int start,vector<vector<int>>&ret){
    if(sum==target) ret.push_back(tmp);
    else if(sum>target) return;
    else{
        for(int i=start;i<candidates.size();i++){
            if(sum+candidates[i]<=target){
                tmp.push_back(candidates[i]);
                backtrack(candidates,target,sum+candidates[i],tmp,i,ret);
                tmp.pop_back();
            }
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>tmp;
    vector<vector<int>>ret;
    sort(candidates.begin(),candidates.end());
    backtrack(candidates,target,0,tmp,0,ret);
    return ret;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}