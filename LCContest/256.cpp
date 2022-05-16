#include "bits/stdc++.h"

using namespace std;
int minimumDifference(vector<int>& nums, int k) {
    if(k==1) return 0;
    int ret = INT_MAX;
    sort(nums.begin(),nums.end());
    for(int i=0;i+k-1<nums.size();i++){
        ret = min(ret,nums[i+k-1]-nums[i]);
    }
    return ret;

}

static bool cmp(string& a,string& b){
    if(a.size()>b.size()){
        return true;
    }
    else if(a.size()<b.size()){
        return false;
    }
    return a>b;
}
string kthLargestNumber(vector<string>& nums, int k) {

    sort(nums.begin(),nums.end(),cmp);
    cout<<nums.size();
    return nums[k-1];
}
int minSessions(vector<int>& tasks, int sessionTime) {
    sort(tasks.begin(),tasks.end());

}

int main() {

    return 0;
}