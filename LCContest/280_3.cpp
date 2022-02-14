#include "bits/stdc++.h"

using namespace std;
long long minimumRemoval(vector<int>& beans) {

    sort(beans.begin(),beans.end());
    vector<int>tmp;
    for (int i = 0; i < beans.size(); ++i) {
        if(beans[i]!=0){
            tmp.push_back(beans[i]);
        }
    }
    if(tmp[0]==tmp.back()) return 0;
    vector<long long>sum(tmp.size(),0);
    for (int i = 1; i < tmp.size(); ++i) {
        sum[i] = sum[i-1]+tmp[i-1];
    }

    long long ret = sum[beans.size()-1];
    vector<long long>diff(tmp.size(),0);

    for (int i = tmp.size()-2; i >=0; --i) {
        diff[i] = diff[i+1]+(tmp.size()-1-i)*(tmp[i+1]-tmp[i]);
        ret = min(ret,sum[i]+diff[i]);
    }
    return ret;
}
int main() {
    vector<int>beans = {2,2,3,10};
    long long ret = minimumRemoval(beans);
    return 0;
}