#include "bits/stdc++.h"

using namespace std;
int countones(string a){
    int ret = 0;
    for(auto &i:a){
        ret+=(i-'0');
    }
    return ret;
}
int numberOfBeams(vector<string>& bank) {
    int l = 0;
    int ret = 0;
    for (int i = 0; i < bank.size(); ++i) {
        if(bank[i].find('1')!=string::npos){
            int r = countones(bank[i]);
            ret+=l*r;
            l = r;
        }
    }
    return ret;
}
int main() {
    vector<string>bank = {"011001","000000","010100","001000"};
    int ret = numberOfBeams(bank);
    return 0;
}