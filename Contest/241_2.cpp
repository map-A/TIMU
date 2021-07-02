#include "bits/stdc++.h"

using namespace std;
int minSwaps(string s) {
    int n = s.size();
    int n0 = count(s.begin(),s.end(),'0');
    int n1 = n-n0;
    int ret = INT_MAX;
    if(n1==(n+1)/2&&n0==n/2){
        int diff1 = 0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'==i%2){
                diff1++;
            }
        }
        ret = min(ret,diff1/2);
    }

    if(n0==(n+1)/2&&n1==n/2){
        int diff2 = 0;
        for(int i=0;i<n;i++){
            if(s[i]-'0'!=i%2){
                diff2++;
            }
        }
        ret = min(ret,diff2/2);
    }
    return ret==INT_MAX?-1:ret;
}
int main() {
    string s = "111000";
    int ret = minSwaps(s);
    return 0;
}