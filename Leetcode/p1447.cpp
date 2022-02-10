#include "bits/stdc++.h"

using namespace std;
vector<string> simplifiedFractions(int n) {

    vector<string> ret;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(gcd(i,j)==1||i==1){
                string tmp = to_string(i)+"/"+to_string(j);
                ret.push_back(tmp);
            }
        }
    }
    return ret;
}
int main() {

    return 0;
}