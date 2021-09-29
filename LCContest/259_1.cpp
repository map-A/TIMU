#include "bits/stdc++.h"

using namespace std;
int finalValueAfterOperations(vector<string>& operations) {
    int x = 0;
    for(auto &i:operations){
        if(i=="--X"||i=="X--"){
            x--;
        }
        else{
            x++;
        }
    }
    return x;
}
int main() {

    return 0;
}