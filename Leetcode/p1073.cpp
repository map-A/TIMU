#include "bits/stdc++.h"

using namespace std;
vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();
    int ta = min(m,n);
    vector<int>tmp;
    vector<int>ret;
    if(ta==m) tmp = arr2;
    else tmp = arr1;
    int flag1 = 0;
    int flag2 =0;
    for (int i = 0;i<ta;i++) {
        int t = arr1[m-i-1]+arr2[n-i-1]+flag1;
        ret.push_back(t%2);
        if(t==4){
            flag1 = flag2;
            flag2 = 1;
        }
        else if(t>1){
            flag2++;
            flag1 = flag2;
            flag2 = 1;
        }
        else{
            flag1=flag2;
            flag2=0;
        }
    }
    for (int i = ta; i < max(m,n); ++i) {
        int t = tmp[max(m,n)-i-1]+flag1;
        ret.push_back(t%2);
        if(t==4){
            flag1 = flag2;
            flag2 = 1;
        }
        else if(t>1){
            flag2++;
            flag1 = flag2;
            flag2 = 1;
        }
        else{
            flag1=flag2;
            flag2=0;
        }
    }
    if(flag1==1) ret.push_back(flag1);
    if(flag1==1&&flag2==1) ret.push_back(flag2);
    while (ret.back()==0&&ret.size()>1){
        ret.pop_back();
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
int main() {
    vector<int>arr1 = {1,1,1,1,1};
    vector<int>arr2 = {1,0,1};
    auto ret = addNegabinary(arr1,arr2);
    return 0;
}