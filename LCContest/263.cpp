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


class Bank {
public:
    vector<long long> balance;

    Bank(vector<long long> &balance) {
        this->balance.assign(balance.begin(), balance.end());
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 > this->balance.size() || account2 > this->balance.size()) {
            return false;
        }
        if (this->balance[account1 - 1] < money) {
            return false;
        }
        this->balance[account1 - 1] -= money;
        this->balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > this->balance.size()) {
            return false;
        }
        this->balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > this->balance.size() || this->balance[account - 1] < money) {
            return false;
        }
        this->balance[account - 1] -= money;
        return true;
    }
};



int countMaxOrSubsets(vector<int> &nums) {

    int ret = 0, maxVal = 0, n = (int) nums.size();
    for (int i = 1; i < (1 << n); ++i) { //从1-2^n
        int max_num = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) max_num |= nums[j];

            if (maxVal < max_num) {
                ret = 1;
                maxVal = max_num;
            } else if (maxVal == max_num) ++ret;
        }
        return ret;
    }
}


int main() {

    return 0;
}