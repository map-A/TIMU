#include "bits/stdc++.h"

using namespace std;
string findDifferentBinaryString(vector<string>& nums) {
    sort(nums.begin(),nums.end());
    unique(nums.begin(),nums.end());
    int n = nums[0].size();
    int index = 0;
    for(int i=0;i<nums.size();i++){
        bitset<16>a(nums[i]);
        if(a==index){
            index++;
        }
        else{
            bitset<16>c(index);
            return c.to_string();
        }
    }

}
int main() {

    return 0;
}