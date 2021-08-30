#include "bits/stdc++.h"

using namespace std;
void solve(vector<int>&vec){
    if(vec.empty()) return;
    vector<int>odd;
    vector<int>even;
    for(int i=0;i<vec.size();i++){
        if(vec[i]%2==0)even.push_back(vec[i]);
        else odd.push_back(vec[i]);
    }
    for(auto i:even){
        cout<<i<<',';
    }
    for(int i=0;i<odd.size()-1;i++){
        cout<<odd[i]<<',';

    }
    cout<<odd.back();
}
int main() {
    int n = 0;
    string line;
    getline(cin,line);
    n = stoi(line);

    vector<int> vec;
    string temp;
    getline(cin, line);

    stringstream ss(line);
    while (getline(ss, temp, ',')) {
        vec.push_back(stoi(temp));
    }
    solve(vec);
    return 0;
}