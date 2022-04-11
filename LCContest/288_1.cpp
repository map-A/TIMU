#include "bits/stdc++.h"

using namespace std;
int largestInteger(int num) {
    string a = to_string(num);
    vector<int>aa;
    vector<int>bb;
    for (int i = 0; i < a.size(); ++i) {
        if((a[i]-'0')%2==0){
            aa.push_back(a[i]-'0');
        }
        else{
            bb.push_back(a[i]-'0');
        }
    }
    std::sort(aa.begin(), aa.end(),greater<int>());
    std::sort(bb.begin(), bb.end(),greater<int>());
    int j=0,k=0;
    for (int i = 0; i < a.size(); ++i) {
        if((a[i]-'0')%2==0){
            a[i] = '0'+aa[j++];
        }
        else{
            a[i] = '0'+ bb[k++];
        }
    }
    return stoi(a);
}
int main() {
    int nums = 65875;
    int ret = largestInteger(nums);
    return 0;
}