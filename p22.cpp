#include "bits/stdc++.h"

using namespace std;

bool valid(const string &str) {
    int ret = 0;
    for (char c : str) {
        if (c == '(') {
            ret++;
        } else {
            ret--;
        }
        if (ret < 0) {
            return false;
        }
    }
    return ret == 0;
}

void generate_all(string &thesis, int n, vector<string> &result) {
    if (thesis.size() == n) {
        if (valid(thesis)) {
            result.push_back(thesis);
        }
        return;
    }
    thesis += '(';
    generate_all(thesis, n, result);
    thesis.pop_back();
    thesis += ')';
    generate_all(thesis, n, result);
    thesis.pop_back();
}

vector<string> generateParenthesis1(int n) {
    vector<string> result;
    string s;
    generate_all(s, n * 2, result);
    return result;
}

void backtrack(string s,int l,int r,int n,vector<string>&ret){
    if(l>n||r>n||r>l) return;
    if(s.size()==n){
        ret.push_back(s);
        return;
    }
    backtrack(s+'(',l+1,r,n,ret);
    backtrack(s+')',l,r+1,n,ret);
    return;
}

vector<string> generateParenthesis(int n) {
    vector<string>ret;
    backtrack("",0,0,n,ret);
    return ret;
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}