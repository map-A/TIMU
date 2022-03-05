#include "bits/stdc++.h"

using namespace std;

int main() {
    string txt = "dasdasdfdgdADSDSd";
    vector<int>m(128);
    for (int i = 0; i < txt.size(); ++i) {
        m[txt[i]]++;
    }
    int ret = INT_MIN;
    char ret_ch=0;
    for (int i = 0; i < 128; ++i) {
        if(m[i]>ret){
            ret = m[i];
            ret_ch = (char)(i);
        }
    }

   // a.erase(a.begin()+2);
    return 0;
}