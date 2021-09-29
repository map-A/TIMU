#include "bits/stdc++.h"

using namespace std;
bool checkIfPangram(string sentence) {
    bool vis[26];
    memset(vis,false,sizeof(vis));
    for(auto i:sentence){
        vis[i-'a'] =1;
    }
    for(int i=0;i<26;i++){
        if(vis[i]==0) return false;
    }
    return true;
}
int main() {
    string sentence = "Leetcode";
    bool ret = checkIfPangram(sentence);
    return 0;
}