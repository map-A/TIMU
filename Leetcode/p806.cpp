#include "bits/stdc++.h"

using namespace std;
vector<int> numberOfLines(vector<int>& widths, string S) {
    int row = 1,tmp = 0;
    for(auto i:S){
        if(tmp+widths[i-'a']>100){
            row++;
            tmp = widths[i-'a'];
        }
        else{
            tmp = tmp+widths[i-'a'];
        }
    }
    vector<int>ret = {row,tmp};
    return ret;
}
int main() {

    return 0;
}