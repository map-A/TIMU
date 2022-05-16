#include "bits/stdc++.h"

using namespace std;
vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int>odd;
    vector<int>even;
    for (int i = 0; i < nums.size(); ++i) {
        i%2==0?odd.push_back(nums[i]):even.push_back(nums[i]);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end(),greater<int>());
    for (int i = 0; i < nums.size(); ++i) {
        i%2==0?nums[i] = odd[i/2]:nums[i]=even[i/2];
    }
    return nums;
}

long long smallestNumber(long long num) {
    if(num==0) return 0;
    int sign = 1;
    if(num<0){
        sign = -1;
        num = -num;
    }
    string t = to_string(num);
    vector<int>digit(10,0);
    for (auto i:t) {
        digit[i-'0']++;
    }
    string ret = "";
    if(sign<0){
        //负数的情况

        for (int i = 9; i >=0 ; --i) {
            for(int j=0;j<digit[i];j++){
                ret+=('0'+i);
            }
        }
        return sign*(stoll(ret));
    }
    else if(sign>0){
        //正数的情况
        for (int i = 1; i < 10; ++i) {
            if(digit[i]>0){
                ret+= ('0'+i);
                digit[i]--;
                break;
            }
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < digit[i]; ++j) {
                ret+=('0'+i);
            }
        }
        return stoll(ret);
    }
}

class Bitset {
public:
    vector<int>v1;
    vector<int>v2;
    int flag = 0;
    int count_v1;
    int count_v2;
    Bitset(int size) {
        v1.resize(size);
        v2.resize(size,1);
        count_v1 = 0;
        count_v2 = size;

    }

    void fix(int idx) {
        if(flag%2==0){
            //此时选择的是v1
            if(v1[idx]!=1){
                v1[idx]=1;
                count_v1++;
            }
            if(v2[idx]!=0){
                v2[idx] = 0;
                count_v2--;
            }
        }
        else{
            if(v2[idx]!=1){
                v2[idx] = 1;
                count_v2++;
            }
            if(v1[idx]!=0){
                v1[idx] = 0;
                count_v1--;
            }
        }


    }

    void unfix(int idx) {
        if(flag%2==0){
            if(v1[idx]!=0){
                v1[idx] = 0;
                count_v1--;
            }
            if(v2[idx]!=1){
                v2[idx] = 1;
                count_v2++;
            }
        }
        else{
            if(v2[idx]!=0){
                v2[idx] = 0;
                count_v2--;
            }
            if(v1[idx]!=1){
                v1[idx] = 1;
                count_v1++;
            }
        }
    }

    void flip() {
        flag++;
    }

    bool all() {
        if(flag%2==0){
            return count_v1==v1.size();
        }
        else{
            return count_v2==v2.size();
        }

    }

    bool one() {
        if(flag%2==0){
            return count_v1>0;
        }
        else{
            return count_v2>0;
        }

    }

    int count() {
        if(flag%2==0){
            return count_v1;
        }
        else{
            return count_v2;
        }
    }

    string toString() {
        string ret = "";
        if(flag%2==0){
            for (int i = 0; i < v1.size(); ++i) {
                ret+=('0'+v1[i]);
            }
            return ret;
        }
        else{
            for (int i = 0; i < v1.size(); ++i) {
                ret+=('0'+v2[i]);
            }
            return ret;
        }
    }
};
int main() {
    vector<int>nums = {4,1,2,3};
    vector<int>ret = sortEvenOdd(nums);
    return 0;
}