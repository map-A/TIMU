#include "bits/stdc++.h"

using namespace std;

int minimumMoves(string s) {
    int num =0;
    int i = 0;
    while(i<s.length()){
        if(s[i] == 'X'){
            num++;
            i += 3;
        }else i++;
    }
    return num;
}
int main() {
    string s("OXOX");
    int ret = minimumMoves(s);
    return 0;
}