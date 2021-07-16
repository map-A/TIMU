#include "bits/stdc++.h"

using namespace std;
char firstUniqChar(string s) {
    // wrong answer
    queue<int>q;
    for(int i=0;i<s.size();i++){
        if(q.empty()){
            q.push(i);
        }
        if(s[q.front()]==s[i]){
            q.pop();
        }
        q.push(i);
    }
    return q.front();
}
int main() {
    string s = "google";
    int ret = firstUniqChar(s);
    return 0;
}