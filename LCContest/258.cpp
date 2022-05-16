#include "bits/stdc++.h"

using namespace std;
string reversePrefix(string word, char ch) {
    auto t = word.find(ch);
    if(t!=word.npos){
        reverse(word.begin(),word.begin()+t+1);
    }
    return word;
}

long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    map<double,vector<vector<int>>>m;
    for(auto i:rectangles){
        m[1.0*i[0]/i[1]].push_back(i);
    }
    long long ret = 0;
    for(auto i:m){
        ret+=(i.second.size()*(i.second.size()-1))/2;
    }
    return ret;
}


int main() {
    string word = "abcdefd";
    char ch='d';
    auto ret = reversePrefix(word,ch);
    return 0;
}