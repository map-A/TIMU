#include "bits/stdc++.h"

using namespace std;
int solve(int bottles){
    int ret = 0;
    while (bottles>=3){
        ret+=bottles/3;
        bottles = bottles%3+bottles/3;
    }
    if(bottles==2) ret++;
    return ret;
}
int main() {
    int n;
    while (1){
        scanf_s("%d",&n);
        if(n==0) break;
        int ret = solve(n);
        printf("%d\n",ret);
    }
    return 0;
}