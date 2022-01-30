#include "bits/stdc++.h"

using namespace std;
bool closeStrings(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();
    if(n1!=n2) return false;
    map<char,int>m1;
    map<char,int>m2;
    for (int i = 0; i < n1; ++i) {
        m1[word1[i]]++;
        m2[word2[i]]++;
    }
    if(m1.size()!=m2.size()) return false;
    vector<int>v1;
    vector<int>v2;
    for (auto &i:m1) {
        if(m2.count(i.first)){
            v1.push_back(i.second);
            v2.push_back(m2[i.first]);
            continue;
        }
        else return false;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(v1!=v2) return false;
    return true;
}
int main() {
    string word1 = "abbzccc";
    string word2 = "babzzcz";
    auto ret = closeStrings(word1,word2);
    return 0;
}