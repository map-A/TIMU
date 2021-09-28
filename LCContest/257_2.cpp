#include "bits/stdc++.h"

using namespace std;
int numberOfWeakCharacters(vector<vector<int>>& pr) {
    sort(pr.begin(),pr.end(),[&](auto &a,auto &b){
        return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];  //排序
    });
    int maxg=-1,num=0;
    for(auto i:pr){
        if(i[1]<maxg)
            num++;
        maxg=max(i[1],maxg);  //更新最大值
    }
    return num;
}
int main() {
    vector<vector<int>>pr = {{2,2},{3,2},{3,3}};
    auto ret = numberOfWeakCharacters(pr);
    return 0;
}