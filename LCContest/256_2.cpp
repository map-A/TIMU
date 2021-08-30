#include "bits/stdc++.h"

using namespace std;
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
int main() {

    return 0;
}