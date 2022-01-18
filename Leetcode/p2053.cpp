#include "bits/stdc++.h"

using namespace std;
string kthDistinct(vector<string>& arr, int k) {
    map<string,int>m;
    for(auto i:arr){
        m[i]++;
    }
    for (int i = 0; i < arr.size(); ++i) {
        if(m[arr[i]]==1){
            k--;
            if(k==0) return arr[i];
        }
    }
    return "";
}
int main() {

    return 0;
}