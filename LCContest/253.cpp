#include "bits/stdc++.h"

using namespace std;
bool isPrefixString(string s, vector<string>& words) {
    string t;
    for(auto i:words){
        t+=i;
        if(t==s) return true;
    }
    return false;
}


int minStoneSum(vector<int>& piles, int k) {

    //初始化一个大顶堆
    priority_queue<int,vector<int>>p(piles.begin(),piles.end());
    while(k>0){
        int val = p.top();
        p.pop();
        k--;
        p.push(val-val/2);
    }
    int ret = 0;
    while(!p.empty()){
        ret+=p.top();
        p.pop();
    }
    return ret;
}


int minSwaps(string s) {
    int n = s.size();

    int ret = 0;
    int balance = 0;
    int right = n - 1;
    for (int i = 0; i < right; i++) {
        if (s[i] == '[') {
            balance += 1;
        } else {
            balance -= 1;
        }
        if (balance < 0) {
            //从最右边找一个左括号
            for (; right > i; right--) {
                if (s[right] == '[') {
                    ret += 1;
                    swap(s[i], s[right]);
                    balance = 0;
                    i -= 1;
                    break;
                }
            }
        }
    }
    return ret;
}


vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> d, ans;
    for (int ob: obstacles) {
        // 这里需要改成 >=
        if (d.empty() || ob >= d.back()) {
            d.push_back(ob);
            ans.push_back(d.size());
        }
        else {
            // 将 300 题解中的二分查找改为 API 调用使得代码更加直观
            // 如果是最长严格递增子序列，这里是 lower_bound
            // 如果是最长递增子序列，这里是 upper_bound
            int loc = upper_bound(d.begin(), d.end(), ob) - d.begin();
            ans.push_back(loc + 1);
            d[loc] = ob;
        }
    }
    return ans;
}

int main() {

    return 0;
}