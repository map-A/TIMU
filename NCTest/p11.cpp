#include "bits/stdc++.h"

using namespace std;


string solve(vector<int>&arr){
    int start = arr[0];
    string ret = to_string(start);


    for (int i = 1; i < arr.size(); ++i) {
        int end = arr[i];

        if(end-start!=1){
            ret+= to_string(end);

        }
        else{
            ret+="-";
            start=arr[i];
        }
    }
    return ret;
}
int main() {
    vector<int>nums = {12,13,15,16,17};
    string ret = solve(nums);
    return 0;
}