#include "bits/stdc++.h"

using namespace std;
int toNum(string s){
    string tmp;
    for(auto i:s){
        tmp+= to_string(i-'a');
    }
    int ret = stoi(tmp);
    return ret;
}
bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    int a = toNum(firstWord);
    int b = toNum(secondWord);
    int c = toNum(targetWord);
    return a+b==c;
}
int main() {
    string firstWord = "acb";
    string secondWord = "cba";
    string targetWord = "cdb";
    bool ret =isSumEqual(firstWord,secondWord,targetWord);
    return 0;
}