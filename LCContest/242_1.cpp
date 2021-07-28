#include "bits/stdc++.h"

using namespace std;
int findMaxSeqChar(string s,char target){
    int ret = INT_MIN;
    int l = 0,r=0;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]==target&&flag== false){
            l=i;
            r = i;
            ret = 1;
            flag= true;
        }
        else if(s[i]==target&&flag== true){
            r=i;
            ret =max(ret,r-l+1);
        }
        else {
            flag = false;

        }

    }
    return ret;
}
bool checkZeroOnes(string s) {

    //找出连续1
    int one = findMaxSeqChar(s,'1');
    int zero = findMaxSeqChar(s,'0');
    return one>zero;
}
int main() {
    string s = "1";
    bool ret = checkZeroOnes(s);
    return 0;
}