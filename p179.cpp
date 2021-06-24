#include "bits/stdc++.h"

using namespace std;
static bool cmp(string &a,string &b){
    int n = min(a.size(),b.size());
    for(int i=0;i<n;i++){
        if(a[i]>b[i]) return true;
        else if(a[i]<b[i]) return false;
    }
    if(a.size()>n){
        string tmp = a.substr(n);
        return cmp(tmp,b);
    }
    else if(b.size()>n){
        string tmp = b.substr(n);
        return cmp(a,tmp);
    }
    return false;
}
string largestNumber(vector<int> &nums) {
    vector<string> tmp;
    for (auto i:nums) {
        tmp.push_back(to_string(i));
    }
    sort(tmp.begin(), tmp.end(), cmp);
    string ret;
    for (auto &i:tmp) {
        ret += i;
    }
    if(ret[0]=='0') return "0";
    return ret;
}
int main() {
    vector<int> nums = {34323,3432};
    auto ret = largestNumber(nums);
    return 0;
}