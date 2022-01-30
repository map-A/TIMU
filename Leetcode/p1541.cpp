#include "bits/stdc++.h"

using namespace std;
int minInsertions(string s) {
    stack<char>st;
    int ret = 0;
    int i=0;
    while (i<s.size()){
        if(s[i]=='('){
            st.push(s[i]);
        }
        if(s[i]==')'){
            if(!st.empty()){
                st.pop();
            }
            else {
                ret++;
            }
            if(i+1<s.size()&&s[i+1]==')'){
                i++;
            }
            else if(i+1<s.size()&&s[i+1]=='('){
                ret++;
            }
            else if(i+1>=s.size()){
                ret++;
            }
        }
        i++;
    }
    ret+=2*st.size();
    return ret;
}
int main() {
    string s = "))())(";
    int ret = minInsertions(s);
    return 0;
}