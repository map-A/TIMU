#include "bits/stdc++.h"

using namespace std;

int minimumMoves(string s) {
    int num =0;
    int i = 0;
    while(i<s.length()){
        if(s[i] == 'X'){
            num++;
            i += 3;
        }else i++;
    }
    return num;
}

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    long long sum = accumulate(rolls.begin(),rolls.end(),0);
    int m = rolls.size();
    long long diff = mean*(n+m)-sum;
    int aver = diff/n;
    if(diff>n*6|diff<0||aver==0){
        return {};
    }
    vector<int>ret(n,aver);
    for(int i=0;i<diff-n*aver;i++){
        ret[i]++;
    }
    return ret;
}

bool stoneGameIX(vector<int>& stones) {
    int s[3] = {0, 0, 0};
    for (int i : stones) ++s[i % 3];
    if (s[0] % 2 == 0) return s[1] != 0 && s[2] != 0;
    return s[2] > s[1] + 2 || s[1] > s[2] + 2;
}


int main() {
    string s("OXOX");
    int ret = minimumMoves(s);
    return 0;
}