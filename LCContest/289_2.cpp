#include "bits/stdc++.h"

using namespace std;
int minimumRounds(vector<int>& tasks) {
    map<int,int>m;
    for (auto i:tasks) {
        m[i]++;
    }
    int ret = 0;
    for (auto i:m) {
        if(i.second==1){
            return -1;
        }
        else if(i.second%3==0){
            ret+=i.second/3;
        }
        else{
            ret+=i.second/3+1;
        }
    }
    return ret;
}
int main() {

    return 0;
}