#include "bits/stdc++.h"

using namespace std;
int minMoves(int target, int maxDoubles) {
    int ret = 0;
    while (target>1){
        if(target%2!=0){
            target--;
            ret++;
        }
        else{
            if(maxDoubles>0){
                maxDoubles--;
                ret++;
                ret/=2;
            }
            else{
                ret+=(target-1);
                target=1;
            }
        }
    }
    return ret;
}
int main() {
    int a = 19,b = 2;
    auto ret = minMoves(a,b);

    return 0;
}