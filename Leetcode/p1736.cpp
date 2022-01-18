#include "bits/stdc++.h"

using namespace std;
string maximumTime(string time) {
    string ret ="";
    if(time[0]=='?'){
        if(time[1]=='?'||time[1]-'0'<4)
            ret+='2';
        else{
            ret+='1';
        }
    }
    else{
        ret+=time[0];
    }
    if(time[1]=='?'){
        if(ret[0]=='2'){
            ret+="3";
        }
        else{
            ret+='9';
        }
    }
    else{
        ret+=time[1];
    }
    ret+=time[2];

    if(time[3]=='?'){
        ret+='5';
    }
    else{
        ret+=time[3];
    }
    if(time[4]=='?'){
        ret+="9";
    }
    else{
        ret+=time[4];
    }
    return ret;
}
int main() {
    string time("2?:?0");
    auto ret = maximumTime(time);
    cout<<ret;
    return 0;
}