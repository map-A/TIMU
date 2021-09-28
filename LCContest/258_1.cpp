#include "bits/stdc++.h"

using namespace std;
string reversePrefix(string word, char ch) {
    auto t = word.find(ch);
    if(t!=word.npos){
        reverse(word.begin(),word.begin()+t+1);
    }
    return word;
}
int main() {
    string word = "abcdefd";
    char ch='d';
    auto ret = reversePrefix(word,ch);
    return 0;
}