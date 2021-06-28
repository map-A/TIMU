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
int main() {
    string num = "4205";
    return 0;
}