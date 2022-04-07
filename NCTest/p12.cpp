#include "bits/stdc++.h"

using namespace std;


long long  solve(long long num1,long long num2,int num3,int num4){
    long long ret = 0;
    while (num3>=num1*2){
        if(num3%2==0&&num4%2==0){
            num3 = num3/2;
            num4 = num4/2;
        }
        else{
            num3-=1;
            num4-=1;
        }
        ret++;
    }
    if(num3==num1){
        if(num4==num2){
            return ret;
        }
        else{
            return -1;
        }
    }
    ret+=num3-num1;
    if(num2+num3-num1==num4){
        return ret;
    }
    else{
        return -1;
    }
}
int main() {
    int num1 = 1,num2=2,num3=4,num4=6;
    int ret = solve(num1,num2,num3,num4);

    return 0;
}