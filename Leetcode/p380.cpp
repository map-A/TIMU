#include "bits/stdc++.h"

using namespace std;
typedef long long LL;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int>value;
    map<int,int>index;
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.count(val)==0){
            value.push_back(val);
            index[val] = value.size()-1;
            return true;
        }
        else{
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.count(val)!=0){
            int val_index = index[val];
            if(val_index!=value.size()-1){
                int swap_index = index[value.back()];
                value[val_index] = value.back();
                index[value.back()] = val_index;
            }
            index.erase(val);
            value.pop_back();
            return true;
        }
        else{
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int n=value.size();
        int randomNum = rand()%n;
        return value[randomNum];
    }
};

int main() {
    return 0;
}
