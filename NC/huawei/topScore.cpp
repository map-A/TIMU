#include "bits/stdc++.h"

using namespace std;
int query(vector<int>&nums,int num1,int num2){
    int a = min(num1,num2);
    int b = max(num1,num2);
    return *max_element(nums.begin()+a-1,nums.begin()+b);

}
void update(vector<int>&nums,int num1,int num2) {
    nums[num1-1] = num2;
}
int main() {
    int m,n;
    while (cin>>m>>n){
        vector<int>nums(m);
        for (int i = 0; i < m; ++i) {
            cin>>nums[i];
        }
        char op;
        int num1,num2;
        for (int i = 0; i < n; ++i) {
            cin>>op>>num1>>num2;
            if(op=='Q'){
                int ret = query(nums,num1,num2);
                printf("%d\n",ret);
            }
            if(op=='U'){
                update(nums,num1,num2);

            }
        }
    }
    return 0;
}