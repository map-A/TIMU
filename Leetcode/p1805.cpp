#include "bits/stdc++.h"

using namespace std;

string filter(string tmp){
    string ret  = "";
    if(tmp.size()==1&&tmp=="0") return tmp;
    int i = 0;
    for (; i < tmp.size(); ++i) {
        if (tmp[i] != '0') {
            break;
        }
    }
    ret = tmp.substr(i);
    return ret;

}

int numDifferentIntegers(string word) {
    set<string>ret;
    string tmp("");
    int start=-1,end=-1;
    for (int i = 0; i < word.size(); ++i) {
        if(isdigit(word[i])){
            if(start==-1){
                start=i;
            }
        }
        else{
            if(start!=-1){
                ret.insert(filter(word.substr(start,i-start)));
                start = -1;
            }

        }
    }
    if(start!=-1){
        ret.insert(filter(word.substr(start,word.size()-start)));
    }
    return ret.size();

}
int main() {
    string s = "a123bc34d8ef34";
    int ret = numDifferentIntegers(s);
    return 0;
}