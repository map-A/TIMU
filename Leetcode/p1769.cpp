#include "bits/stdc++.h"

using namespace std;
vector<int> minOperations(string boxes) {
    vector<int>ret;
    int i=0;
    for(int i=0;i<boxes.size();++i){
        int count = 0;
        for(int j=0;j<boxes.size();++j){
            if(boxes[j]=='1')count+=abs(j-i);
        }
        ret.push_back(count);
    }
    return ret;
}
int main() {
    string boxes = "110";
    vector<int>ret = minOperations(boxes);
    return 0;
}