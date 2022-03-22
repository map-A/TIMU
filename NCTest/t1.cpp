#include "bits/stdc++.h"

using namespace std;

int solve(vector<string>&alpha,string target){
    int ret = 0;
    for (int i = 0; i < alpha.size(); ++i) {
        if(alpha[i].find(target)!=string::npos){
            ret++;
        }
    }
    for (int i = 0; i < alpha.size(); ++i) {
        string tmp;
        for (int j =0; j < alpha.size(); ++j) {
            tmp+=alpha[j][i];
        }
        if(tmp.find(target)!=string::npos){
            ret++;
        }
    }
    return ret;
}


int main() {
    int n;
    scanf("%d\n",&n);
    string target;
    cin>>target;
    vector<string>alpha(n);
    for (int i = 0; i < n; ++i) {
        cin>>alpha[i];
    }
    auto ret = solve(alpha,target);
    printf("%d\n",ret);
    return 0;
}