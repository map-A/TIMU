#include "bits/stdc++.h"

using namespace std;
#define f1(i, a, b) for(int i = a; i <= b; i ++)
#define f2(i, a, b) for(int i = a; i >= b; i --)

typedef long long LL;

vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    map<int,long long>m;
    for(auto segment:segments){
        m[segment[0]] +=segment[2];
        m[segment[1]]-=segment[2];
    }
    vector<vector<long long>>ret;
    long long color= 0;
    long long left = 0,right = 0;
    for(auto i:m){
        right = i.first;
        if(color!=0){
            ret.push_back({left,right,color});
        }
        left = right;
        color+=i.second;
    }
    return ret;
}


int main() {
    return 0;
}
