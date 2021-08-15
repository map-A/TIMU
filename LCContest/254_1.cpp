#include "bits/stdc++.h"
using namespace std;

int numOfStrings(vector<string>& patterns, string word) {
    int ret = 0;
    for(auto i:patterns){
        if(word.find(i)!=word.npos){
            ret++;
        }
    }
    return ret;
}
int main() {

    return 0;
}