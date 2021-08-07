#include "bits/stdc++.h"

using namespace std;
int maximumPopulation(vector<vector<int>>& logs) {
    int age[101] = {0};
    for(int i=0;i<logs.size();i++){
        for(int j = logs[i][0];j<logs[i][1];j++){
            age[j-1950]++;
        }
    }
    int ret  = 0;
    int year = 0;
    for(int i=0;i<101;i++){
        if(ret<age[i]){
            year = 1950+i;
            ret = age[i];
        }
    }
    return year;
}
int main() {

    return 0;
}