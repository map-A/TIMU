#include "bits/stdc++.h"

using namespace std;

int t(int a){
    int ret=0;
    string s = to_string(a);
    for (int i = 0; i < s.size(); ++i) {
        ret+=(s[i]-'0');
    }
    return ret;
}

vector<int> slove(int l,int r){
    vector<int>ret(1e6+2,0);
    int tmp = 0;
    for (int i = l; i <=r; ++i) {
        if(i%t(i)==1){
            tmp++;
        }
        ret[i]=tmp;
    }
    return ret;
}

int main() {
    int t;
    auto ret = slove(1,1e6+1);

    scanf("%d\n",&t);
    for (int i = 0; i <t; ++i) {
        int l,r;
        scanf("%d %d\n",&l,&r);
        printf("%d\n",ret[r]-ret[l-1]);
    }
    return 0;
}