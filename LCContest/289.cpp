#include "bits/stdc++.h"

using namespace std;
string digitSum(string s, int k) {
    while(s.size() > k){
        string next = "";
        int sum = 0;
        for(int i = 0; i < s.size(); i ++){
            sum += s[i] - '0';
            if(i % k == k - 1 || i + 1 == s.size()){
                next += to_string(sum);
                sum = 0;
            }
        }
        s = next;
    }
    return s;
}

int minimumRounds(vector<int>& tasks) {
    map<int,int>m;
    for (auto i:tasks) {
        m[i]++;
    }
    int ret = 0;
    for (auto i:m) {
        if(i.second==1){
            return -1;
        }
        else if(i.second%3==0){
            ret+=i.second/3;
        }
        else{
            ret+=i.second/3+1;
        }
    }
    return ret;
}


int main() {

    return 0;
}