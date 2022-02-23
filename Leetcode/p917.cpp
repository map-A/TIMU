#include "bits/stdc++.h"

using namespace std;
string reverseOnlyLetters(string s) {
    int i = 0,j = s.size()-1;
    while(i<j){
        if(isalpha(s[i])&&isalpha(s[j])){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        if(!isalpha(s[i])){
            i++;
        }
        if(!isalpha(s[j])){
            j--;
        }
    }
    return s;
}
int main() {

    return 0;
}