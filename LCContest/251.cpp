#include "bits/stdc++.h"

using namespace std;

int getLucky(string s, int k) {
    string tmp;
    for (auto i:s) {
        tmp += to_string(i - 'a' + 1);
    }
    int ret = 0;
    for (int i = 0; i < k; i++) {
        ret = 0;
        for (auto i:tmp) {
            ret += i - '0';
        }
        tmp = to_string(ret);
    }
    return ret;
}


string maximumNumber(string num, vector<int>& change) {
    bool  flag = false;
    for(int i=0;i<num.size();i++){
        if(num[i]-'0'<change[num[i]-'0']){
            num[i] = '0'+change[num[i]-'0'];
            flag = true;
        }
        else if(num[i]-'0'==change[num[i]-'0']){
            if(flag){
                num[i] = '0'+change[num[i]-'0'];
            }
        }
        else if(!flag){
            continue;
        }
        else{
            break;
        }
    }
    return num;
}

int main() {
    string s = "leetcode";
    int ret = getLucky(s, 2);
    return 0;
}