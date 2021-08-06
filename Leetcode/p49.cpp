#include "bits/stdc++.h"

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>ret;
    map<string,vector<string>>m;
    for(auto i:strs){
        string tmp = i;
        sort(tmp.begin(),tmp.end());
        m[tmp].push_back(i);
    }
    for(auto i:m){
        ret.push_back(i.second);
    }
    return ret;

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}