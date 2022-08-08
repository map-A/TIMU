#include "bits/stdc++.h"

using namespace std;

int minMaxGame(vector<int>& nums) {
    int n = nums.size();
    while(n>1){
        for (int i = 0; i < n/2; ++i) {
            if(i%2==0) nums[i] = min(nums[2*i],nums[2*i+1]);
            else nums[i] = max(nums[2*i],nums[2*i+1]);
        }
        n = n/2;
    }
    return nums[0];
}


int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int ret = 1;
    int start = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if(nums[i]-start>k){
            ret++;
            start = nums[i];
        }
    }
    return ret;
}

vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    map<int,int>m;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }
    for (int i = 0; i < operations.size(); ++i) {
        m.insert({operations[i][1],m[operations[i][0]]});
        m.erase(operations[i][0]);
    }
    for (auto i:m) {
        nums[i.second] = i.first;
    }
    return nums;
}

class TextEditor {
public:
    stack<char> left, right;
    TextEditor() {}

    void addText(string text) {
        for (char c:text) left.push(c);
    }

    int deleteText(int k) {
        k = min(k, (int)left.size());
        for (int i = 0; i < k; i++) left.pop();
        return k;
    }

    string text() {
        string res;
        for (int i = 0, k = min((int)left.size(), 10); i < k; i++) {
            res.insert(res.begin(), left.top());
            left.pop();
        }
        addText(res);
        return res;
    }

    string cursorLeft(int k) {
        k = min(k, (int)left.size());
        while (k--) {
            right.push(left.top());
            left.pop();
        }
        return text();
    }

    string cursorRight(int k) {
        k = min(k, (int)right.size());
        while (k--) {
            left.push(right.top());
            right.pop();
        }
        return text();
    }
};

int main() {

    return 0;
}