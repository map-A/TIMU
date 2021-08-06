#include "bits/stdc++.h"

using namespace std;
double func(vector<int>& nums, int k) {
    int numsSize = nums.size(), index = 0, maxKSum = INT_MIN, tempKSum = 0;
    while (index < k){
        tempKSum += nums[index++];
    }
    double ret = 0;
    double  tmpret = 0;
    int next = 0;
    while (index < numsSize){
        next = tempKSum+nums[index] - nums[index - k];//减去左端加上右端
        tmpret = 1.0*(next-tempKSum)/(tempKSum);
        tempKSum = next;
        ret = max(ret,tmpret);
        index += 1;
    }
    return ret;
}
int main() {
    string line;
    vector<int> vec;
    string temp;
    int k;
    getline(cin, line);
    stringstream ss(line);

    while(getline(ss, temp, ',')){
            vec.push_back(stoi(temp));
    }

    stringstream st(temp);
    while(getline(st, temp, ':')){
        k = stoi(temp);
    };
    auto ret = func(vec,k);
    printf("%.2lf\%%\n",ret*100);
    return 0;
}