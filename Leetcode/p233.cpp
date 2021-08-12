#include "bits/stdc++.h"

using namespace std;
int countDigitOne(int n) {
    if(n==0) return 0;
    if(n<10) return 1;
    if(n==99) return 20;
    long long  count = 0;
    int tmp = n;
    long long nine = 0;
    int num = 1;
    vector<int>dp;
    while(1){
        nine = pow(10,num-1)*9+nine;
        if(n>nine){
            count+=pow(10,num-1)+9*pow(10,num-2)*(num-1);
            dp.push_back(count);
        }
        else{
            break;
        }
        num++;
    }
    int i=num;
    int high = n/pow(10,i-1);
    count+=dp[i-2]*(high-1);
    if(n-2*pow(10,i-1)+1>0){
        count+=pow(10,i-1);
    }else{
        count+=(n-pow(10,i-1)+1);
    }
    n = n%(int)pow(10,i-1);
    i = to_string(n).length();
    while(n>0){
        high  = n/pow(10,i-1);
        if(i>=2){
            count+=dp[i-2]*(high);
            if(n-2*pow(10,i-1)+1>0){
                count+=pow(10,i-1);
            }else{
                count+=(n-pow(10,i-1)+1);
            }

        }
        else{
            count++;
        }
        n = n%(int)pow(10,i-1);
        i = to_string(n).length();
    }
    return count;
}
int main() {

    return 0;
}