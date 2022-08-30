//
// Created by mm on 2022/8/14.
//

#include "bits/stdc++.h"
using namespace std;
static const string base64_chars("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");

/*
 * Base64（基底64）是一种基于64个可打印字符来表示二进制数据的表示方法。
由于log64 = 6，所以每6个bit为一个单元，对应某个可打印字符。
 3个字节相当于24个bit，对应4个Base64单元，即3个字节可由4个可打印字符来表示。
在Base64中的可打印字符包括字母A-Z、a-z、数字0-9，这样共有62个字符，此外两个可打印符号在不同的系统中而不同。
本题采用的转换关系：0~25分别对应A~Z，26~51分别对应a~z，52~61分别对应0~9，62对应+，63对应/
注：当'二进制序列字节数'不为3的倍数时，需要用0字节将长度补充到3的倍数，为与实际的“0”字节进行区别，补充的“0”会被编码为“=”。
 00
 AA==
 *
 * */
string str2Base64(string input){
    int len;
    int str_len;
    int i,j;
    str_len = input.size();
    if(str_len%3==0){
        len = str_len/3*4;
    }
    else{
        len = (str_len/3+1)*4;
    }
    string ret(len,'0');
    for(i=0,j=0;i<len-2;j+=3,i+=4){
        ret[i]=base64_chars[input[j]>>2];
        ret[i+1]=base64_chars[(input[j]&0x3)<<4]|(input[j+1]>>4);
        ret[i+2]=base64_chars[(input[j+1]&0xf)<<2]|(input[j+2]>>6);
        ret[i+3] = base64_chars[input[j+2]&0x3f];
    }
    if(str_len%3==1){
        ret[i-2] = '=';
        ret[i-1] = '=';
    }
    else if(str_len%3==2){
        ret[i-1]='=';
    }
    return ret;




}
struct cmp{
    bool operator() (pair<string,int>&a,pair<string,int>&b){
        if(a.second>b.second) return false;
        else if(a.second==b.second&& a.first>b.first) return false;
        return true;
    }
};

vector<vector<string> > topKstrings(vector<string>& strings, int k) {
    // write code here
    vector<vector<string>>ret;
    priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>pq;
    for(int i=0;i<k;i++){
        pq.push()
    }
}

int main(){
    string input;
    cin>>input;
    string ret = str2Base64(input);
    cout<<ret;
    return 0;
}