#include "bits/stdc++.h"

using namespace std;
int minPartitions(string n) {
    int ret = INT_MIN;
    int tmp = n[0]-'0';
    for(auto i:n){
        tmp =max(tmp,i-'0');
        ret = max(tmp,ret);
    }
    return ret;
}
int main() {
    string n = "27346209830709182346";
    int ret = minPartitions(n);
    return 0;
}