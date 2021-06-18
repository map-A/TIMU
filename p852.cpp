//
// Created by mm on 2021/6/15 0015.
//


#include <bits/stdc++.h>

using namespace std;
int peakIndexInMountainArray(vector<int>& A) {
    return max_element(A.begin(),A.end())-A.begin();
}
int main(){
    vector<int>arr = {0,1,0};
    cout<<peakIndexInMountainArray(arr);
    return 0;
}
