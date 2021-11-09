
#include "bits/stdc++.h"

using namespace std;

bool isTrue(const string &s){
    int vis[26] = {0};
    for(auto i:s){
        vis[i-'a']=1;
    }
    int sum = 0;
    for(int i=0;i<26;i++){
        sum+=vis[i];
    }
    if(sum>5) return false;
    if(vis[0]+vis[4]+vis[8]+vis[14]+vis[20]==5) return true;
    return false;
}
int countVowelSubstrings(string word) {
    if(word.size()<5) return 0;
    int ret = 0;
    for(int i=0;i<=word.size()-5;i++){
        int j = 5;
        for(j;j<=word.size()-i;j++){
            string tmp = word.substr(i,j);
            if(isTrue(tmp)){
                ret++;
            }
        }
    }
    return ret;
}
int main() {
    string a = "poazaeuioauoiioaouuouaui";
    int ret = countVowelSubstrings(a);
    return 0;
}