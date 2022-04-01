#include "bits/stdc++.h"

using namespace std;

bool canReorderDoubled(vector<int>& arr) {
    map<int,int>m;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
    }
    if(m[0]%2!=0) return false;//0的个数一定要为偶数
    vector<int>tmp;
    for(auto & [x,_]:m){
        tmp.push_back(x);
    }

    sort(tmp.begin(),tmp.end(),[](int a,int b){return abs(a)<abs(b);});

    //2,4,8不符合要求，应该是2,4,4,8
    for (int x: tmp) {
        if (m[2 * x] < m[x]) { // 无法找到足够的 2x 与 x 配对
            return false;
        }
        m[2 * x] -= m[x];
    }
    return true;

}
int main() {
    vector<int> nums = {4, -2, 2, -4};
    auto ret = canReorderDoubled(nums);
    return 0;
}