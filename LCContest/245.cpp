#include "bits/stdc++.h"

using namespace std;
bool makeEqual(vector<string>& words) {
    int  ch[26];
    memset(ch,0, sizeof(ch));
    for(int i=0;i<words.size();i++){
        for(auto j:words[i]){
            ch[j-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        if(ch[i]%words.size()!=0){
            return false;
        }
    }
    return true;
}

bool isSubSeq(string s, string p) {

    int p_i = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == p[p_i]) {
            p_i++;
        }
    }
    return p_i == p.size();
}

int maximumRemovals(string &s, string p, vector<int> &removable) {
    int ret = 0;
    string tmp = s;
    int l = 0;
    int r = removable.size() - 1;
    while (l <= r) {
        for (int i = 0; i <= (l + r) / 2; ++i) {
            tmp[removable[i]] = ' ';
        }
        if (isSubSeq(tmp, p)) {
            ret = (l + r) / 2 + 1;
            l = (l + r) / 2 + 1;
        } else {
            r = (l + r) / 2 - 1;
            tmp = s;
        }
    }
    return ret;
}

bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    for (auto i:triplets) {
        if (i[0] == target[0] && i[1] == target[1] && i[2] == target[2]) return true;
    }
    //选取两个元素
    int n = triplets.size();
    vector<int>tmp = {0,0,0};
    for (int i = 0; i < n; i++) {
        if(triplets[i][0]==target[0]||triplets[i][1]==target[1]||triplets[i][2]==target[2]){
            if(triplets[i][0]>target[0]||triplets[i][1]>target[1]||triplets[i][2]>target[2]){
                continue;
            }
            tmp[0] = max(tmp[0],triplets[i][0]);
            tmp[1] = max(tmp[1],triplets[i][1]);
            tmp[2] = max(tmp[2],triplets[i][2]);
        }
        if (tmp[0] == target[0] && tmp[1] == target[1] && tmp[2] == target[2]) return true;
    }
    return false;
}

int main() {
    string num = "4205";
    return 0;
}