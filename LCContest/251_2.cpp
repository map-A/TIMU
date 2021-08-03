#include "bits/stdc++.h"

using namespace std;


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
    string num = "021";
    vector<int>change= {9,4,3,5,7,2,1,9,0,6};
    string ret = maximumNumber(num,change);
    return 0;
}