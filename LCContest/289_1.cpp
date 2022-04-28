#include "bits/stdc++.h"

using namespace std;
string digitSum(string s, int k) {
    while(s.size() > k){
        string next = "";
        int sum = 0;
        for(int i = 0; i < s.size(); i ++){
            sum += s[i] - '0';
            if(i % k == k - 1 || i + 1 == s.size()){
                next += to_string(sum);
                sum = 0;
            }
        }
        s = next;
    }
    return s;
}
int main() {

    return 0;
}