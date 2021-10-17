#include "bits/stdc++.h"

using namespace std;

bool is_nums(string &s){
    for(auto i:s){
        if(!isdigit(i))return false;
    }
    return true;
}

bool areNumbersAscending(string s) {
    stringstream ss(s);
    string temp;
    vector<int>nums;
    while(getline(ss, temp, ' ')){
        if(is_nums(temp)){
            int num = stoi(temp);
            if(nums.empty()||nums.back()<num){
                nums.push_back(num);
            }
            else if(nums.back()>=num){
                return false;
            }
        }

    }
    return true;
}
int main() {

    return 0;
}