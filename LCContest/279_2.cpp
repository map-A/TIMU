#include "bits/stdc++.h"

using namespace std;
long long smallestNumber(long long num) {
    if(num==0) return 0;
    int sign = 1;
    if(num<0){
        sign = -1;
        num = -num;
    }
    string t = to_string(num);
    vector<int>digit(10,0);
    for (auto i:t) {
        digit[i-'0']++;
    }
    string ret = "";
    if(sign<0){
        //负数的情况

        for (int i = 9; i >=0 ; --i) {
            for(int j=0;j<digit[i];j++){
                ret+=('0'+i);
            }
        }
        return sign*(stoll(ret));
    }
    else if(sign>0){
        //正数的情况
        for (int i = 1; i < 10; ++i) {
            if(digit[i]>0){
                ret+= ('0'+i);
                digit[i]--;
                break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < digit[i]; ++j) {
                ret+=('0'+i);
            }
        }
        return stoll(ret);
    }
}
int main() {
    long long num = -7065;
    long long ret = smallestNumber(num);
    return 0;
}