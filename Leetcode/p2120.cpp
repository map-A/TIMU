#include "bits/stdc++.h"

using namespace std;
vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    int len= s.size();
    vector<int>ret(len,0);
    for (int i = len-1; i>=0; --i) {
        int t = 0;
        int j = i;
        vector<int>new_pos(startPos);
        for (; j < len; ++j) {
            if(s[j]=='L'){
                new_pos[1]-=1;
            }
            else if(s[j]=='R'){
                new_pos[1]+=1;
            }
            else if(s[j]=='U'){
                new_pos[0]-=1;
            }
            else if(s[j]=='D'){
                new_pos[0]+=1;
            }
            if(new_pos[0]<0||new_pos[0]>=n||new_pos[1]<0||new_pos[1]>=n){
                ret[i] = t;
                break;
            }
            t++;
        }
        if(j==len){
            ret[i] = t;
        }
    }
    return ret;
}
int main() {
    int n = 3;
    vector<int>startPos = {0,1};
    string s = "RRDDLU";
    auto ret = executeInstructions(n,startPos,s);
    return 0;
}