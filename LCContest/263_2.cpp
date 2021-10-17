#include "bits/stdc++.h"

using namespace std;

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

int main() {

    return 0;
}