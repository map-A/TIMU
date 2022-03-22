#include "bits/stdc++.h"

using namespace std;

bool winnerOfGame(string colors) {
    int count = 0;
    for (int i = 0; i < (int)colors.size()-2; ++i) {
        if(colors.substr(i,3)=="AAA"){
            count++;
        }
        if(colors.substr(i,3)=="BBB"){
            count--;
        }
    }
    return count>0;
}

int main() {
    string color = "A";
    bool ret = winnerOfGame(color);
    return 0;
}