#include "bits/stdc++.h"

using namespace std;


bool addstring(string a,string b,string c){
    //TODO:
    string ret = "";
    int flag = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int i=0;
    for (;i<min(a.size(),b.size());i++) {
        ret+= to_string(((a[i]-'0')+(b[i]-'0')+flag)%10);
        flag = ((a[i]-'0')+(b[i]-'0')+flag)/10;
    }
    if(i<a.size()){
        for (i; i< b.size(); ++i) {
            ret+= to_string(((b[i]-'0')+flag)%10);
            flag = ((b[i]-'0')+flag)/10;
        }
    }
    if(i<b.size()){
        for (i; i< b.size(); ++i) {
            ret += to_string(((a[i] - '0') + flag) % 10);
            flag = ((a[i] - '0') + flag) / 10;
        }
    }
    if(flag!=0) ret+= to_string(flag);
    reverse(ret.begin(),ret.end());
    return ret==c;
}
bool vaild(int firstend,int secondend,string num){
    //从一开始的数
    string a = num.substr(0,firstend+1);
    string b = num.substr(firstend+1,secondend-firstend);
    int i = 0;
    bool flag = false;
    for (i=secondend+1; i < num.size(); ++i) {
        string c=num.substr(secondend+1,i-secondend);
        if(addstring(a,b,c)){
            a = b;
            b = c;
            secondend =i;
            flag = true;
        }
        else{
            flag = false;
        }

    }
    return i==num.size()&&flag== true;
}


bool isAdditiveNumber(string num) {
    int firstbegin = 0,firstend = 0;
    int secondbegin = 1,secondend = 1;
    //第一个数和第二个数
    for (; secondend < num.size(); ++firstend) {
        for (; secondend < num.size(); ++secondend) {
            if(vaild(firstend,secondend,num)){
                return true;
            }
        }
    }
    return false;
}



int main() {

    return 0;
}