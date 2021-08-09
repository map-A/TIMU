#include "bits/stdc++.h"

using namespace std;

vector<vector<int> >ret;
void backtrace(vector<int>&tmp,vector<int>&nums,int index) {
    if (tmp.size()==nums.size()){
        ret.push_back(tmp);
        return;
    }
    for (int i=index;i<nums.size();i++) {
        tmp.push_back(nums[i]);
        backtrace(tmp,nums,i+1);
        tmp.pop_back();
    }
}
vector<vector<int> > permute(vector<int> &num) {
    vector<int>tmp;
    backtrace(tmp,num,0);
    return ret;
}

int main() {
    vector<int>nums = {1,2,3};
    auto ret = permute(nums);
    return 0;
}