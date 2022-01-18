#include "bits/stdc++.h"

using namespace std;
int repeatedStringMatch(string a, string b) {
    int len_a = a.size();
    int len_b = b.size();
    int min_time = ceil(len_b*1.0/len_a);
    string s ="";
    for(int i=0;i<min_time;i++){
        s+=a;
    }
    for(int i=min_time;i<min_time+2;i++){
        if(s.find(b)!=s.npos){
            return i;
        }
        s+=a;
    }
    return -1;
}
int main() {
    string  a("abc");
    string b("cabcabca");
    auto ret = repeatedStringMatch(a,b);
    return 0;
}