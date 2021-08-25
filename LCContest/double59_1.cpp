#include "bits/stdc++.h"

using namespace std;
int minTimeToType(string word) {
    char pre = 'a';
    int ret = word.size();
    for(auto i:word){
        ret+=min(abs(i-pre-26)%26,abs(i-pre+26)%26);
        pre = i;
    }
    return ret;
}
int main() {
    string word ="abc";
    int ret = minTimeToType(word);
    return 0;
}