#include "bits/stdc++.h"

using namespace std;
string pushDominoes(string dominoes) {
    int len = dominoes.length();
    if(len<2) return dominoes;
    string ret;

    int flag;
    while(1){
        ret = "";
        flag=0;
        if(dominoes[0]=='.'&&dominoes[1]=='L'){
            ret+="L";
            flag=1;
        }
        else{
            ret+=dominoes[0];
        }
        for(int i=1;i<len-1;++i){
            if(i>0&&i<len-1&&dominoes[i]=='.'&&dominoes[i+1]=='L'&&dominoes[i-1]!='R'){
                ret+="LL";
                i++;
                flag=1;
            }
            else if(i>0&&i<len-1&&dominoes[i]=='.'&&dominoes[i-1]=='R'&&dominoes[i+1]!='L'){
                ret+="R";
                flag=1;
            }
            else ret+=dominoes[i];
        }
        if(dominoes[len-2]=='R'&&dominoes[len-1]=='.'){
            ret+="R";
            flag=1;
        }
        else{
            ret+=dominoes[len-1];
        }
        if(flag==0) break;
        dominoes = ret;
    }
    return ret;
}
int main() {

    return 0;
}