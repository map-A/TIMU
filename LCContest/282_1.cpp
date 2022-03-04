#include "bits/stdc++.h"

using namespace std;
int prefixCount(vector<string>& words, string pref) {
    int ret = 0;
    for (int i = 0; i < words.size(); ++i) {
        if(words[i].find(pref)==0){
            ret++;
        }
    }
    return ret;
}
int main() {
    vector<string>words = {"leetcode","win","loops","success"};
    string pref = "code";
    int ret = prefixCount(words,pref);
    return 0;
}